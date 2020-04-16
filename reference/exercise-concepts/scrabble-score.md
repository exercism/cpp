# Scrabble score

## Task

Given a word, compute the Scrabble score for that word.

### Letter Values

You'll need these:

```text
Letter                           Value
A, E, I, O, U, L, N, R, S, T       1
D, G                               2
B, C, M, P                         3
F, H, V, W, Y                      4
K                                  5
J, X                               8
Q, Z                               10
```

### Examples

"cabbage" should be scored as worth 14 points:

- 3 points for C
- 1 point for A, twice
- 3 points for B, twice
- 2 points for G
- 1 point for E

And to total:

- `3 + 2*1 + 2*3 + 2 + 1`
- = `3 + 2 + 6 + 3`
- = `5 + 9`
- = 14

## Example `scrabble_score.h`

```cpp
#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H

#include <string>

namespace scrabble_score
{

int score(const std::string &word);

}

#endif
```

`example.cpp`

```cpp
#include "scrabble_score.h"
#include <cctype>

namespace scrabble_score
{

namespace
{
const int letter_scores[26] = {
    1,  // A
    3,  // B
    3,  // C
    2,  // D
    1,  // E
    4,  // F
    2,  // G
    4,  // H
    1,  // I
    8,  // J
    5,  // K
    1,  // L
    3,  // M
    1,  // N
    1,  // O
    3,  // P
    10, // Q
    1,  // R
    1,  // S
    1,  // T
    1,  // U
    4,  // V
    4,  // W
    8,  // X
    4,  // Y
    10  // Z
};

}

int score(const std::string &word)
{
    int result = 0;
    for (const char c : word) {
        if (std::isalpha(c)) {
            result += letter_scores[std::tolower(c) - 'a'];
        }
    }
    return result;
}

}
```

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- including directives: `<string>`
- namespaces: the function is member of a namespace
- functions: used as the main entry point for the exercise
- function arguments: word is passed as argument
- integers: an `int` is for keeping score
- signed integers: the core guidelines recommend signed integers for arithmetic
- equality operators: `==` and `!=`
- return values: the result is returned by the function
- const-qualification: input and letters in the word do not change
- conditional statements: `if` to filter out non-alphanumeric characters
- functions: create function with a compatible signature
- `noexcept` function specifier: solution should not throw
- range for-loop or for-loop: to get though characters in the input
- arrays: to hold letter scores
- template specializations: store score per letter in a hash-map
- pass by `const` reference: large string may be expensive to copy

## Alternative approaches

- using `tranform_reduce` to get from the letters to letter scores and from the letter scores to the final score
- using `tranform` to get from the letters to letter scores and `accumulate` from the letter scores to the final score
- substracting 'a' from letter code and using that as an index in array of scores
- creating an accumulator and adding letters' scores in a loop
- using `boost::flat_map` as a container for letters' scores
- using `std::array` as a container for letters' scores

## Common mistakes

- making copy of the input instead of passing as `const` reference
- using `std::map` instead of `std::unordered_map`to store scores
- using `switch-case` or `if` to map letters to scores
- not making letter scores `const` or `constexpr`
- using C-style arrays
- explicitly using iterators

## Common suggestions to improve a solution

- use more cache-friendly container, such as `boost::flat_map` or `std::array`
- use range-for loop instead of for loop with an index
- use `accumulate` and `transform`
- use `transform_reduce`
- use `const` for individual characters and input word
- use `constexpr` for data known at compile time
- add `noexcept` to mark all functions that are not expected to throw exceptions
- use `std::string_view` instead of `std::string`
