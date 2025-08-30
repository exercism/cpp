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

## Assignment operator

The assignment operator assigns a variable with a literal.
Always takes place from right to left, and never the other way around.

```cpp
int length = 5;
int width = 2;
length = width;
```

Here integer value `5` is assigned to the variable `length`.
Then integer value `2` is assigned to variable `width`.
Finally value of `width` is copied to the variable `length` and the earlier value `5` will be lost.
Consider also that we are only assigning the value of `width` to `length` at the moment of the assignment operation.
Therefore, if the value of `width` changes at a later moment, it will not affect the value taken by `length`.

Assignment operator can be combined with the other operators(arithmetic & bitwise) known as `compound assignment` operators `+=`, `-=`, `*=`, `/=`, `%=`.
These operators modify the current value of a variable by performing an operation on it.

```cpp
// we start with 0 people
int people{};
// we need 0 eggs
int eggs{};
// two people joined:
people += 2;
// people is now 2
// let's add 3 eggs per person
eggs += 3 * people;
// eggs is now 6
```

Variables `people` & `eggs` are initialized to `0`.
Then, we add integer value `2` over the existing value `0` of the variable `people` and assign it back to `people`.
`people` becomes `2` now.
Later, we add `3` eggs for each person, which turns out to be `6` eggs in total.
Now add this `6` to existing value `0` of the variable `eggs` and assign it back to `eggs`.
`eggs` will be `6` now.
The equivalent expression would be `people = people + 2` and `eggs = eggs + (3 * people)`.


[cpp_numerical_bases]: https://cplusplus.com/doc/hex/
