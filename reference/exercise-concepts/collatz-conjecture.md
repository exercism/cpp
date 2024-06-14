# Collatz Conjecture

## Task

The Collatz Conjecture or 3x+1 problem can be summarized as follows:

Take any positive integer n. If n is even, divide n by 2 to get n / 2. If n is odd, multiply n by 3 and add 1 to get 3n + 1. Repeat the process indefinitely. The conjecture states that no matter which number you start with, you will always reach 1 eventually.

Given a number n, return the number of steps required to reach 1.

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- namespaces: the function is member of a namespace
- functions: used as the main entry point for the exercise
- including directives: `<stdexcept>` is needed for `std::domain_error`
- function arguments: starting number
- return values: the result is returned by the function
- conditionals using if: conditionally execute logic using an `if` statement
- comparison operators: `!=` and `<=`
- exceptions: throw an exception if the starting number is smaller than 1
- signed integers: the core guidelines recommend signed integers for arithmetic
- increment: `++`
- math operators: the modulo operator `%` is used
- loops: use `while` to check if function has reached its end

## Alternative approaches

- implement solution as `inline` functions in the `.h` file
- using a recursive solution and call `steps` every time the end-condition has not been met