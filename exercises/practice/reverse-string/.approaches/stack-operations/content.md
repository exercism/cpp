# Approach: Stack operations

**reverse_string.h**
```cpp
#pragma once

#include <string>

namespace reverse_string
{
    std::string reverse_string(std::string_view str);
}
```

**reverse_string.cpp**
```cpp
#include "reverse_string.h"

namespace reverse_string
{

// (1) the function takes its argument "by value"
std::string reverse_string(std::string_view original)
{
    // (2) start with an empty string
    std::string result;

    // (3) loop as long as the parameter still contains characters
    while (!original.empty())
    {
        // (3) pop the last character off the parameter and append it to the result
        char c = original.back();
        original.remove_suffix(1);
        result.push_back(c);
    }

    // result now contains a reversed version of the string
    return result;
}

} // namespace reverse_string;
```

## The type of the parameter

The function takes a `std::string_view` as its argument.
That type was added to C++17, it is an immutable "view" of a string, it is cheap to construct and to copy (see [cppreference.com][cppref-stringview].)
We can use it here because the function does not *really* modify the underlying string, the `remove_suffix(1)` just narrows the view.

## Constructing an empty `std::string`

There are several equivalent ways to construct an empty `std::string`, for example:
```cpp
std::string result;
std::string result{};
std::string result{""};
std::string result = "";
auto result = std::string{};
```

None of them is significantly better than the others, chosing one is mostly a matter of personal preferences.

## Treating the two strings as stacks.

In programming and computer science "stack" is a term for a container that supports some specific operations (see [Wikipedia][wiki-stack]):

- You can *push* a new item onto the stack.
- You can *pop* the top-most (i.e. most recently pushed) item off the stack.
- You can *peek* at the top-most item (without popping it off the stack).

`std::string_view` have the member functions `back` (see [cppreference.com][cppref-stringview-back]) and `remove_suffix` (see [cppreference.com][cppref-string-removesuffix]).
`std::string` has the member function `push_back` (see [cppreference.com][cppref-string-pushback]).
They let use use the two strings like stacks.

- `original.back()` returns the last character of the `original`.
- `original.remove_suffix(1)` *conceptually* removes the last character from the `original` (it narrows the view).
- `result.push_back()` appends a character to the `result`.

If we do that repeatedly until the `original` is empty, the `result` contains the reversed string.

## Conclusion

This is a valid approach, it is correct and reasonably efficient.
It is mostly presented as an interesting idea and unique way to think about the problem.


[cppref-stringview]: https://en.cppreference.com/w/cpp/string/basic_string_view
[wiki-stack]: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
[cppref-stringview-back]: https://en.cppreference.com/w/cpp/string/basic_string_view/back
[cppref-string-removesuffix]: https://en.cppreference.com/w/cpp/string/basic_string_view/remove_suffix
[cppref-string-pushback]: https://en.cppreference.com/w/cpp/string/basic_string/push_back
