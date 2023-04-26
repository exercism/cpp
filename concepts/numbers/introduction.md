# Introduction
The built-in number types in C++ can be divided into integers and floating points.
Integers are whole numbers like `0`, `691`, or `-2`.
Examples of floating point numbers are `6.02214076`, `0.1`, or `-1.616`.

## Integers
When you assign a value to an `int` variable, you can do so directly with a literal.
There are different integer literals based on the base of the representation.
Decimal integer literals are the most common and use the numbers `0` to `9`.
By adding a special prefix it is possible to use other bases.
The example below shows the number `9421` in its four representations and prefixes.

```cpp
int decimal{9241};              // base 10: 0-9
int hexadecimal{0x24CD};        // base 16: 0-9 and A-F
int binary{0b10010000011001};   // base  2: 0-1
int octal{022031};              // base  8: 0-7
                                // Leading with a 0 not the letter o.
```
You can use an apostrophe to separate digits for easier readability.
`9'241` is the same as `0b0100'100'0001'1001` or `92'4'1`.

## Floating-Point Numbers

The floating-point literals come in two flavors. 
Next to the intuitive `0.0024` it is possible to use its scientific notation `2.4e-3`.
The most common floating-point type is `double`.

## Arithmetic

C++ supports `+`, `-`, `*`, `/`, `(` and `)` and `%` to form expressions.
The result from the operation between two integers is also an integer.
`5 / 2` will return `2`.
When one of the involved types is a floating-point type, the result will also be of a floating-point.
`5.0 / 2` and `5 / 2.0` will return `2.5`.
`%` is the modulus operator and will return the remainder of an integer division: `5%3` is `2`.


## The auto keyword

It is possible to let the compiler figure out the correct type of a variable at the point of declaration with the `auto` keyword.
The practice can help during refactoring and shines with very long type names, that will come in later concepts.

```cpp
auto feist{1234};             // feist is of type int, as 1234 is an integer literal
auto red_cross{0xED1B2E};     // also an int
auto pythargoras{1.41421356}; // pythargoras is of type double

auto two_times(int number) {
    return number * 2;        // the return type of two_times will be int because the 
}                             // multiplication of two int types returns an int type
```

