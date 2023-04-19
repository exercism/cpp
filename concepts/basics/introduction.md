# Introduction

To start the C++ journey we are starting with variables, function calls, and comments.

## Variables

C++ is a typed language.
The type of a variable has to be stated upon the declaration of a variable.
Its type cannot change during its lifetime.
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

## Arithmetic Operations

Arithmetic expressions like `*`, `+`, or `-` can be part of a statement. 

```cpp
3 * 2;
// => 6
```

## Updating Variables

You can reassign variables, as long as keep their type:

```cpp
tomatoes = tomatoes - 5; // tomatoes is now 75
potatoes = (32 * 2) + 11; // potatoes is now 75 as well
```

## Functions

Functions have a name and a return type.
It is possible to pass a parameter list to the function.

An example of a function named `always_fortyseven` that would always return 47 would look like this:

```cpp
int always_fortyseven() {
    return 47;
}
```

Or `total_fee`, a function with three parameters.

```cpp
int total_fee(int vip, int adult, int kids) {
    /*
    total_fee calculates the total price for a group of VIP and adult guests with kids.
    Kids get a flat discount on the standard fee.
    VIP guest fees are calculated by multiplying the fee.
    */
    int standard_fee{30};
    int kids_discount{15};
    int vip_multi{3};
    int kids_total_fee = kids  * (standard_fee - kids_discount);

    return vip * vip_multi + standard_fee * adult + kids_total_fee;
}
```

C++ does not return the last statement in a function like some other languages.
The `return` keyword is required for the code to compile.

## Comments

Comments come in two flavors: single- and multi-line.
You have already seen the syntax above.
Everything that comes after `//` in a line is ignored by the compiler.
Multi-line comments are also known as C-style comments. 
They are surrounded by `/*` and `*/`.
