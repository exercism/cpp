# Grains

## Task

Calculate the number of grains of wheat on a chessboard given that the number on each square doubles.

There once was a wise servant who saved the life of a prince. The king promised to pay whatever the servant could dream up. Knowing that the king loved chess, the servant told the king he would like to have grains of wheat. One grain on the first square of a chess board, with the number of grains doubling on each successive square.

There are 64 squares on a chessboard (where square 1 has one grain, square 2 has two grains, and so on).

Write code that shows:

- how many grains were on a given square, and
- the total number of grains on the chessboard

## Example

`grains.h`

```cpp
#ifndef GRAINS_H
#define GRAINS_H

#include <cstdint>

namespace grains {

std::uint64_t square(std::uint8_t no);
std::uint64_t total();

}

#endif
```

`grains.cpp`

```cpp
#include "grains.h"

std::uint64_t grains::square(std::uint8_t no) {
  return 1ULL << (no - 1);
}

std::uint64_t grains::total() {
  return -1;
}
```

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- namespaces: the function is member of a namespace
- functions: used as the main entry point for the exercise
- function arguments: number of square is passed by argument
- bitwise operators: binary left (`<<`) and right (`>>`) shift
- unsigned integer types: `std::uint64_t` with width of exactly 64 bits
- return values: the result is returned by the function

## Alternative approaches

- implement solution as `inline` functions in the `.h` file
- implement solution as `constexpr` functions in the `.h` file to get compile time results
- using `std::pow()` function from `<cmath>`
- using `std::numeric_limits` to query largest possible value for `std::uint64_t`
- compute total number of grains on chessboard using `for` loop.
- using `std::bitset`

## Common mistakes

- forgetting to place include guards in `.h` file
- forgetting to delete commented code
- forgetting to delete unused include directives
- placing non-inline function definitions to `.h` file
- using C-style defined constants from `<climits>`
- using C-style typedefs from `<cstdint>`
- using `magic` numbers

## Common suggestions to improve a solution

- mark all functions `noexcept` if they are not expected to throw exceptions
