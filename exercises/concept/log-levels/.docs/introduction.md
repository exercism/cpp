# Introduction

### Includes

In general, you don't want to reinvent the wheel when it comes to programming.
For many standard algorithms, there will be someone who might have already done your work for you.

### Include directive

To include the content of other files C++ uses the `include` directive.
These includes should be stated at the top of the file.
During compilation, the line with the directive is replaced by the content of the respective file.
Namespaces are kept as they are in the original file after includes.

### The Standard Library

The standard library offers many common functions, algorithms, and data structures.
The standard library uses the `std` namespace.

One example is the C numerics library `cmath`.
It provides many common mathematical operations.

```cpp
#include <cmath>

int cube_me(int a) {
    // raise `a` to the third power
    return std::pow(a, 3);
}
```

~~~~exercism/note
Standard libraries are included with angled braces `<>` instead of double quotes `"`.
The difference is the location, where the compiler searches for the respective files.
The search in the current project is skipped for the angled braces version, and it directly starts in the system's include directories.
If you want to include local files you would use double quotes: `#include "myfile"`
~~~~

## Strings

A `string` in C++ is a mutable object that represents text as a sequence of characters (letters, digits, punctuation, etc.).
Strings are manipulated by calling the string's methods.

### Strings Library

In C++ the string type and the associated functions have to be included from the strings library before usage.
You can do so by adding `#include <string>` to the top of your file.
They will then populate the `std` namespace.
The fully qualified name of the string type is `std::string`.
The string literal uses the double quote character: `"`.

```cpp
#include <string>
std::string w_berry_quote{"A well-made sentence, I think, is a thing of beauty."};
```

### Common String Operations

You can use the `+` operator to concatenate strings:

```cpp
std::string original_title{"The School of Rock"};
std::sequel_indicator{"Electric Boogaloo"};
std::string next_movie_title = original_title + " 2: " + sequel_indicator;
```

To use the strings library, you need to know that it is possible to call a function that belongs to an object.
These are called member functions.
Later in the syllabus, you will learn more about member functions and the connected class concept.

```cpp
std::string qualification{"awesome"};
// 1st argument: from the index to the end of the string:
std::string who_is_awesome = qualification.substr(5);
// => "me"

// 2nd optional argument for the length:
std::string material{"haunted books"};
std::string ghost = material.substr(8, 3);
// => "boo"
```

The `find` function is also very useful.
It is called as a member function on the string and takes a string as the argument.
`find` returns the zero-indexed position of the _first_ occurrence in the string.

```cpp
std::string new_release{"apple released a new app!"};
new_release.find("app");
// => 0
new_release.find("e");
// => 4
```
