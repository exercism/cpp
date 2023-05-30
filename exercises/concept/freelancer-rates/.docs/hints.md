# Hints

## General

- Browse the [`cmath` reference][cmath-reference] to learn about common mathematical operations and transformations that work with `doubles`.

## 1. Calculate the daily rate given an hourly rate

- Basic arithmetic operations where one argument is an `int`, and the other is a `double`, will return a `double`.

## 2. Calculate a discounted price

- Basic arithmetic operations where one argument is an `int`, and the other is a `double`, will return a `double`.

## 3. Calculate the monthly rate, given an hourly rate and a discount

- There is a [function in the `cmath` header][cmath-ceil] for rounding up.

## 4. Calculate the number of workdays given a budget, hourly rate, and discount

- Casting a `double` to an `int` will truncate the number at the decimal point.

[cmath-reference]: https://en.cppreference.com/w/cpp/header/cmath
[cmath-ceil]: https://en.cppreference.com/w/cpp/numeric/math/ceil
