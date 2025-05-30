# Approach: Direct construction

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

// (1) the function takes a std::string_view
std::string reverse_string(std::string_view original)
{
    // (2) construct the reversed string directly
    // by combining a constructor with reverse iterators
    return std::string(rbegin(original), rend(original));
}

} // namespace reverse_string;
```

## The type of the parameter

The function takes a `std::string_view` as its argument.
That type was added to C++17, it is an immutable "view" of a string, it is cheap to construct and to copy (see [cppreference.com][cppref-stringview].)
We can use it here because the function does not modify the parameter.

## Reverse Iterators

In C++ "normal" iterators are an abstraction of pointers.
We can dereference them (if they refer to a valid object), we can compare them, we can increment them so that they refer to the next object, etc. just like with regular pointers.
"Reverse iterators" are similar, we can dereference them (if they refer to a valid object), we can compare them, etc. but the direction is reversed:
When we increment them they refer to the *previous* object.

For example:
```cpp
std::string str = "abcdefghijklmnopqrstuvwxyz";
auto rit = rbegin(str);  // this is a reverse iterator that refers to the last character
std::cout << *rit << '\n';  // prints z
++rit;
std::cout << *rit << '\n';  // prints y
```

## Constructor of `std::string`

`std::string` has surprisingly many constructors (see [cppreference.com][cppref-string-ctor].)
One of them takes two iterators (begin and end of a range) and constructs a `std::string` with the characters in that range.

Combining this constructor with the reverse iterators `rbegin(original)` and `rend(original)` creates the reversed string directly.

We could even omit the type `std::string` from the `return` statement and write
```cpp
return {rbegin(original), rend(original)};
```
That works because the compiler knows the return type of the function and uses the "braced init-list" to construct the `std::string`.

## Conclusion

This is a great approach, it is concise and easy to read (once you know about the constructor and reverse iterators), it is idiomatic and very efficient.

[cppref-stringview]: https://en.cppreference.com/w/cpp/string/basic_string_view
[cppref-string-ctor]: https://en.cppreference.com/w/cpp/string/basic_string/basic_string
