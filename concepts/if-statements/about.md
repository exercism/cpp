# About

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

> Note: any variables created in the initialization cannot be accesed after the end of the if statement.
