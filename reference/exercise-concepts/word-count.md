# Word Count

## Task

Given a phrase, count the occurrences of each _word_ in that phrase.

For the purposes of this exercise you can expect that a _word_ will always be one of:

1. A _number_ composed of one or more ASCII digits (ie "0" or "1234") OR
2. A _simple word_ composed of one or more ASCII letters (ie "a" or "they") OR
3. A _contraction_ of two _simple words_ joined by a single apostrophe (ie "it's" or "they're")

When counting words you can assume the following rules:

1. The count is _case insensitive_ (ie "You", "you", and "YOU" are 3 uses of the same word)
2. The count is _unordered_; the tests will ignore how words and counts are ordered
3. Other than the apostrophe in a _contraction_ all forms of _punctuation_ are ignored
4. The words can be separated by _any_ form of whitespace (ie "\t", "\n", " ")

For example, for the phrase `"That's the password: 'PASSWORD 123'!", cried the Special Agent.\nSo I fled.` the count would be:

```text
that's: 1
the: 2
password: 2
123: 1
cried: 1
special: 1
agent: 1
so: 1
i: 1
fled: 1
```

## Example

`"word_count.h"`

```cpp
#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <map>
#include <string>

namespace word_count
{

std::map<std::string, int> words(std::string const& text);

}

#endif
```

`word_count.cpp`

```cpp
#include "word_count.h"
#include <algorithm>
#include <cctype>
#include <iterator>
#include <vector>

using namespace std;

namespace
{

string trim_copy_if(string const& s, string const& delims)
{
    string cpy(s);
    // Trim front
    while (!cpy.empty() && delims.find(cpy.front()) != string::npos)
        cpy.erase(cpy.begin());
    // Trim back
    while (!cpy.empty() && delims.find(cpy.back()) != string::npos)
        cpy.pop_back();
    return cpy;
}

vector<string> split(string const& s, string const& delims)
{
    auto start = s.begin();
    vector<string> words;
    for (auto end = s.begin(); end != s.end(); end++) {
        if (delims.find(*end) != string::npos) {
            if (start != end) {
                words.push_back(s.substr(start - s.begin(), end - start));
            }
            start = end + 1;
        }
    }
    if (start < s.end()) {
        words.push_back(s.substr(start - s.begin(), s.end() - start));
    }
    return words;
}

string normalize_text(string const& text)
{
    string normalized;
    transform(text.begin(), text.end(), back_inserter(normalized),
        [](const char c) { return (isalnum(c) || c == '\'') ? tolower(c) : ' '; });
    return normalized;
}

string trim_word(string const& word)
{
    return trim_copy_if(word, "' ");
}

vector<string> split_text_into_words(string const& text)
{
    vector<string> words = split(text, "\t ");
    transform(words.begin(), words.end(), words.begin(), trim_word);
    return words;
}

}

namespace word_count
{

map<string, int> words(string const& text)
{
    map<string, int> count;
    for (auto const& word : split_text_into_words(normalize_text(text)))
    {
        if (!word.empty())
        {
            ++count[word];
        }
    }
    return count;
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
- strings: argument is `string` (or `string_view`)
- range for-loop, for-loop and while-loop: most solutions use iteration/repetition
- `tranform`: include `#include <algorithm>` to use it
- template specializations: create vector of strings, create map of results
- containers: vectors and maps
- iterators: for standard algorithms
- lambda expressions: to normalize input to avoid case-sensitive search
- conditionals using if: conditionally execute logic using an `if` statement
- strings: arguments are strings (or maybe string views)
- operator precedence: misunderstanding precedence can lead to an invalid solution
- short-circuit evaluation: understanding sce can lead to a more efficient solution
- return values: the result is returned by the function
- pass by reference to const: large strings may be expensive to copy
- increment: `++`
- equality operators: `==` and `!=`

## Alternative approaches

- implement solution as `inline` functions in the `.h` file
- using `boost::algorithm` for `to_lower_copy` or `to_lower`
- using `boost::split`
- using `boost::tokenizer`
- using `switch-case` to remove separators
- using `regex` to replace separators with `" "`
- creating custom `word_iterator` to skip over separators
- using `const char *` and C-style interfaces

## Common mistakes

- passing `string` by value
- forgetting to submit the `.h` file
- forgetting to enable and/or run all the tests
- no include guards
- using reference to `char`
- using `const char *`
- using explicit iterator types instead of type deduction with `auto`
- making one big function that does everything

## Common suggestions to improve a solution

- use `constexpr` whenever the result of computation does not depend on run-time data
- add `noexcept` to mark all functions that are not expected to throw exceptions
- using `boost::algorithm` for `to_lower_copy`
- using `boost::split`
- using `ranges` instead of `begin`-`end` pairs
