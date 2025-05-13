# Introduction

There are many ways to solve Pangram.
One approach can use a [`bitset`][bitset] and its [`all`][all] member function.
Another approach can use the [`algorithm.all_of()`][all_of] function.

## Approach: `bitset.all()`


**pangram.h**
```cpp
#pragma once
#include <string_view>

namespace pangram {
    bool is_pangram(std::string_view phrase);
}  // namespace pangram
```

**pangram.cpp**

```cpp
#include "pangram.h"
#include <bitset>
#include <cctype>

namespace pangram {

    bool is_pangram(std::string_view phrase) {
        std::bitset<26> letters;
        for (const auto c : phrase)
            if (std::isalpha(c))
                letters.set (std::tolower(c) - 'a');
        return letters.all();
    }
}  // namespace pangram
```

For more information, check the [`bitset.all()` approach][approach-bitset-all].

## Approach: `algorithm.all_of()`

**pangram.h**
```cpp
#if !defined(PANGRAM_H)
#define PANGRAM_H
#include <string_view>

namespace pangram {
    bool is_pangram(std::string_view phrase);
}  // namespace pangram

#endif // PANGRAM_H
```

**pangram.cpp**

```cpp
#include <algorithm>
#include <cctype>
#include <string>

namespace {
    const std::string abc = "abcdefghijklmnopqrstuvwxyz";
}

namespace pangram {
    bool is_pangram(std::string_view phrase){
        std::string lphrase(phrase.length(), ' ');
        std::transform(phrase.begin(), phrase.end(), lphrase.begin(), std::tolower);
        return std::all_of(abc.cbegin(), abc.cend(), [lphrase](char c){ return lphrase.find(c) != std::string::npos; });
  }
}  // namespace pangram
```

For more information, check the [`algorithm-all_of()` approach][approach-algorithm-allof].

## Which approach to use?

Since benchmarking is currrently outside the scope of this document, which to use is pretty much a matter of personal preference,
although `bitset.all()` is more efficient.

[bitset]: https://en.cppreference.com/w/cpp/utility/bitset
[all]: https://en.cppreference.com/w/cpp/utility/bitset/all_any_none
[all_of]: https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
[approach-bitset-all]: https://exercism.org/tracks/cpp/exercises/pangram/approaches/bitset-all
[approach-algorithm-allof]: https://exercism.org/tracks/cpp/exercises/pangram/approaches/algorithm-allof
