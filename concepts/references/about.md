# About

## Copies and References

With our current knowledge, it is a bit cumbersome to update a variable with the help of a function.
Every function argument is handled like a copy and does not change the original value.
Depending on the size of your type, this can have serious consequences for the performance of your code.

```cpp
int adjust_salary(int base, int kids) {
    return base + kids * 500;
}
int now_a_mother_of_twins{2500};
adjust_salary(now_a_mother_of_twins, 2);

// now_a_mother_of_twins is still 2500
now_a_mother_of_twins = adjust_salary(now_a_mother_of_twins, 2);
// now_a_mother_of_twins is now 3500
```

`References` can be seen as aliases - changes to them have an effect on the original variable.
`References` use an **ampersand** (`&`) in the type declaration.

```cpp
int balance{1000};
int& budget{balance};
int pro_computer_wheels{699};
budget -= pro_computer_wheels;
// budget is now 301;
// balance is also 301;
```
[Reseating][Reseating] (changing the binding of a `reference`) is not possible.
You cannot have an unitialized `reference`.
`References` need to be initialized with an existing variable.

```cpp
int main_acc{1'000'000};
int side_acc{-20};
int& savings{main_acc};
// => main_acc and savings are 1'000'000

// try to reseat savings to use main account
savings = side_acc;
// savings and main_acc are now -20
// as this uses the **value** of side_acc
savings += 20;
// savings and main_acc are now 0, side_acc is stil -20

int& future_budget;
// => compiler error, reference must be bound!
```

## `void`

With the power of `references` you might not need to return a value from a function at all.
`void` is used as a return type in this scenario.

```cpp
void increase_power(int& level) {
    level += 500;
}
int goku{8700};
increase_power(goku);
// goku's power level?
// It's over 9000!
```

[Reseating]: https://stackoverflow.com/questions/728233/why-are-references-not-reseatable-in-c
