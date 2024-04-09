# Introduction

Literals are fixed values that are used directly in code.
They do not need any computation during run-time.
They come in various forms to represent different types of data efficiently.
The most frequent literals are of numeric nature, but there are also literal operators for date, time and string types.
A later concept will show how user-defined literal operators can be used.

## Numeric Literals

Numeric literals include decimal, octal, hexadecimal, and binary representations.
These basics were already covered in the [numbers concept][numbers-concept].

All representations like `23`, `0x50f7ba11` and `0xba5eba11` are understood as `int` by the compiler.
The general `int` type is signed and ([depending on the compiler and the system][in-depth-integers]), often has a range of `-2'147'483'648` to `2'147'483'647`.
This is sufficient most of the time and you don't need to worry about the specific type.

Some use-cases demand larger ranges or very small memory footprints of programs.
To be explicit one can directly state specific integer types with the numeric literal.

When negative numbers aren't needed, but the added range is desired the `u` or `U` suffix are used for _unsigned_ integers.
For greater ranges `L` or even `LL` can be used for long and long long types.

~~~~exercism/caution
The use of lower-case `l` is permitted, but it is easily confused with the number `1` and thus discouraged.
~~~~

```cpp
auto net_worth_christian_grey{2'500'000'000U}; // out of range for 32-bit integers
auto net_worth_carlisle_cullen{46'000'000'000LL}; // int and uint are not enough
```

Floating-point numbers usually resolve to `double` during compilation.
This is a good default case and use-cases with the narrower `float` type are less frequent than the unsigned example above.

```cpp
auto light_year_in_m{9.46073e+15f}; // well in the range of float
auto earth_to_edge_comoving_distance_in_nm{4.32355e+32}; // needs double type for magnitude
auto eulers_number{2.718281828459045}; // needs double type for precision
```

~~~~exercism/advanced
## Character and String Literals

Other concepts already used character literals with single quotes like `'}'` or `'@'`.

In C++ `char` is limited to the first 128 [ascii character codes][ascii-code].
To use several ascii chars or extended ascii characters like `‰` or even unicode characters like `麗` and `ẞ` other types are needed.
In previous concept string literals were introduced with _double quotes_: `"一体どういう意味ですか。C++です"`.
The actual type of this Japanese phrase is `const char (&)[46]`, a C-style string.

The use of string literals is not activated by default.
To use the _string_ literal `""s` or the _string-view_ literal `""sv`, the user has to specify their use by using the related namespace:

```cpp
#include <string>
#include <string_view>

using namespace std::literals;

auto green_light{"무궁화 꽃 이 피었 습니다"};
// green_light type is const char (&)[36]
auto umbrella{"달고나"s};
// umbrella type is std::basic_string<char>, the same as std::string
auto il_nam{"보는 것이 하는 것보다 더 재미있을 수가 없지"sv};
// il_nam type is std::basic_string_view<char>
```

A _string_view_ can be seen as a reference to a const string.

[ascii-code]: https://www.ascii-code.com/

~~~~

[numbers-concept]: https://exercism.org/tracks/cpp/concepts/numbers
[in-depth-integers]: https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
