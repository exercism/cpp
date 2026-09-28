# Introduction

There are many ways to solve Binary Search.
One approach can use a `while` loop with `if` statements.

## Approach: `while` loop with `if` statements

**binary_search.h**
```cpp
#pragma once
#include <vector>
#include <cstddef>
namespace binary_search {
    std::size_t find (const std::vector<int>& data, int value);
}  // namespace binary_search
```

**binary_search.cpp**
```cpp
#include "binary_search.h"
#include <stdexcept>

namespace binary_search {
    std::size_t find (const std::vector<int>& data, int value) {
        std::size_t left = 0, right = data.size();
        while (left < right) {
            std::size_t mid = left + ((right - left) / 2);
            int look = data[mid];
            if (look == value) return mid;
            if (look < value) left = mid + 1;
            else right = mid;
        }
        throw std::domain_error("Value not found. No soup for you!");
    }
}  // namespace binary_search
```

For more information, check the [`while` loop with `if` statements approach][approach-while-with-if-statements].

[approach-while-with-if-statements]: https://exercism.org/tracks/cpp/exercises/binary-search/approaches/while-with-if-statements
