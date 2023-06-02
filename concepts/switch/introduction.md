# Introduction

Like other languages, C++ also provides a `switch` statement.
Switch statements are a shorter way to write long `if ... else if` statements.
To make a switch, we start by using the keyword `switch` followed by an integer.
We then declare each one of the conditions with the `case` keyword.
We can also declare a `default` case, that will run when none of the previous `case` conditions matched.
Each case should end with a `break` (or a `return`) statement.

```cpp
int price{0};
int adults{3};
int kids{2};

switch (int group_size{adults + kids}) {
    case 1:
        price = 50;
        break;
    case 2:
        price = 70;
        break;
    default:
        price = group_size * 30;
}
```

## Fall-through

One important thing about the switch construct is that the code will continue to be executed until it stops at a `break` statement.
This can lead to unexpected behavior.

```cpp
int adults{1};
int kids{0};
switch (int group_size{adults + kids}) {
    case 1:
        price = 50;
    case 2:
        price = 70;
    default:
        price = group_size * 30;
}
// price will be 30!
```

The main use case for this feature is a statement, that has several labels:
```cpp
switch (group_size) {
case 1:
    book_room();
    break;
case 2:
case 3:
    book_appartment();
    break;
default:
    book_house(group_size);
}
// book_appartment happens wheng roup_size is 2 or 3
```