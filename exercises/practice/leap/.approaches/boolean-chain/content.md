# Chain of boolean expressions

```cpp
bool is_leap_year(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
```

The first boolean expression uses the [remainder operator][remainder-operator] to check if the year is evenly divided by `4`.

- If the year is not evenly divisible by `4`, then the chain will "short circuit" due to the next operator being a [logical AND][logical-and] (`&&`),
  and will return `false`.
- If the year _is_ evenly divisible by `4`, then the [logical NOT operator][logical-not] is used to check if the year is _not_ evenly divisible by `100`.
- If the year is not evenly divisible by `100`, then the expression is `true` and the chain will "short-circuit" to return `true`,
  since the next operator is a [logical OR][logical-or] (`||`).
- If the year _is_ evenly divisible by `100`, then the expression is `false`, and the returned value from the chain will be if the year is evenly divisible by `400`.

| year | year % 4 == 0 | year % 100 != 0 | year % 400 == 0 | is leap year |
| ---- | ------------- | --------------- | --------------- | ------------ |
| 2020 | true          | true            | not evaluated   | true         |
| 2019 | false         | not evaluated   | not evaluated   | false        |
| 2000 | true          | false           | true            | true         |
| 1900 | true          | false           | false           | false        |

The chain of boolean expressions is efficient, as it proceeds from testing the most likely to least likely conditions.
[Howard Hinnant][hinnant] wrote a short paragraph about the order of operations on his web page about date-related algorithms.

## Shortening

By using the [implicit conversion][implicit-conversion] from `int` to `bool` the code can be shortened using the [logical NOT operator][logical-not].
Only `0` is converted to `false` and _every non-zero_ value is converted to `true`.

```cpp
bool is_leap_year(int year) {
    return !(year % 4) && ((year % 100) || !(year % 400 == 0));
}
```

## Precedence

You may have noticed the parentheses around the boolean expressions above.
Consider the following code:

```cpp
bool many_parens    = ((year % 100) != 0) || ((year % 400) == 0);
bool some_parens    = (year % 100 != 0) || (year % 400 == 0);
bool no_parens      =  year % 100 != 0 || year % 400 == 0;
```

All lines produce the same result but differ a lot in readability.
The reason for their equal results is the order of operator evaluation (`%`, `!=`, `||`, etc) or [precedence][operator-precedence].
In this example the first operator to get the attention of the compiler is the remainder, followed by the equality operators.
Only then will the compiler go for `&&` and then check `||`.
Mixing `&&` and `||` at the same level of an expression is error-prone.
Some people might overlook that `and` is evaluated before `or` and thus introduce bugs.
This is a potential reason to keep some parenthesis, although they are not necessarily needed by the compiler.
You might be able to follow the code like the compiler, but [other developers might struggle][mixing-and-and-or].

```cpp
true || false && true;
\\ => false
(true || false) && true;
\\ => true
```

## Short-circuit evaluation

If a boolean expression's value is not going to change with further evaluations, C++ code will [short-circuit][short-circuit-evaluation] and skip these "unesssary" evaluations.
They might not change the final result of the boolean, but side-effects will not take place.

```cpp
bool print_and_always_false() {
    std::cout << "Hello!";
    return false;
}

bool print_and_always_true() {
    std::cout << "World!";
    return true;
}

print_and_always_false() && print_and_always_true();
// will only print "Hello!". `print_and_always_true`` is never called.
```

Short-circuiting is a way to speed up your programs by sorting your chain of booleans in a sensible order.
One strategy might be to evaluate expensive operations late or very likely and unambiguous results first.

[remainder-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[logical-not]: https://en.cppreference.com/w/cpp/keyword/not
[logical-and]: https://en.cppreference.com/w/cpp/keyword/and
[logical-or]: https://en.cppreference.com/w/cpp/keyword/or
[hinnant]: https://howardhinnant.github.io/date_algorithms.html#is_leap
[implicit-conversion]: https://en.cppreference.com/w/cpp/language/implicit_conversion
[operator-precedence]: https://en.cppreference.com/w/cpp/language/operator_precedence
[mixing-and-and-or]: https://softwareengineering.stackexchange.com/q/201175/126640
[short-circuit-evaluation]: https://en.wikipedia.org/wiki/Short-circuit_evaluation
