# Sum of multiples

## Task

Given a number, find the sum of all the unique multiples of particular numbers up to
but not including that number.

If we list all the natural numbers below 20 that are multiples of 3 or 5,
we get 3, 5, 6, 9, 10, 12, 15, and 18.

The sum of these multiples is 78.

## Example

`sum_of_multiples.h`

```cpp
#if !defined(SUM_OF_MULTIPLES_H)
#define SUM_OF_MULTIPLES_H

#include <initializer_list>

namespace sum_of_multiples
{

int to(std::initializer_list<int> const& multiples, int num);

}

#endif
```

`sum_of_multiples.cpp`

```cpp
#include "sum_of_multiples.h"

namespace sum_of_multiples
{

int to(std::initializer_list<int> const& multiples, int num)
{
    int sum = 0;
    for (int i = 0; i < num; ++i) {
        for (const int multiple : multiples) {
            if (i % multiple == 0) {
                sum += i;
                break;
            }
        }
    }
    return sum;
}

}
```

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- initializer list: accept the input without creating any containers
- namespaces: the function is member of a namespace
- functions: used as the main entry point for the exercise
- function arguments: passing multiples as `const` reference, to avoid making copies
- integers: an `int` for an accumulator
- signed integers: the core guidelines recommend signed integers for arithmetic
- math operators: the modulo operator `%` is used
- const-qualification: inputs do not change
- range for-loop or for-loop: to get though multiples
- `break`: interrupt loop
- `noexcept` function specifier: solution should not throw
- `constexpr`: solution does not depend on any run-time data

## Alternative approaches

- using `std::unordered_set` to keep unique factors
- using `std::find_if` or `std::any_of` to search for multiples dividable by a number
- using `std::unordered_map` to keep track of factors
- using `boost::range`'s adapters to express search for factors

## Common mistakes

- submitting the `.cpp` file without the `.h` file.
- forgetting to enable and/or run all the tests
- no include guards
- making copy of the input instead of passing as `const` reference
- using `std::set`
- using iterators explicitly
- creating references to simple numeric data types

## Common suggestions to improve solution

- sorting input and making sure that all the numbers in it are unique
- use `const` for individual multiples
- use `constexpr` for data known at compile time
- add `noexcept` to mark all functions that are not expected to throw exceptions
- using `boost::flat_set`
- using `boost::range`'s adapters to express search for factors
- using function templates for generic solution
