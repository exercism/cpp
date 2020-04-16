# Leap

## Task

Given a year, report if it is a leap year.

## Example

`leap.h`

```cpp
#ifndef LEAP_H
#define LEAP_H

namespace leap
{
    bool is_leap_year(int year);
}

#endif
```

`leap.cpp`

```cpp
#include "leap.h"

bool leap::is_leap_year(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
```

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- namespaces: the function is member of a namespace
- functions: used as the main entry point for the exercise
- function arguments: year is passed as argument
- integers: an `int` is used for the year
- signed integers: the core guidelines recommend signed integers for arithmetic
- math operators: the modulo operator `%` is used
- equality operators: `==` and `!=`
- logical operators: `||` and `&&`
- operator precedence: (not strictly required) misunderstanding precedence can lead to an invalid solution
- short-circuit evaluation: (not strictly required) understanding sce can lead to a more efficient solution
- return values: the result is returned by the function
- booleans: the result is a `bool`

## Alternative approaches

- Many students use two or three `if` statements instead of logical operators.
- A few Students use the conditional operator instead of logical operators.
- Some students `if` statements with a local `result` variable and a single `return` statement.
- Some students use three local variables that tell if `year` is divisible by `4`, `100`, and `400`.
- Some implement their solution as an `inline` function in the `.h` file.

## Common mistakes

- submitting the `.cpp` file without the `.h` file.
- forgetting to enable and/or run all the tests
- no include guards
- defining the function in the header without declaring it as `inline`
- `if (condition) return true; else return false;` instead of `return condition;`
- `condition? true: false` instead of `condition`
- `!(year % 4 == 0)` instead of `year % 4 != 0
- `year % 4 == 0 && year % 100 == 0 && year % 400 == 0` instead of `year % 400 == 0`
- complicated nested `if` statements

## Common suggestions to improve a solution

- use a signed integer unless you need a bit pattern
- give the argument a name in the declaration to help human readers
- minimize the average number of divisions by rearranging the terms in the `return` statement
