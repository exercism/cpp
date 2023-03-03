# `algorithm.all_of()`

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
        std::transform(phrase.begin(), phrase.end(), lphrase.begin(), tolower);
        return std::all_of(abc.cbegin(), abc.cend(), [lphrase](char c){return lphrase.find(c) != std::string::npos;});
  }
}  // namespace pangram
```

