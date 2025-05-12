# Two Fer

## Task

`Two-fer` or `2-fer` is short for two for one. One for you and one for me.

Given a name, return a string with the message:

    One for X, one for me.

Where X is the given name.

However, if the name is missing, return the string:

    One for you, one for me.

## Example

`two_fer.h`

```cpp
#pragma once

#include <string>

namespace two_fer
{
    std::string two_fer(const std::string& name = "you") noexcept;
}
```

`two_fer.cpp`

```cpp
#include "two_fer.h"

std::string two_fer::two_fer(const std::string& name) noexcept
{
    return "One for " + name + ", one for me.";
}
```

## Concepts

- .h file: the tests include `"two_fer.h"`
- .cpp file: the most common approach is to use a `.cpp` for declaring member functions
- include guard: protect against multiple inclusion within a single translation unit
- namespaces: the class/struct is member of a namespace
- const-qualification: member functions must be qualified as `const`
- return values: the result is returned by the function
- `noexcept` function specifier: none of the functions in this exercise are throwing

## Alternative approaches

- Declaring the function in the header file
- Using function overload instead of default arguments
- Using `if` to check if name string is empty

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
