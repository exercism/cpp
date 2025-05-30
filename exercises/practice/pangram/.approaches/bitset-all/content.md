# `bitset.all()`


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

This approach starts be defining a [`bitset`][bitset] to keep track of the used letters.

A [range-based `for` loop][ranged-for] iterates over all of the characters in the input phrase [`string_view`][stringview].
Each character is tested by the [`isalpha()`][isalpha] function to see if it is considered an alphabetic character according to the currently installed C locale.
If the currently installed locale is not suitable for the English alphabet, then [`std::locale::classic()`][locale-classic] can be passed to the [`isalpha()`][isalpha-locale] function defined in [&lt;locale&gt;][locale], like so:

```cpp
#include <bitset>
#include <locale>

// code snipped

if (std::isalpha(c, std::locale::classic()))
```

If the character is alphabetic, then a bit value is set to represent its being used.
The [ASCII][ascii] value of `a` is subtracted from the character [`tolower()`][tolower]ed.
If the currently installed locale is not suitable for lowercasing English characters, then `std::locale::classic()` can be passed to the [`tolower()`][tolower-locale] function defined in `<locale>`, like so:

```cpp
#include <bitset>
#include <locale>

// code snipped

letters.set (std::tolower(c, std::locale::classic()) - 'a');
```

For example, if the character is `A`, then `A` is lowered to `a`, and the ASCII value of `a` is subtracted by the ASCII value `a` to set the bit at position `0` in the `bitset` to `1`.

if the character is `Z`, then `Z` is lowered to `z`, and the ASCII value of `z` is subtracted by the ASCII value `a` to set the bit at position `25` in the `bitset` to `1`.

After all of the characters in the input phrase are iterated, the the [`all()`][all] function is used to return if all of the `26` bits are set.

[bitset]: https://en.cppreference.com/w/cpp/utility/bitset
[ranged-for]: https://en.cppreference.com/w/cpp/language/range-for
[stringview]: https://en.cppreference.com/w/cpp/header/string_view
[isalpha]: https://en.cppreference.com/w/cpp/string/byte/isalpha
[isalpha-locale]: https://en.cppreference.com/w/cpp/locale/isalpha
[locale]: https://en.cppreference.com/w/cpp/header/locale
[locale-classic]: https://en.cppreference.com/w/cpp/locale/locale/classic
[tolower]: https://en.cppreference.com/w/cpp/string/byte/tolower
[tolower-locale]: https://en.cppreference.com/w/cpp/locale/tolower
[ascii]: https://www.asciitable.com/
[all]: https://en.cppreference.com/w/cpp/utility/bitset/all_any_none
