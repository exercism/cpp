# Introduction

To set off the C++ journey we are starting with variables, function calls, and comments.

## Comments

Comments come in two flavors: single- and multi-line.
Everything that comes after `//` on the same line is ignored by the compiler.
Multi-line comments are also known as C-style comments.
They are surrounded by `/*` and `*/`.
Anything that comes between these will be ignored as well.

## Variables

C++ is a typed language.
All types need to be known at compile time, and you generally need to state them explicitly.
A variable's type cannot change.
An integer variable with the name `years` can be declared like this:

```cpp
int years;
```

It is good practice to initialize variables upon declaration.
C++ offers different mechanisms to do so.
The version with the curly braces is more in line with modern C++, but the equal-sign version is also very common.

```cpp
int tomatoes{80};
int potatoes = 40;
```

~~~~exercism/caution
C++ does allow using uninitialized variables.
Until the variable is deliberately set, it is undefined and might contain anything.
To avoid used-before-set errors and undefined behavior it is adviseable to **always initialize**.
Undefined behavior can crash your program at the worst possible moment, while it was running fine previously.
It cannot be stressed enough: avoid undefined behavior at all cost.
~~~~

## Arithmetic Operations

Arithmetic operators like `*`, `+`, or `-` can be part of an expression like `3 * 2` or `tomatoes + potatoes`.

## Updating Variables

You can reassign variables, as long as they keep their type:

```cpp
tomatoes = tomatoes - 5; // tomatoes is now 75
potatoes = (32 * 2) + 11; // potatoes is now 75 as well
```

## Functions

Functions have a name, a return type and a (possibly empty) parameter list.
An example of a function named `always_fortyseven` that would always return 47 would look like this:

```cpp
int always_fortyseven() {
    return 47;
}
```

Here is `vip_fee`, which has one parameter:
```cpp
int vip_fee(int standard_fee) {
    /*
    vip_fee calculates the vip fee based on the standard_fee.
    */
    int vip_multi{3};
    return standard_fee * vip_multi;
}
```

Or `total_fee`, a function with three parameters and a call to another function.

```cpp
int total_fee(int vips, int adults, int kids) {
    /*
    total_fee calculates the total price for a group of VIP and adult guests with kids.
    Kids get a flat discount on the standard fee.
    VIP guest fees are calculated by calling vip_fee.
    */
    int standard_fee{30};
    int kids_discount{15};

    int kids_total_fee = kids  * (standard_fee - kids_discount);
    int vips_total_fee = vips * vip_fee(standard_fee);
    int adult_total_fee = adults * standard_fee;

    return vips_total_fee + adult_total_fee + kids_total_fee;
}
```

Functions in C++ do not return the value of the last statement like in some other languages.
The `return` keyword is required for the code to compile.

### Whitespace

Whitespace is used for formatting source code and includes spaces, tabs, or newlines.
As the compiler ignores unnecessary whitespace, you can use it to structure your code.
Smart use of whitespace can improve the readability of your code.
There are different formatting standards, but these are all conventional and not enforced by the compiler.

```cpp
// Formatting makes it easier to find bugs

int eggs_yolks =  3;
int      yeast = 15;

int flour=500;int sugar=200;// compact, but difficult to read
```
