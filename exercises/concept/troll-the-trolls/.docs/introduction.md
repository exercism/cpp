# Introduction

## Enumerations

So far we have mostly handled numbers and strings.
To model the real world, we might want a limited number of values that a variable can take on.
You might want a dedicated type with a few distinct values with distinct names.
For example, in a skateboard factory, having the deck material be a choice of only maple, bamboo, or plastic.

You could use integers to encode those values, but you would have to use extra code to check if there is an invalid value coming from the system for the material.
The meaning of those [_magic numbers_][magic numbers] is difficult to trace over the source code and they are prone to mix-ups.
`enumerations` can be used to encourage expressive code and to restrict unintentional comparison mistakes.

## Example usage

The specific term for this kind of enumeration is `scoped enumeration`.
The snippet below shows how to write a `DeckMaterial` `enumeration`.
Note the `enum class` keyword and the `;` at the end of the definition:

```cpp
enum class DeckMaterial {
    maple,
    bamboo,
    plastic
};
```
Now, look at a pricing function in the skate shop and take note of the scope resolution operator (`::`) specifying an `enumerator` from the `enumeration`:

```cpp
double deck_price(double base_price, DeckMaterial material) {
    if(material == DeckMaterial::plastic) {
        return base_price * 0.9;
    }
    return base_price * 1.3;
}
```

## Scoping

Imagine you have a second `enumeration` for wheel material:

```cpp
enum class WheelMaterial {
    steel,
    clay,
    plastic
};
```
Although the wheels and the deck can both be made of _plastic_, the two cannot be confused. 
They are different _types_:  `DeckMaterial` plastic and `WheelMaterial` plastic.
Each `enumeration` will have its `enumerators` in its own scope - its own `namespace`.
This is the reason they are called `scoped enumerations`.

~~~~exercism/advanced
## Unscoped Enumerations
You might be thinking that with a name like `scoped`, there would also be  _`unscoped`_ enumerations -- and you would be correct.
`Unscoped enumerations` are becoming less popular because they all share the same global namespace.
Because of the sharing, you could not have two `unscoped enumerations` with the same `enumerators` like _plastic_ in the example above.

Also, `unscoped enumerations` implicitly convert to integers. 
Look at the example below for a surprising result:

```cpp
enum CitrusFruits {
    lemons,  // 0
    oranges, //1
};

enum IceCream {
    walnut,  // 0
    apples,  // 1
};

bool comparison{apples == oranges};
// => true

// Example from above:
bool comparison{DeckMaterial::plastic == WheelMaterial::plastic};
// => Does not compile!
```

If you want to convert `scoped enumerations` to integers you can use `static_cast<int>`.
~~~~


## Switch Statements

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

One important thing about the switch construct is that the code will continue to execute until it is stopped by a `break` (or a `return`) statement.
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

The main use case for this continued execution feature is a statement that has several labels.
Multiple switch results can map to the same piece of code to be executed.
This way - in a booking app, for example - the called function for group sizes 2 and 3 can be the same:
```cpp
switch (group_size) {
case 1:
    book_room();
    break;
case 2:
case 3:
    book_apartment(group_size);
    break;
default:
    book_house(group_size);
}
// book_apartment happens when group_size is 2 or 3
```

[magic numbers]: https://en.wikipedia.org/wiki/Magic_number_(programming)
