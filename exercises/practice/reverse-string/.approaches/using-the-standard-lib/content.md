# Approach: Using the standard library

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

#include <algorithm>  // (1) for std::reverse()

namespace reverse_string
{

// (2) the function takes its argument "by value"
std::string reverse_string(std::string str)
{
    // (3) call a function from the standard library that performs the reversal
    std::reverse(begin(str), end(str));

    // str is now reversed
    return str;
}

} // namespace reverse_string;
```

## Including the header

The header `<algorithm>` is part of the standard library, it contains lots of useful functions (see [cppreference.com][cppref-algorithm]).
After including this header we can call the function `std::reverse` later in the file.

## The type of the parameter

The function takes its argument "by value" (`std::string`).
That means the parameter `str` gets constructed from the argument that the caller passes to the function, and it gets destructed at the end of the function.
Any modifications of the parameter will not be visible outside of the function and will not affect the argument of the caller.  
We do that because the function needs a "working copy" of the string, it will reverse and return that parameter without creating an additional instance of `std::string`.

## Calling `std::reverse()`.

`std::reverse()` is a function template (in other languages known as "generics") that takes two "bidirectional iterators".
These two iterators define a half-open interval `[begin, end)`.
`std::reverse()` reverses the order of the elements in the interval by swapping (see [cppreference.com][cppref-reverse].)

## Conclusion

This is a great approach; it is concise, easy to read, idiomatic, and very efficient.


[cppref-algorithm]: https://en.cppreference.com/w/cpp/header/algorithm
[cppref-reverse]: https://en.cppreference.com/w/cpp/algorithm/reverse

