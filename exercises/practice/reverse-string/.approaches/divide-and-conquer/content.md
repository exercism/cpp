# Approach: Divide and conquer

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
    // (2) handle the base case where nothing needs to be done
    if (size(original) <= 1)
        return std::string{original};

    // "divide and conquer" by reversing the two halfs of the string separately
    auto half_size = size(str) / 2;
    return reverse_string(original.substr(half_size) +
           reverse_string(original.substr(0, half_size);
}

} // namespace reverse_string;
```

## The type of the parameter

The function takes a `std::string_view` as its argument.
That type was added to C++17, it is an immutable "view" of a string, it is cheap to construct and to copy (see [cppreference.com][cppref-stringview].)
We can use it here because the function does not modify the parameter.

## Handling the base case

Whenever we use recursion we need two things: A "base case" and the recursion itself (see the [Wikipedia][wiki-recursion].)
Here the base case is a string that is empty or has just a single character.
Such a string is obviously identical to the reversed version of itself.
Therefore if the length is `1` or smaller we can return the parameter unmodified.

In this case the type of the parameter is `std::string_view` so we have to construct the result of the function (a `std::string`) explicitly in the `return` statement.

## The recursion

The idea of this solution is this:
We can create a reversed version of a string if we split the string into two parts, reverse them separately, and concatenate them in the end (in reversed order).

That it works can be proven formally but that is outside of the scope of this explanation.
Instead the following example should demonstrate why and how it works:
```cpp
std::string_view str = "abcdefghijklmnopqrstuvwxyz";
auto half_size = size(str) / 2;  // half_size is 13
auto reversed_left_half  = reverse_string(str.substr(0, half_size);
    // reversed_left_half is now "mlkjihgfedcba"
auto reversed_right_half  = reverse_string(str.substr(half_size);
    // reversed_right_half is now "zyxwvutsrqpon"
auto result = reversed_right_half + reversed_left_half;
    // result is now "zyxwvutsrqponmlkjihgfedcba"
```

## Analysis

The general category of the algorithm is "Divide and Conquer":
We divide the problem into smaller problems, then we "conquer" (solve) them independently and recursively (see the [Wikipedia][wiki-divide-and-conquer].)

Calculating the `half_size` and splitting the string into two parts takes constant time (due to the `std::string_view`).
Each recursive function call handles one half of the string.
Combining the two reversed half at the end takes linear time.
Therefore the runtime complexity of this implementation is O(n log n), it is "linearithmic" (see the [Wikipedia][wiki-quasilinear-time]).

Note that in contrast to the [Linear Recursion][approach-linear-recursion] this approach is safe.
The depth of the recursion is limited by the logarithmic nature of Divide and Conquer.

## Conclusion

This is a valid approach but it has a worse runtime complexity than others.
Therefore it is mostly presented as an interesting idea.

[cppref-stringview]: https://en.cppreference.com/w/cpp/string/basic_string_view
[wiki-recursion]: https://en.wikipedia.org/wiki/Recursion_(computer_science)
[wiki-divide-and-conquer]: https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm
[wiki-quasilinear-time]: https://en.wikipedia.org/wiki/Time_complexity#Quasilinear_time
[approach-linear-recursion]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/linear-recursion
