# Introduction
The built-in number types in C++ can be divided into integers and floating points.
Integers are whole numbers like `0`, `691`, or `-2`.
Floating point numbers are numbers with a decimal point like `6.02214076`, `0.1`, or `-1.616`.

## Integers
The following example shows the declaration and initialization of four different variables 

```cpp
int m_morales{9241};              // base 10: 0-9
int a_apaec{0x24CD};              // base 16: 0-9 and A-F
int m_gargan{0b10010000011001};   // base  2: 0-1
int b_reilly{022031};             // base  8: 0-7
                                  // Leading with a 0 not the letter o.
```
When you assign a value to an `int` variable, you can do so directly with a literal.
A literal is a hard-coded number like `9241`.
There are different integer literals for several bases of the representation.
Decimal integer literals are the most common and use the digits `0` to `9`.
By adding a special prefix, like `0x`, it is possible to use other bases.
The example above shows the number `9421` in its four representations and prefixes.
All variables are initialized to the same value.

For more details on the different representation systems, take a look at [a small tutorial][cpp_numerical_bases].

You can use an apostrophe to separate digits for easier readability.
`9'241` is the same as `0b0100'100'0001'1001` or `92'4'1`.

## Floating-Point Numbers

The floating-point literals come in two flavors. 
In addition to the intuitive `0.0024` it is possible to use its scientific notation `2.4e-3`.
The most common floating-point type is `double`.

## Arithmetic

C++ supports `+`, `-`, `*`, `/`, `(` and `)` and `%` to form expressions.
The result from the operation between two integers is also an integer.
`5 / 2` will return `2`.
When one of the involved types is a floating-point type, the result will also be of a floating-point.
`5.0 / 2` and `5 / 2.0` will return `2.5`.
`%` is the remainder operator and will return the remainder of an integer division: `5%3` is `2`.

[cpp_numerical_bases]: https://cplusplus.com/doc/hex/