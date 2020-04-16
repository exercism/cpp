# Hamming

## Task

Calculate the Hamming Distance between two strings.

## Example

`hamming.h`

```cpp
#ifndef HAMMING_H
#define HAMMING_H

#include <cstddef>

namespace hamming
{
    std::size_t compute(const std::string& s1, const std::string& s2);
}

#endif
```

`hamming.cpp`

```cpp
#include "hamming.h"
#include <stdexcept>

std::size_t hamming::compute(const std::string& s1, const std::string& s2)
{
    if (s1.size() != s2.size())
        throw std::domain_error("argument lengths do not match");
    std::size_t result = 0;
    for (std::size_t i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i])
            ++result;
    return result;
}
```

## Concepts

- .h file: the tests include `"hamming.h"`
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- namespaces: the function is member of a namespace
- functions: used as the main entry point for the exercise
- function arguments: the function has two arguments
- strings: both arguments are strings (or maybe string views)
- pass by reference to const: both arguments might be expensive to copy
- return values: the result is returned by the function
- integer: the result is an integer
- integer types: (optional) `int` as return type is fine, `std::size_t` or `std::string::size_type` would be even better
- including directives: `<stdexcept>` is needed for `std::domain_error`
- conditionals using if: conditionally execute logic using an `if` statement
- comparison operators: `!=` and `<`
- exceptions: throw an exception if the arguments have different lengths
- initialization / assignment: the variable holding the result and the loop variable (if applicable) have to be initialized
- increment: `++`

## Alternative approaches

- Some students used `std::string_view` from C++17 instead of `std::string`.
- A few students used C-style strings and call `std::strlen()`.
- Some students used iterators for the loop.
- A few students used `std::inner_product()` with `std::plus<>()` and `std::not_equal_to<>()`.
- Some students increment the result by `s1[i] != s2[i]` instead of using an `if` statement.
- One student used a range library (Boost::range).
- One student initialized the local `result` variable with the length of the arguments and then decremented that for each match.
- One student used `std::mismatch()` in the loop.
- One student used `std::count_if()` with a lambda that increments a index for the other string.

## Common mistakes

- pass by value (by far the most common mistake)
- forgetting to submit the `.h` file
- forgetting to enable and/or run all the tests
- no include guards
- include directives before the include guard (not an error but unconventional)
- using directives or using declarations in the global namespace of the `.h` file
- defining the function in the header without declaring it as `inline`
- empty error messages
- using a non-standard integer type `uint`
- treating `arg1 == arg2` as a special case and thus potentially doubling the number of comparisons
- comparing signed and unsigned types in the loop
- C-style casts
- special case for empty strings (not an error but unnecessary)
- using `::size_t` without including the correct header
- bad variable names
- different types for the local `result` variable and the return type
- "lenght" is a pretty common typo
- writing to `std::cout` or `std::cerr`
- not initializing the `result` variable
- implementing `compute()` as a `static` member function of a class `hamming`
- using a `while` loop and initializing and incrementing the index variable in three different lines instead of using a traditional `for` loop (not an error but un-idiomatic)
