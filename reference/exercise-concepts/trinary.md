# Trinary

## Task

Convert a trinary number, represented as a string (e.g. '102012'), to its decimal equivalent using first principles.

The program should consider strings specifying an invalid trinary as the value 0.

Trinary numbers contain three symbols: 0, 1, and 2.

The last place in a trinary number is the 1's place. The second to last is the 3's place, the third to last is the 9's place, etc.

```cpp
# "102012"
    1       0       2       0       1       2    # the number
1*3^5 + 0*3^4 + 2*3^3 + 0*3^2 + 1*3^1 + 2*3^0    # the value
  243 +     0 +    54 +     0 +     3 +     2 =  302
```

## Example

`trinary.h`

```cpp
#pragma once
#include <string>

namespace trinary
{
unsigned int to_decimal(const std::string &s) noexcept;
} // namespace trinary
```

`trinary.cpp`

```cpp
#include "trinary.h"

namespace trinary
{
unsigned int to_decimal(const std::string &s) noexcept
{
    unsigned int result = 0;
    for (const auto &c : s)
    {
        result *= 3;
        switch (c)
        {
        case '0':
            break;
        case '1':
            result += 1;
            break;
        case '2':
            result += 2;
            break;
        default:
            return 0;
        }
    }
    return n;
}
} // namespace trinary
```

## Concepts

- .h file: the tests include `"trinary.h"`
- .cpp file: the most common approach is to use a `.cpp` for declaring member functions
- include guard: protect against multiple inclusion within a single translation unit
- namespaces: the class/struct is member of a namespace
- const-qualification: member functions must be qualified as `const`
- return values: the result is returned by the function
- `noexcept` function specifier: none of the functions in this exercise are throwing
- loops: use a `for` or `for each` to iterate the string characters
- strings: arguments are strings (or maybe string views)
- operator precedence: misunderstanding precedence can lead to an invalid solution
- pass by reference to const: large strings may be expensive to copy
- conditionals: use `if/else` or `switch` to execute different code branches
- variables: use a specific name to store the result being calculated
- assignment: sets an initial value to the calculated result
- type inference: use of `auto` to avoid declaring a variable type explicitly
- signedness: specify if the result has a sign or not
- arithmetic: use `*=` and `+=` to update the result
- constants: use of `const` to avoid variables modifications

## Alternative approaches

- Declaring the function in the header file
- Using an `if/else` instead of a `switch`
- Convert each `char` to a number
- Use `std::pow` to convert a digit and update the result
- Use a template function for a generic return value
- Create a function to convert from any base

## Common mistakes

- Forgetting to submit the `.h` file
- Forgetting to enable and/or run all the tests
- No include guards
- Bad variable and constants names
- Writing to `std::cout` or `std::cerr`
- Not declaring argument as `const`
- Not passing argument by reference

## Common suggestions to improve a solution

- Use `constexpr` whenever the result of computation does not depend on run-time data
- Add `noexcept` to mark all functions that are not expected to throw exceptions
