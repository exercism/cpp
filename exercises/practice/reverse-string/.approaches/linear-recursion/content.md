# Approach: Linear Recursion

**reverse_string.h**
```cpp
#pragma once

#include <string>

namespace reverse_string
{
    std::string reverse_string(std::string_view str);
}
```

**reverse_string.cpp**
```cpp
#include "reverse_string.h"

namespace reverse_string
{

// (1) the function takes a std::string_view as its input parameter
// (2) the function takes an "output parameter"
void recursive_helper(std::string_view input, std::string& output)
{
    // (3) handle the base case
    if (input.empty())
        return;

    // (4) append the last character of the input to the output
    output.append(input.back());
    // and "remove" the last character from the input
    input.remove_suffix(1);

    // (5) handle the rest of the input recursively
    recursive_helper(input, output);
}

std::string reverse_string(std::string_view original)
{
    std::string result;
    recursive_helper(original, result);
    return result;
}

} // namespace reverse_string;
```

## The types of the parameters

Both functions take a `std::string_view` as their first argument.
That type was added to C++17, it is an immutable "view" of a string, it is cheap to construct and to copy (see [cppreference.com][cppref-stringview].)
We can use it here because the functions do not really modify the parameter, the `recursive_helper` just narrows the view (`input.remove_suffix(1)`).

The helper function has an "output parameter" (see the [Wikipedia][wiki-output-parameter]).
In C++ we use a (non-`const`) reference for that (`std::string&`, note the ampersand!).

## The base case

Whenever we use recursion we need two things:
A "base case" and the recursion itself (see the [Wikipedia][wiki-recursion].)
Here the base case is a string that is empty.
In that case nothing needs to be done.

## Processing the current character

`std::string_view` has the member function `back` that returns the last character (see [cppreference.com][cppref-stringview-back]).

`std::string` has the member function `append` that appends something to the string (see [cppreference.com][cppref-string-append]).
There are equivalent member functions like `push_back` (see [cppreference.com][cppref-string-pushback]) or the operator `+=` (see [cppreference.com][cppref-string-operator-plus-assign]).
In this case they do exactly the same.

`std::string_view` has the member function `remove_suffix` that *conceptually* removes some characteas from the end of the `std::string_view`.
That does not modify the underlying string, it just narrows the view.

These three functions combined allow us to get the last character of the `input`, append it to the `output`, and remove it from the `input`.

## The recursion

After processing the current character the helper function calls itself recursively.
Note that the `input` is now one character shorter, so the recursion is guaranteed to terminate.

## Analysis

The general category of the algorithm is "Linear Recursion":
If our original string has `n` characters the helper function gets called `n + 1` times.
That makes it easy to reason about the function and its linear runtime complexity.

But this linear recursion is dangerous in C++.
If the string is too long we risk a stack overflow (see the [Wikipedia][wiki-stack-overflow]).
Only do that if you know for sure the string will be relatively short, *or* if the compiler can and will perform "Tail Call Optimization" (see the [Wikipedia][wiki-tail-call].)

## Conclusion

This is a valid approach but in practice the recursion is slower than processing the string iteratively.
Therefore it is only presented as an interesting idea and to warn about linear recursion in C++.

[cppref-stringview]: https://en.cppreference.com/w/cpp/string/basic_string_view
[wiki-output-parameter]: https://en.wikipedia.org/wiki/Parameter_(computer_programming)#Output_parameters
[wiki-recursion]: https://en.wikipedia.org/wiki/Recursion_(computer_science)
[cppref-stringview-back]: https://en.cppreference.com/w/cpp/string/basic_string_view/back
[cppref-string-append]: https://en.cppreference.com/w/cpp/string/basic_string/append
[cppref-string-pushback]: https://en.cppreference.com/w/cpp/string/basic_string/push_back
[cppref-string-operator-plus-assign]: https://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D
[cppref-stringview-removesuffix]: https://en.cppreference.com/w/cpp/string/basic_string_view/remove_suffix
[wiki-stack-overflow]: https://en.wikipedia.org/wiki/Stack_overflow
[wiki-tail-call]: https://en.wikipedia.org/wiki/Tail_call

