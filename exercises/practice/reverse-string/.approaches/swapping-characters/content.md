# Approach: Swapping characters

**reverse_string.h**
```cpp
#pragma once

#include <string>

namespace reverse_string
{
    std::string reverse_string(std::string str);
}
```

**reverse_string.cpp**
```cpp
#include "reverse_string.h"

namespace reverse_string
{

// (1) the function takes its argument "by value"
std::string reverse_string(std::string str)
{
    // (2) handle an empty string as a special case
    if (str.empty())
        return str;

    // (3) use two indexes,
    // a starts a the beginning and gets incremented
    // b starts at the end and gets decremented
    std::size_t a = 0;
    std::size_t b = size(str) - 1;

    // (4) swap characters until the two indexes meet
    while (a < b)
    {
        std::swap(str[a], str[b]);
        ++a;
        --b;
    }

    // str is now reversed
    return str;
}

} // namespace reverse_string;
```

## The type of the parameter

The function takes its argument "by value" (`std::string`).
That means the parameter `str` gets constructed from the argument that the caller passes to the function, and it gets destructed at the end of the function.
Any modifications of the parameter will not be visible outside of the function and will not affect the argument of the caller.  
We do that because the function needs a "working copy" of the string, it will reverse and return that parameter without creating an additional instance of `std::string`.

## Handling an empty string as a special case

The rest of the function would have problems with an empty string because in that case `size(empty_string) - 1` is a large positive number, and the first iteration of the loop tries to access `str[b]` which would be out of bounds.
Therefore we handle the empty string as a special case with an "early return".

## Using two indexes

This solution swaps characters, the first character with the last one, the second character with the second to last, etc.
It therefore uses two variables for the indexes: `a` starts at `0` and gets incremented, `b` starts at `size(str) - 1` and gets decremented.

The general category of this algorithm is sometimes called "Two pointers technique" (pointers and indexes are closely related.)

## Swapping characters

The standard library provides a function `std::swap` for swapping two variables (see [cppreference.com][cppref-swap].)
We *could* do that manually with a temporary third variable:
```cpp
char temp = str[a];
str[a] = str[b];
str[b] = temp;
```
But calling `std::swap` is shorter, expresses the intent more clearly, and through the optimizations that all modern compilers perform it is just as efficient.

## Conclusion

This is a valid approach, it produces a correct result and is reasonably efficient.

But most experts recommend not doing things "manually" if there are better alternatives.
You could consider calling a function from the standard library that performs the reversal for you.
That would shorten the code, would be concise, easy to read, idiomatic, and very efficient.
Check out the [Using the standard library][approach-using-the-standard-lib] approach.

[cppref-swap]: https://en.cppreference.com/w/cpp/algorithm/swap
[approach-using-the-standard-lib]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/using-the-standard-lib

