# Approach: Over-engineered

**reverse_string.h**
```cpp
#pragma once

#include <string>

namespace reverse_string
{
    // (1) mark the functions as nodiscard
    // (2) declare three separate functions for different types of arguments
    [[nodiscard]] std::string reverse_string(std::string&& str) noexcept;
    [[nodiscard]] std::string reverse_string(std::string_view str);
    [[nodiscard]] std::string reverse_string(const char* str);
}
```

**reverse_string.cpp**
```cpp
#include "reverse_string.h"

#include <algorithm>

namespace reverse_string
{

// (3) if the argument is a std::string rvalue we can modify it directly
// (4) this function does not throw any exception
std::string reverse_string(std::string&& str) noexcept
{
    // (5) use the standard library to reverse the parameter
    std::reverse(begin(str), end(str));
    return str;
}

// (6) if the argument cannot be modified we create a new reversed string
std::string reverse_string(std::string_view original)
{
    // (7) combine reverse iterators with the constructor of std::string
    // to create a reversed version directly.
    return {rbegin(original), rend(original)};
}

// (8) if the argument is a char pointer we need to disambiguate manually
std::string reverse_string(const char *str)
{
    return reverse_string(std::string_view{str});
}

} // namespace reverse_string;
```

## The `[[nodiscard]]` attribute

The identifier between the double brackets (`[[....]]`) is an *attribute*, it is used to annotate the code (see [cppreference.com][cppref-attributes].)

`nodiscard` (added to C++17) tells the reader and the compiler that the result of the function must not be ignored.
That is helpful in situations where either the result contains some error code that must be checked, or (like in this case) if ignoring/discarding the result of the function does not make sense and is most likely an error in the logic of the caller.

## Overloading functions

In C++ it is possible (and quite common) to define multiple different functions with the same name but different parameter (different number of parameter or different parameter types.)
When an overloaded function is called the compiler collects all candidate with that name, trims the set of candidate to the *viable* ones, and then selects the best fit for the function call (see [cppreference.com][cppref-overload-resolution]).  

Overloading function is often done if these functions perform the same task *conceptually* but in a slightly different way, depending on the arguments.

## Handling a `std::string` rvalue

Rvalues and move semantics were one of the major changes in C++11 and are one of the core concepts of "modern C++".
They allow a program to handle objects that cannot be copied (like some smart pointers) or to handle objects efficiently that are expensive to copy.

A `std::string` uses dynamically allocated memory for its characters, creating a copy involves a memory allocation and copying all the characters.
That can be comparatively expensive.

By writing a function that takes an rvalue reference (`std::string &&`) we can handle a certain case efficiently, where the caller passes a temporary `std::string` object to the function or explicitly *moves* the argument.
In that case the program does not have to allocate memory for the reversed version of the string but can "steal" the memory from the argument.

## The `noexcept` specifier

The first overload (that takes an rvalue reference) does not allocate any memory dynamically, we know for sure that no exceptions can occur.
With `noexcept` that can be formally specified (see [cppreference.com][cppref-noexcept].)
That can allows the compiler to generate better instructions when the function is called.

## Calling `std::reverse`

`std::reverse()` is a function template (in other languages known as "generics") that takes two "bidirectional iterators".
These two iterators define a half-open interval `[begin, end)`.
`std::reverse()` reverses the order of the elements in the interval by swapping.

Calling `std::reverse()` instead of performing the reversal "manually" leads to short and expressive code that is easy to read and efficient.

## Handling a `std::string_view`

`std::string_view` was added to C++17, it is an immutable view of a string, and it can be created from any contiguous sequence of characters such as a `std::string`, a `char *`, a `std::vector<char>`, etc.
It is cheap to construct and to copy, it does not involve any dynamic memory allocation or copying of characters.
Using the type `std::string_view` for strings is a great option whenever some part of the code does not have to "*own*" the string.

We can use it here because the function does not modify the parameter.
That allows the caller to pass a `std::string` or a `std::string_view` or a `char *` to the function without creating a new `std::string` instance.

## Constructing the reversed string directly

`std::string` has surprisingly many constructors.
One of them takes two iterators (begin and end of a range) and constructs a `std::string` with the characters in that range.

Combining this constructor with the reverse iterators `rbegin(original)` and `rend(original)` creates the reversed string directly.
That leads to short and expressive code that is easy to read (once you know reverse iterators) and very efficient.

The `return` statement in that second overload returns a "braced init-list".
The compiler knows the return type from the signature of the function and uses that braced init-list to construct the result.
That is equivalent to `return std::string(rbegin(original), rend(original));` but a little bit shorter and it avoids repeating the return type.

## Handling `const char *` explicitly

Without the third overload (that takes a `const char *`) this would not be a valid solution of the exercise.
The tests call the function with a *string literal* (e.g. `reverse_string::reverse_string("robot")`).
All three overloads of `reverse_string` are *viable*:

- The compiler can implicitly construct a temporary `std::string` from the string literal and pass it to the first overload as an rvalue reference.
- The compiler can implicitly construct a `std::string_view` from the string literal and pass it to the second overload.
- The compiler can pass the string literal directly to the third overload.

Without the third overload the first two functions would be equally good options (as determined by the overload resolution) and the compiler would report an error:
```
error: call of overloaded 'reverse_string(const char [6])' is ambiguous
note: candidate: 'std::string reverse_string::reverse_string(std::string&&)'
note: candidate: 'std::string reverse_string::reverse_string(std::string_view)'
```

By adding the third overload we resolve the ambiguity because this third one is the *best viable function*.

## Going beyond

Of course over-engineering knows no limit, it is possible to use more advanced features of C++.
For example we could implement the three `reverse_string` functions as function templates where the char type and allocator are template parameters.

## Conclusion

This is a valid approach, it is idiomatic and very efficient.
But the more code we write and the more complex/complicated the code becomes, the harder it is to understand and to maintain.
Therefore this "over-engineered approach" is not meant as the *best* approach, but rather as a showcase for some of the more advanced features and as some sort of technical joke.

[cppref-attributes]: https://en.cppreference.com/w/cpp/language/attributes
[cppref-overload-resolution]: https://en.cppreference.com/w/cpp/language/overload_resolution
[cppref-noexcept]: https://en.cppreference.com/w/cpp/language/noexcept_spec

