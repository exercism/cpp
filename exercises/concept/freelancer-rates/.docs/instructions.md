# Instructions

In this exercise, you'll be writing code to help a freelancer communicate with a project manager.
Your task is to provide a few utilities to quickly calculate daily and monthly rates, optionally with a given discount.

We first establish a few rules between the freelancer and the project manager:

- The daily rate is 8 times the hourly rate.
- A month has 22 billable days.

Sometimes, the freelancer is offering to apply a discount on their daily rate (for example for their most loyal customers or not-for-profit customers).

Discounts are modeled as fractional numbers representing percentages, for example, `25.0` (25%).

## 1. Calculate the daily rate given an hourly rate

Implement a function to calculate the daily rate given an hourly rate:

```cpp
daily_rate(60)
// => 480.0
```

The returned daily rate should be of type `double`.

## 2. Calculate a discounted price

Implement a function to calculate the price after a discount.

```cpp
apply_discount(150, 10)
// => 135.0
```

The returned value should always be of type `double`, not rounded in any way.

## 3. Calculate the monthly rate, given an hourly rate and a discount

Implement a function to calculate the monthly rate, and apply a discount.

```cpp
monthly_rate(77, 10.5)
// => 12130
```

The returned monthly rate should be rounded up (take the ceiling) to the nearest integer.

## 4. Calculate the number of complete workdays given a budget, hourly rate, and discount

Implement a function that takes a budget, an hourly rate, and a discount, and calculates how many complete days of work that covers.

```cpp
days_in_budget(20'000, 80, 11.0)
// => 35
```

The returned number of days should be rounded down (take the floor) to the next integer.
