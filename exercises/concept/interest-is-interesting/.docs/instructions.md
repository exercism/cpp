# Instructions

In this exercise, you'll be working with savings accounts.
Each year, the balance of your savings account is updated based on its interest rate.
The interest rate your bank gives you depends on the amount of money in your account (its balance):

- 3.213% for a balance less than `0` dollars (balance gets more negative).
- 0.5% for a balance greater than or equal to `0` dollars, and less than `1000` dollars.
- 1.621% for a balance greater than or equal to `1000` dollars, and less than `5000` dollars.
- 2.475% for a balance greater than or equal to `5000` dollars.

You have four tasks, each of which will deal with the balance and its interest rate.

## 1. Calculate the interest rate

Implement the `interest_rate` function to calculate the interest rate based on the specified balance:

```cpp
interest_rate(200.75);
// => 0.5
```

## 2. Calculate the interest

Implement the `yearly_interest` function to calculate the interest based on the specified balance:

```cpp
yearly_interest(200.75):
// => 1.003750
```

## 3. Calculate the annual balance update

Implement the `annual_balance_update` function to calculate the annual balance update, taking into account the interest rate:

```cpp
annual_balance_update(200.75);
// => 201.75375
```

## 4. Calculate the years before reaching the desired balance

Implement the `years_until_desired_balance` function to calculate the minimum number of years required to reach the desired balance, taking into account that each year, interest is added to the balance.
This means that the balance after one year is: start balance + interest for start balance.
The balance after the second year is the balance after one year + interest for the balance after one year.
And so on, until the current year's balance is greater than or equal to the target balance.

```cpp
double balance {200.75};
double targetBalance {214.88};
years_until_desired_balance(balance, targetBalance)
// => 14
```

Note that the value returned is an `int`.
