# Anagram

## Task

Given a word and a list of possible anagrams, select the correct sublist.

Given "listen" and a list of candidates like "enlists" "google" "inlets" "banana" the program should return a list containing "inlets".

## Example

`anagram.h`

```cpp
#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <string>
#include <vector>

namespace anagram {

class anagram {
public:
    explicit anagram(std::string word) : word_(word) {}
    std::vector<std::string> matches(const std::vector<std::string>& words);
private:
    std::string word_;
};

} // namespace anagram

#endif // !ANAGRAM_H
```

`anagram.cpp`

```cpp
#include <algorithm>
#include "anagram.h"

static bool is_anagrams(std::string lhs, std::string rhs) {
    if ((lhs.size() == rhs.size())) {
        std::transform(lhs.begin(), lhs.end(), lhs.begin(),
                        [](unsigned char c) { return std::tolower(c); });
        std::transform(rhs.begin(), rhs.end(), rhs.begin(),
                        [](unsigned char c) { return std::tolower(c); });
        if (lhs.compare(rhs) != 0) {
            std::sort(lhs.begin(), lhs.end());
            std::sort(rhs.begin(), rhs.end());
            return lhs.compare(rhs) == 0;
        }
    }
    return false;
}

std::vector<std::string> anagram::anagram::matches(const std::vector<std::string>& words) {
    std::vector<std::string> anagrams;
    for (const std::string& word : words) {
        if (is_anagrams(word_, word)) {
            anagrams.push_back(word);
        }
    }
    return anagrams;
}
```

## Concepts

- .h file: the most common approach is to use a `.h` for the declarations
- .cpp file: the most common approach is to use a `.cpp` for the definitions
- include guard: protect against multiple inclusion within a single translation unit
- .cpp includes .h: a `.cpp` file should include its `.h` file
- namespaces: the class declaration is a member of a namespace
- class: used as the main entry point for the exercise
- constructors: used to initialize class members when an object of class is created
- explicit specifier: mark constructor as explicit to prevent the compiler from using that constructor for implicit conversions
- vector: sequence container representing array that can dynamically change its own size
- string: container that stores and manipulates sequences of `char`
- reference: vector of words are passed by reference to prevent unnecesary copy
- const reference: vector of words are passed by const reference to forbid to make changes what they refer to
- range-based for loop: operating over a range of values such as all elements of container
- `transform`: modifying sequence operation which apllies the given function to range of values and stores the result in another range
- string comparison: compare two character sequences
- `sort`: sorting algoritm which sorts the elements in ascending order
- lambda expressions: create an anonymous function object capable of capturing variables in scope
- return values: the result is returned by the function

## Alternative approaches

- using `std::initializer_list` to provide access to an array of words
- using `boost::algorithm::string` instead `std::string`
- using `boost::algorithm` collection to process the words
- using associative containers (`std::map`, `std::unordered_map`, `std::set`, `std::unordered_set`) to store histogram of letters
- using array containers (`std::array`, `std::vector`) to store histogram of letters
- using `std::is_permutation` to check if permutation of character elements exists
- using `std::equal` to check equality of character sequences

## Common mistakes

- forgetting to place include guards in `.h` file
- forgetting to submit the `.cpp` file
- forgetting to delete unused include directives
- placing non-inline function definitions to `.h` file
- placing `using namespace std` to `.h` file

## Common suggestions to improve a solution

- mark functions `noexcept` if they are not expected to throw exceptions
- use `auto` to deduce complicated types
- use `[[nodiscard]]` attribute to warn on discarding a nodiscard value
