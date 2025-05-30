# Introduction

## Comparisons

In C++, you can compare values using the comparison operators.

| Comparison        | Operator  |
| ------------------| --------- |
| equal             | `==`      |
| not equal         | `!=`      |
| less              | `<`       |
| less or equal     | `<=`      |
| greater           | `>`       |
| greater or equal  | `>=`      |

The result of these comparisons is always a boolean value:

```cpp
int a{3};

bool eq1 = a != 4; // true

bool eq2 = a > 5;  // false
```

The operators `==` and `!=` check whether a value is equal to another or not, respectively.
Here are some common examples:

```cpp
bool eq3 = 2 == 3; // false, integer comparison

bool eq4 = 2.1 != 2.2; // true, float comparison

bool eq5 = "hello" == "hello"; // true, string comparison
```

The other operators check if one value is greater than (`>`), greater or equal to (`>=`), less than (`<`), and less or equal to (`<=`) to another value.
This kind of comparison is available for numbers and strings.
When comparing strings, the dictionary order (also known as lexicographic order) is followed.

```cpp
bool eq6 = 2 > 3; // false, integer comparison

bool eq7 = 1.2 < 1.3; // true, float comparison

bool eq8 = "Hello" < "World"; // true, string comparison
```

## If Statements

Conditionals in C++ are similar to conditionals in other languages.
The underlying type of any conditional operation is the `bool` type, which can have the value of `true` or `false`.
Conditionals are often used as flow control mechanisms to check for various conditions.

An `if` statement can be used, which executes its code if the underlying condition is `true` like this:

```cpp
std::string value{"val"};

if (value == "val") {
    return "was val";
}
```

In scenarios involving more than one case many `if` statements can be chained together using the `else if` and `else` statements.

```cpp
int number{33};

if (number > 0) {
   return "positive";
} else if (number < 0) {
    return "negative";
} else {
   return "zero";
}
```

Since C++17 if-statements can also include a short initialization statement that can be used to initialize one or more variables for the if statement.
For example:

```cpp
int num{7};
if (int v{2 * num}; v > 10) {
    return v;
} else {
    return num;
}
// => 14
```

> Note: any variables created in the initialization cannot be accessed after the end of the if statement.
