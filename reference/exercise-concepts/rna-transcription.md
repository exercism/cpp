# RNA Transcription

## Task

Given a DNA strand, return its RNA complement (per RNA transcription).

Both DNA and RNA strands are a sequence of nucleotides.

The four nucleotides found in DNA are adenine (**A**), cytosine (**C**),
guanine (**G**) and thymine (**T**).

The four nucleotides found in RNA are adenine (**A**), cytosine (**C**),
guanine (**G**) and uracil (**U**).

Given a DNA strand, its transcribed RNA strand is formed by replacing
each nucleotide with its complement:

- `G` -> `C`
- `C` -> `G`
- `T` -> `A`
- `A` -> `U`

## Example

`rna_transcription.h"`

```cpp
#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

#include <string>

namespace rna_transcription
{

char to_rna(char nucleotide);
std::string to_rna(std::string const& nucleotide);

}

#endif
```

`rna_transcription.cpp`

```cpp
#include "rna_transcription.h"
#include <algorithm>
#include <iterator>

using namespace std;

namespace rna_transcription
{

char to_rna(const char nucleotide)
{
    const string dna_nucleotides("CGAT");
    const string rna_nucleotides("GCUA");
    const auto pos = dna_nucleotides.find(nucleotide);
    if (pos != string::npos) {
        return rna_nucleotides[pos];
    }
    return 0;
}

string to_rna(string const& sequence)
{
    string transcription;
    transform(sequence.begin(), sequence.end(), back_inserter(transcription),
        [](char c) { return to_rna(c); });
    return transcription;
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
- function overload: for `string` and for `char`
- strings: argument is `string` (or `string_view`)
- const-qualification: inputs do not change and should be `const`
- `noexcept` function specifier: none of the functions in this exercise are throwing
- `constexpr`: solution does not depend on any run-time data
- conditionals using if: conditionally execute logic using an `if` statement
- STL: for `find` and `transform`
- containers: vectors and maps, string
- iterators: for standard algorithms
- lambda expressions: to normalize input to avoid case-sensitive search
- return values: the result is returned by the function
- range for-loop or for-loop: to iterate over the sequence
- pass by `const` reference: large string may be expensive to copy

## Alternative approaches

- using `switch-case` to translate from DNA to RNA
- using `std::map` for DNA to RNA mapping
- throwing an exception in case of an invalid input
- using `std::string_view` for input
- using `std::string` or `std::array` to store keys (DNA) and values (RNA)

## Common mistakes

- making copy of the input instead of passing as `const` reference
- not making DNA and RNA nucleotides `const` or `constexpr`
- submitting the `.cpp` file without the `.h` file.
- forgetting to submit the `.h` file
- forgetting to enable and/or run all the tests
- no include guards
- writing to `std::cout` or `std::cerr`
- using C-style arrays
- explicitly using iterators
- creating references to simple numeric data types

## Common suggestions to improve a solution

- Adding `const` for input arguments
- Use `std::array` instead of `std::string` for the case of separate DNA and RNA sequences
- Use `std::map` for dictionary approach to DNA -> RNA translation
- Use `constexpr` for data known at compile time
- Add `noexcept` to mark all functions that are not expected to throw exceptions
- Using `std::range`' from `<ranges>`
- Use range-for loop instead of for loop with an index
- Use `std::transform` and lambda function
- Use `std::back_inserter` for filling in the RNA sequence
- Use anonymous namespace for storing constants
