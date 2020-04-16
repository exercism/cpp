# Isogram

## Task

Determine if a word or phrase is an isogram.

An isogram (also known as a "nonpattern word") is a word or phrase without a repeating letter, however spaces and hyphens are allowed to appear multiple times.

Examples of isograms:

    lumberjacks
    background
    downstream
    six-year-old

The word `isograms`, however, is not an isogram, because the `s` repeats.

## Example

`isogram.h`

```cpp
#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <string>

namespace isogram {

bool is_isogram(const std::string& word);

} // namespace isogram

#endif // ISOGRAM_H
```

`isogram.cpp`

```cpp
#include <unordered_set>
#include "isogram.h"

bool isogram::is_isogram(const std::string& word) {
  std::unordered_set<char> entries;
  for (unsigned char c : word) {
    if (std::isalpha(c) &&
        !entries.insert(static_cast<char>(std::tolower(c))).second) {
      return false;
    }
  }
  return true;
}
```

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- namespaces: the function is a member of namespace
- function: used as the main entry point for the exercise
- string: container that stores and manipulates sequences of `char`
- unordered set: associative container that collect unique objects
- reference: word is passed by reference to prevent unnecesary copy
- const reference: word is passed by const reference to forbid to make changes what they refer to
- range-based for loop: operating over a range of values such as all elements of container
- static_cast conversion: explicitly converts between types
- return values: the result is returned by the function

## Alternative approaches

- using associative containers (`std::map`, `std::unordered_map`, `std::set`, `std::unordered_set`) to store entries of a letter
- using arrays (`std::vector`, `std::array`) to store entries of a letter
- using `std::bitset` to store entries of a letter
- using regular expressions to determine if the character is letter
- using regular expressions to replace non-alphabetic characters

## Common mistakes

- forgetting to place include guards in `.h` file
- forgetting to submit the `.h` file
- forgetting to submit the `.cpp` file
- forgetting to remove commented code
- placing `using namespace std` to `.h` file
- passing function argument by value
- using C-style arrays to store entries of a letter
- creating references to simple data types
- placing non-inline function definitions to `.h` file
- calling `std::toupper` or `std::tolower` (and similar functions) without casting `char` argument to `unsigned char`

## Common suggestions to improve a solution

- use `std::string_view` to refer to sequence of char
- use `auto` to deduce complicated types
- mark function `noexcept` if it is not expected to throw exceptions
- use `constexpr` to evaluate the value of function or variable at compule time
- use `[[nodiscard]]` attribute to warn on discarding a nodiscard value
