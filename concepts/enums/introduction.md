# Introduction

## Enumerations

So far we have mostly handled numbers and strings.
To model the real world, we might want a limited number of options that a variable can take on.
If you work for a skateboard manufacturer the deck material can be selected from maple, bamboo, or plastic.

You could use integers to encode those values, but would have to use extra code to check if there is an invalid value coming from the system for the material.
This is a case for `enumerations`.

## Example usage

The specific term for this kind of enumeration is `scoped enumeration`.
The deck material can be written like this.
Note the `enum class` keyword and the `;` at the end of the definition:

```cpp
enum class DeckMaterial {
    maple,
    bamboo,
    plastic
};
```
Now, look at a pricing function in the skate shop and take note of the scope resolution operator (`::`) to specify an `enumerator` from the `enumeration`:

```cpp
double deck_price(double base_price, DeckMaterial material) {
    if(material == DeckMaterial::plastic) {
        return base_price * 0.9;
    }
    return base_price * 1.3;
}
```

## Scoping

Imagine you have a second `enumeration` for the material of the wheels:

```cpp
enum class WheelMaterial {
    steel,
    clay,
    plastic
};

bool comparison{DeckMaterial::plastic == WheelMaterial::plastic};
// => false
```
Although the wheels and the deck can both be made of _plastic_, the two cannot be confused.
Each `enumeration` will have its `enumerators` in its own scope - its own namespace.
This is the reason they are called `scoped enumerations`.

~~~~exercism/advanced
## Unscoped Enumerations

You might think that there should be `unscoped` enumerations as well and you are correct.
`Unscoped enumerations` lost favor to the version above, because they populate the global namespace.
For this reason you could not have two `unscoped enumerations` with the same `enumerators` like _plastic_ in the example above.

Also, `unscoped enumerations` implicitly convert to integers. 
Look at the example to see a surprising result:

```cpp
enum CitrusFruits {
    lemons,  // 0
    oranges, //1
};

enum IceCream {
    walnut, // 0
    apples,      // 1
};

bool comparison{apples == oranges};
// => true
```

If you want to convert `scoped enumerations` into integers you can use `static_cast<int>`.
~~~~
