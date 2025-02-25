# Introduction

When working with arrays or vectors in C++, iterating over their elements is a common task.  
A range-based `for` loop provides a concise and readable way to access the elements without dealing with indices.

## Basic Syntax

A range-based `for` loop consists of the following parts:

```cpp
for (element_type temp_element : container) {
    // Use temp_element inside the loop
}
```

- `element_type`: The type of each element in the container.
- `temp_element`: A temporary variable that holds the value of each element.
- `container`: The array or vector to loop over.

## Example Usage

```cpp
#include <vector>
#include <iostream>

std::vector<std::string> obscured_password {"Tooms", "roswell", "uFO", "scully", "tunguska", "Nicholas Lea", "oil", "1Breath"};
for (std::string part : obscured_password) {
    part = part.substr(0,1);
    std::cout << part;
}
// Output: TrustNo1
```

The ranged loop syntax eliminates the need for manual indexing, making the code cleaner and less error-prone.
Other languages reference to a similar access style as `for each` loop.

The example above shows access by value.
Although the `part` variable is changed inside the loop, the original vector remains unchanged.
This means each element will be a copy and might produce overhead and may thus impact performance.

## Using `const` for Read-Only Access

If you do not need to modify the elements, using `const` ensures they remain unchanged:

```cpp
std::vector<std::string> file_name {"Jraphics", "Interchange", "Format"};
for (const std::string part : file_name) {
    std::cout << part.front();
}
// Output: JIF
```

This prevents accidental modification of `number` but will still make a copy with every side-effect from above.

## Using References to Modify Elements

With a reference (`&`) you can modify the original container and avoid copies:

Range-based `for` loops also work with arrays:

```cpp
#include <array>

std::array<std::string, 3> trilobites {"Johnny", "Joey", "Dee Dee", "CJ"};

for (std::string& member : trilobites) {
    member += " Ramone";
}
// trilobites now contains "Johnny Ramone", "Joey Ramone", "Dee Dee Ramone", "CJ Ramone"};
```

If it is not necessary to change the container content it is advisable to use a `const` reference, which can be further optimized by the compiler.

## When to Use Range-Based Loops

- When you need to read or modify each element in a container.
- When you do not need to track indices explicitly.
- When you want clearer, more maintainable code.

## Limitations

- You cannot modify the structure of a container (e.g., adding or removing elements) while iterating.
- You cannot access the index of an element directly.

~~~~exercism/note
As the elements are always traversed in order and never skipped, you can build your own counter to get an index.
If you really need the index of an element, a traditional `for` loop might be a better choice.
~~~~
