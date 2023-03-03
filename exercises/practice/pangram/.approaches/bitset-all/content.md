# `bitset.all()`


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
#include "pangram.h"
#include <bitset>
#include <cctype>

namespace pangram {

    bool is_pangram(std::string_view phrase) {
        std::bitset<26> letters;
        for(const auto letter : phrase)
            if(isalpha(letter))
                letters.set(tolower(letter) - 'a');
        return letters.all();
    }
}  // namespace pangram
```

