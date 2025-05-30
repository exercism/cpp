# Introduction

There are several idiomatic approaches to solve Leap.
You can use a chain of boolean expressions to test the conditions.
Or you can use a [ternary operator][ternary-operator].
You might also see functions from the `std::chrono` or `boost::gregorian` libraries.

## General guidance

The key to solving Leap is to know if the year is evenly divisible by `4`, `100` and `400`.
For determining that you will use the [remainder operator][remainder-operator].

## Approach: Chain of Boolean expressions

```cpp
bool is_leap_year(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}
```

For more information, check the [Boolean chain approach][approach-boolean-chain].

## Approach: Ternary operator of Boolean expressions

```cpp
bool is_leap_year(int year) {
    return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
}
```

For more information, check the [Ternary operator approach][approach-ternary-operator].

## Other approaches

Besides the aforementioned idiomatic approaches, you could also approach the exercise as follows:

## Approach: `std::chrono`

```cpp
#include <chrono>

bool is_leap_year(int year) {
    return std::chrono::year{year}.is_leap();
}
```

These `chrono` library features need a C++20 compatible compiler.

## Approach: `boost::gregorian`

```cpp
#include "boost/date_time/gregorian/gregorian_types.hpp"

bool is_leap_year(int year) {
    return boost::gregorian::gregorian_calendar::is_leap_year(year);
}
```

If you cannot use C++20 features, you might consider falling back on the [boost libraries][boost-library].

## Which approach to use?

- The chain of boolean expressions is most efficient, as it proceeds from the most likely to least likely conditions.
  It has a maximum of three checks.
- The ternary operator has a maximum of only two checks, but it starts from a less likely condition.
- Using `std::chrono` or `boost::gregorian` may be considered a "cheat" for the exercise.

[remainder-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[ternary-operator]: https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
[approach-boolean-chain]: https://exercism.org/tracks/cpp/exercises/leap/approaches/boolean-chain
[approach-ternary-operator]: https://exercism.org/tracks/cpp/exercises/leap/approaches/ternary-operator
[boost-library]: https://www.boost.org/doc/libs/1_31_0/libs/date_time/doc/class_gregorian_calendar.html#functions
