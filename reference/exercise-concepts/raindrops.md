# Raindrops

## Task

Your task is to convert a number into a string that contains raindrop sounds corresponding to certain potential factors. A factor is a number that evenly divides into another number, leaving no remainder. The simplest way to test if a one number is a factor of another is to use the [modulo operation](https://en.wikipedia.org/wiki/Modulo_operation).

The rules of `raindrops` are that if a given number:

- has 3 as a factor, add 'Pling' to the result.
- has 5 as a factor, add 'Plang' to the result.
- has 7 as a factor, add 'Plong' to the result.
- _does not_ have any of 3, 5, or 7 as a factor, the result should be the digits of the number.

### Examples

- 28 has 7 as a factor, but not 3 or 5, so the result would be "Plong".
- 30 has both 3 and 5 as factors, but not 7, so the result would be "PlingPlang".
- 34 is not factored by 3, 5, or 7, so the result would be "34".

## Example

`raindrops.h`

```cpp
#if !defined(RAINDROPS_H)
#define RAINDROPS_H

#include <string>

namespace raindrops
{

std::string convert(int drops);

}

#endif
```

`raindrops.cpp`

```cpp
#include "raindrops.h"
#include <sstream>

using namespace std;

namespace raindrops
{

string convert(int drops)
{
    const int pling_factor{3};
    const int plang_factor{5};
    const int plong_factor{7};
    ostringstream result;
    if (drops % pling_factor == 0) {
        result << "Pling";
    }
    if (drops % plang_factor == 0) {
        result << "Plang";
    }
    if (drops % plong_factor == 0) {
        result << "Plong";
    }
    if (!result.tellp()) {
        result << drops;
    }
    return result.str();
}

}
```

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- namespaces: the function is member of a namespace
- functions: used as the main entry point for the exercise
- function arguments: `drops` is passed as argument
- math operators: the modulo operator `%` is used
- equality operators: `==` and `!=`
- strings: append to a string and return it as a result
- `noexcept` function specifier: none of the functions in this exercise are throwing
- variables: use a specific name to store the result string
- const-qualification: inputs do not change and should be `const`
- `constexpr`: use for constant data known at compile time
- return values: the result is returned by the function
- streams in STL: `<<` and `>>` for stream objects
- conditional statements: `if` to check for factors

## Alternative approaches

- Create `std::map` of factor to string literal.
- Using `std::string` as a result, without relying on `std::ostringstream`.
- Get all the prime factors of the input number and add corresponding string literals if any 3, 5 and 7 are among them.

## Common mistakes

- Forgetting to submit the `.h` file
- Forgetting to enable and/or run all the tests
- No include guards
- Bad variable and constants names
- Writing to `std::cout` or `std::cerr`
- Not marking all constants known at compile time as `constexpr`
- Creating a class `raindrops` instead of a namespace of the same name

## Common suggestions to improve a solution

- Adding `const` for input argument
- Use `constexpr` for data known at compile time
- Add `noexcept` to mark all functions that are not expected to throw exceptions
- Using `auto` for return type deduction
