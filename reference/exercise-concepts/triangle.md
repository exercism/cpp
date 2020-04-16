# Triangle

## Task

Determine if a triangle is equilateral, isosceles, or scalene.

An _equilateral_ triangle has all three sides the same length.

An _isosceles_ triangle has at least two sides the same length. (It is sometimes
specified as having exactly two sides the same length, but for the purposes of
this exercise we'll say at least two.)

A _scalene_ triangle has all sides of different lengths.

## Example

`triangle.h`

```cpp
#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle
{

enum class flavor
{
    equilateral,
    isosceles,
    scalene
};

flavor kind(double a, double b, double c);

}

#endif
```

`triangle.cpp`

```cpp
#include "triangle.h"
#include <stdexcept>

namespace triangle
{

namespace
{

bool triangle_equality(double a, double b, double c)
{
    return a < (b + c)
        && b < (a + c)
        && c < (a + b);
}

}

flavor kind(double a, double b, double c)
{
    if (a == 0 || b == 0 || c == 0) {
        throw std::domain_error("Zero triangle");
    }
    if (a < 0 || b < 0 || c < 0 || !triangle_equality(a, b, c)) {
        throw std::domain_error("Invalid triangle");
    }
    if (a == b && b == c) {
        return flavor::equilateral;
    }
    if (a == b || b == c || a == c) {
        return flavor::isosceles;
    }
    return flavor::scalene;
}

}
```

## Concepts

- .h file: the tests include `"triangle.h"`
- .cpp file: the most common approach is to use a `.cpp` for declaring member functions
- including directives: `<stdexcept>` is needed for `std::domain_error`
- include guard: protect against multiple inclusion within a single translation unit
- namespaces: grouping of functions and an enumeration
- return values: the result is returned by the function
- exceptions: throw an exception when input is not a valid triangle
- scoped enumerations: define types of triangles
- logical operators: `||` and `&&`
- short-circuit evaluation: understanding sce can lead to a more efficient solution
- floating point types: all constants are stored as `double`
- equality of floating point types: the specifics of what happens with `==` for floating point types
- conditional statements: `if`, `switch-case`
- functions: create function with compatible signature
- function templates: create template that does not depend on the numeric type
- partial template specializations: different equality checks for integer and floating point types

## Alternative approaches

- Function template with specializations for integer and floating point types
- In-lining the function into the header file

## Common mistakes

- Comparing floating point types with `==` where epsilon is more desirable
- Using `std::list` or `std::vector` for storing input
- Using `float`
- Empty error messages
- Temporary variables to store results of comparisons or flavor

## Common suggestions to improve solution

- Sorting input to eliminate excessive comparison
- Using `std::array` for storing input
- Adding `constexpr` for part of the solution that does not validate the input
- Adding `noexcept` function specifier for functions that should not throw
- Adding `const` for input arguments
- Adding `[[nodiscard]]`
- Using `auto` for return type deduction
- Generic implementation using function template
