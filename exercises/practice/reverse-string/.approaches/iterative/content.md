# Approach: Iterative

**reverse_string.h**
```cpp
#pragma once

#include <string>

namespace reverse_string
{
    std::string reverse_string(const std::string& str);
}
```

**reverse_string.cpp**
```cpp
#include "reverse_string.h"

namespace reverse_string
{

// (1) the function takes its argument "by reference to const"
std::string reverse_string(const std::string& original)
{
    // (2) start with an empty string
    std::string result;

    // (3) loop over the original string
    for (std::size_t i = 0; i < size(original); ++i)
    {
        std::size_t rindex = size(original) - i - 1;

        // (4) append each character (starting from the end)
        result.append(original[rindex]);
    }

    // result now contains a reversed version of the string
    return result;
}

} // namespace reverse_string;
```

## The type of the parameter

The function takes its argument "by reference to const" (`const std::string&`).
That avoids creating an unnecessary copy which can be comparatively expensive for a `std::string`.
This is a best practice and widely recommended if a copy is expensive and the function does not need a "working copy" that it can modify (see the [C++ Core Guidelines][cgl-by-value-by-const-ref].)

Alternatively you could use a `std::string_view`.
That type was added to C++17, it is an immutable view of a string, it is cheap to construct and to copy (see [cppreference.com][cppref-stringview].)

## Constructing an empty `std::string`

There are several equivalent ways to construct an empty `std::string`, for example:
```cpp
std::string result;
std::string result{};
std::string result{""};
std::string result = "";
auto result = std::string{};
```

None of them is significantly better than the others, choosing one is mostly a matter of personal preferences.

## Looping over the original string from back to front

In the implementation above `i` is a loop variable that goes from `0` to `size(original)` (exclusive).
Inside the loop `i` is used to to calulate `rindex`, an index that goes from `size(original) - 1` to `0` (inclusive).

There are other ways to write that loop, for example like this:
```cpp
for (std::size_t rindex = size(original) - 1; rindex < size(original); --rindex)
```
That uses the fact that `std::size_t` is an unsigned integer type that "wraps around", `std::size_t{0} - 1` is a large positive number.

Or with reverse iterators which many experienced C++ programmers would prefer:
```cpp
for (auto rit = rbegin(original); rit != rend(original); ++rit)
{
    // *rit is the current character
}
```

## Appending to the result

The solution above uses the member function `append` (see [cppreference.com][cppref-string-append].)
There are other equivalent member function like `push_back()` (see [cppreference.com][cppref-string-pushback]) or the operator `+=` (see [cppreference.com][cppref-string-operator-plus-equal].)
Either one is fine, chosing one is a matter of personal preferences.

## Variation: With assignments

Instead of starting with an empty `std::string` and appending each character we could start with a string that has the correct length, and then *assign* each character to its correct position.

```cpp
// start with a string of the correct length
std::string result(size(original), '_');

// loop over the original string
for (std::size_t i = 0; i < size(original); ++i)
{
    std::size_t rindex = size(original) - i - 1;

    // assign each character to its new place
    result[rindex] = original[i];
}
```
The assignment (`result[rindex] = original[i]`) needs two indexes, so we have to write the loop in a way that we get both.
Either by computing the other index like in the snippet (`std::size_t rindex = ...`), or by using *two* loop variables:
```cpp
for (std::size_t i = 0, rindex = size(original) - 1; i < size(original); ++i, --rindex)
```

## Conclusion

This is a valid approach, it produces a correct result and is reasonably efficient.

But most experts recommend not doing things "manually" if there are better alternatives.
You could consider using the `std::string` class to construct the reversed string directly.
That would shorten the code, would be concise, easy to read, idiomatic, and very efficient.
Check out the [Direct Construction][approach-direct-construction] approach.


[cgl-by-value-by-const-ref]: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rf-in
[cppref-stringview]: https://en.cppreference.com/w/cpp/string/basic_string_view
[cppref-string-append]: https://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D
[cppref-string-pushback]: https://en.cppreference.com/w/cpp/string/basic_string/push_back
[cppref-string-operator-plus-equal]: https://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D
[approach-direct-construction]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/direct-construction
