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
You might be thinking that with the name `scoped`, there would also be be `unscoped` enumerations -- and you would be correct.
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



[magic numbers]: https://en.wikipedia.org/wiki/Magic_number_(programming)
