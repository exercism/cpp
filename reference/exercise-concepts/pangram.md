# Pangram

## Task

Determine if a sentence is a pangram. A pangram (Greek: παν γράμμα, pan gramma, "every letter") is a sentence using every letter of the alphabet at least once. The best known English pangram is:

    The quick brown fox jumps over the lazy dog.

The alphabet used consists of ASCII letters a to z, inclusive, and is case insensitive. Input will not contain non-ASCII symbols.

## Example

`pangram.h`

```cpp
#ifndef PANGRAM_H
#define PANGRAM_H

#include <string>

namespace pangram {

bool is_pangram(const std::string& s);

} // namespace pangram

#endif // PANGRAM_H
```

`pangram.cpp`

```cpp
#include <bitset>
#include "pangram.h"

const std::uint8_t sizeof_alphabet = 26;

bool pangram::is_pangram(const std::string& s) {
    std::bitset<sizeof_alphabet> alphabet;
    for (const unsigned char c : s) {
        if (std::isalpha(c)) {
            alphabet[std::tolower(c) - 'a'] = true;
        }
    }
    return alphabet.all();
}
```

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- namespaces: the function is member of a namespace
- functions: used as the main entry point for the exercise
- function arguments: input string is passed by argument
- reference: input string is passed by reference to prevent unnecesary copy
- const reference: input string is passed by const reference to forbid to make changes what they refer to
- unsigned integer types: `std::uint8_t` with width of exactly 8 bits
- range-based for loop: operating over a range of values such as all elements of `std::string` container
- bitset: using `std::bitset` to represent alphabet occupancy rate
- work with letter sequences: using specialized functions from `<cctype>` or `<locale>`
- return values: the result is returned by the function

## Alternative approaches

- implement solution as `inline` functions in the `.h` file
- using `std::string_view` to pass input by argument
- using `std::vector<bool>` to store entry of a letter
- using `std::unordered_set` to store entry of a letter
- using `std::uint_fast32_t` to store entry of a letter
- using `std::transform` to make sequence with small letters
- using `std::for_each` to make sequence with small letters
- using `std::unique` to find unique letters in the input sequence
- using `erase-remove idiom` to eliminate elements from input sequence that fulfill certain criterion

## Common mistakes

- forgetting to submit the `.h` file
- forgetting to submit the `.cpp` file
- forgetting to place include guards in `.h` file
- forgetting to delete unused include directives
- writing to `std::cout` or `std::cerr`
- creating references to simple data types
- using `std::set` to store entry of a letter
- argument is not passed by `const` reference

## Common suggestions to improve a solution

- mark all functions `noexcept` if they are not expected to throw exceptions
- place constants in anonymous namespaces
- use `auto` to deduce complicated types
- use `constexpr` to evaluate the value of function or variable at compule time
- use `[[nodiscard]]` attribute to warn on discarding a nodiscard value
