#
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

The `find` function starts by defining the variables that control iterating to the answer.
The `left` is initialized to `0` and the `right` is initialized to the [size][size] of the [`vector`][vector] of `int`s passed in.
The middle value is initialized to `0`.

The [`while` loop][while] iterates while `left` is less than `right`.

Inside the loop, the middle value is set by `left` plus ((`right` - `left`) divided by `2`).
The reason for not doing (`left` + `right`) divided by `2` is to prevent overflow for very large sizes of the input `vector`, as explained [here][mid-bug].
For example, if `left` is `0` and `right` is `10`, then the middle is calculated to `5`.
if `left` is `6` and `right` is `10`, then the middle is calculated to `8`.

An [`if` statement][if] is used to check the value of the element whose index in the `vector` of `int`s is the middle value.
If the element at the index of the middle value matches the value being searched for, then the middle value is returned.

If the first `if` statement does not return, then another `if` statement is used to check the element.

~~~~exercism/note
Note that if an `if` statement can return, it does not need to be followed by an `else if ` or an `else`.
If the statement returns, then control flow will leave the function.
If the statement does not return, control will fall through to the next statement anyway.
~~~~

If the element at the index of the middle value is less than the value being searched for, then `left` is set to the middle value
plus one so that the next iteration will look for higher numbers.

Otherwise, the value being searched for must be less than the element at the index of the middle value, so `right` is set to the middle value
so that the next iteration will look at lower numbers.

If `left` and `right` are changed during the iterations so that `left` is no longer less than `right`,
then the value being searched for is not in the `vector` of `int`s.
The loop exits and a [std::domain_error][domain-error] is returned from the function.

[size]: https://en.cppreference.com/w/cpp/container/vector/size
[vector]: https://en.cppreference.com/w/cpp/container/vector
[while]: https://en.cppreference.com/w/cpp/language/while
[if]: https://en.cppreference.com/w/cpp/language/if
[domain-error]: https://en.cppreference.com/w/cpp/error/domain_error
[mid-bug]: https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
