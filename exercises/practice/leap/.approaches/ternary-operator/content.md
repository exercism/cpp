# Ternary operator

```cpp
bool is_leap_year(int year) {
    return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
}
```

The [conditional operator][ternary-operator] is also known as a "ternary conditional operator", or just "ternary operator".
The implementation above uses a maximum of two checks to determine if a year is a leap year.

It starts by testing the outlier condition of the year being evenly divisible by `100`.
It does this by using the [remainder operator][remainder-operator].
If the year is evenly divisible by `100`, then the expression is `true`, and the ternary operator returns if the year is evenly divisible by `400`.
If the year is _not_ evenly divisible by `100`, then the expression is `false`, and the ternary operator returns if the year is evenly divisible by `4`.

| year | year % 100 == 0 | year % 400 == 0 | year % 4 == 0 | is leap year |
| ---- | --------------- | --------------- | ------------- | ------------ |
| 2020 | false           | not evaluated   | true          | true         |
| 2019 | false           | not evaluated   | false         | false        |
| 2000 | true            | true            | not evaluated | true         |
| 1900 | true            | false           | not evaluated | false        |

Although it uses a maximum of only two checks, the ternary operator tests an outlier condition first,
making it less efficient than another approach that would first test if the year is evenly divisible by `4`,
which is more likely than the year being evenly divisible by `100`.

## Shortening

By using the [implicit conversion][implicit-conversion] from `integer` to `bool` the code can be shortened using the [logical NOT operator][logical-not].
Only `0` is converted to `false` and _every non-zero_ value is converted to `true`.

```cpp
bool is_leap_year(int year) {
    return !(year % 100) ? !(year % 400) : !(year % 4);
}
```

It can be thought of as the expression _not_ having a remainder.

## Precedence

You may have noticed the braces around the boolean expressions above.
Consider the following code:

```cpp
bool many_braces    = ((year % 100) != 0) || ((year % 400) == 0);
bool some_braces    = (year % 100 != 0) || (year % 400 == 0);
bool no_braces      =  year % 100 != 0 || year % 400 == 0;
```

All lines produce the same result, but differ a lot in readability.
The reason for their equal results, is the order of operator evaluation (`%`, `!=`, `||`, etc) or [precedence][operator-precedence].
In this example the first operator to get the attention of the compiler is the remainder, followed by the equality operators.
Only then will the compiler go for `&&` and then check `||`.
Some people might overlook that `and` is evaluated before `or` and thus introduce bugs.
This is a potential reason to keep some braces, although they are not necessarily needed in the code.

```cpp
true || false && true;
\\ => false
(true || false) && true;
\\ => true
```

[ternary-operator]: https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
[remainder-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[implicit-conversion]: https://en.cppreference.com/w/cpp/language/implicit_conversion
[logical-not]: https://en.cppreference.com/w/cpp/keyword/not
[operator-precedence]: https://en.cppreference.com/w/cpp/language/operator_precedence
