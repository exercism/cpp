# `algorithm.all_of()`

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

This approach starts by defining a [`const`][const] `string` to hold all of the lowercased letters of the English alphabet, within an unnamed namespace.
The `static` keyword used to be used for this, but it was deprecated for this purpose in former versions (and then was later undeprecated.)
Many coders still prefer using the unnamed namespace.

This `is_pangram()` function starts by defining a string to hold the lowercased letters.
The [`transform()`][transform] and [`tolower()`][tolower] functions are used to place the lowercased letters from the input phrase [`string_view`][stringview] into that `string`.
If the currently installed locale is not suitable for lowercasing English characters, then [`std::locale::classic()`][locale-classic] can be passed to the [`tolower()`][tolower-locale] function defined in [&lt;locale&gt;][locale], like so:

```cpp
#include <algorithm>
#include <string>
#include <locale>

// code snipped

std::transform(phrase.begin(), phrase.end(), lphrase.begin(), [](char c){ return std::tolower(c, std::locale::classic()); });
```

The [`all_of()`][all_of] function is used test if all of the letters in the English alphabet `string` are present in the lowercased letters `string`.
The [lambda][lambda] takes each character from the English alphabet `string` as an argument and passes it to the [`find()`][find] member function of the lowercased letters `string`.
If `find()` does not return [`npos`][npos], then the character was found, and the lambda will return `true`, otherwise it will return `false`.

If all of the calls to `find()` return `true`, then `all_of()` will return `true`.
If any call to `find()` returns `false`, then `all_of()` will return `false`.

FInally, the `is_pangram()` function returns the result of calling `all_of()`.

[const]: https://en.cppreference.com/w/cpp/language/cv
[transform]: https://en.cppreference.com/w/cpp/algorithm/transform
[stringview]: https://en.cppreference.com/w/cpp/header/string_view
[locale]: https://en.cppreference.com/w/cpp/header/locale
[locale-classic]: https://en.cppreference.com/w/cpp/locale/locale/classic
[tolower]: https://en.cppreference.com/w/cpp/string/byte/tolower
[tolower-locale]: https://en.cppreference.com/w/cpp/locale/tolower
[all_of]: https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
[lambda]: https://en.cppreference.com/w/cpp/language/lambda
[find]: https://en.cppreference.com/w/cpp/string/basic_string/find
[npos]: https://en.cppreference.com/w/cpp/string/basic_string/npos
