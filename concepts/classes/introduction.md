# Introduction

It is time to get to one of the core paradigms of C++: object-oriented programming (OOP).
OOP is centered around `classes` - user-defined types of data with their own set of related functions.
We will start with the basics and will cover more advanced topics further down the syllabus tree.

## Members

Classes can have **member variables** and **member functions**.
They are accessed by the **member selection** operator `.`.
Just as variables outside of `classes`, it is advisable to initialize member variables with a value upon declaration.
This value will then become the default for newly created objects from this class.

## Encapsulation and Information Hiding

Classes offer the option to restrict access to their members.
The two basic cases are `private` and `public`.
`private` members are not accessible from outside the class.
`public` members can be called freely.
All members are `private` by default and need to be explicitly marked to be usable outside of the class.

## Basic example

The definition of a new `class` can be seen in the following example.
Notice the `;` after the definition.

```cpp
class Wizzard {
  public:               // from here on all members are accessible publicly
    int cast_spell() {  // defines the public member function cast_spell
      return damage;
    }
    std::string name{}; // defines the public member variable `name`
  private:              // from here on all members are private
    int damage{5};      // defines the private member variable `damage`
};

```

You can access all variables from within the class.
Take a look at `damage` inside the `cast_spell` function.
You cannot read or change `private`  members outside of the class:

```cpp
Wizzard silverhand{};
// calling the `cast_spell` function is okay, it is public:
silverhand.cast_spell();
// => 5

// name is public and can be changed:
silverhand.name = "Laeral";

// damage is private:
silverhand.damage = 500;
 // => Compilation error
```

## Constructors

Constructors offer the possibility to assign values to member variables at object creation.
They have the same name as the `class` and do not have a return type.
A class can have several constructors.
This is useful if you do not always have a need to set all variables.

```cpp
class Wizzard {
  public:
    Wizzard(std::string new_name) {
      name = new_name;
    }
    Wizzard(std::string new_name, int new_damage) {
      name = new_name;
      damage = new_damage;
    }
    int cast_spell() {
      return damage;
    }
    std::string name{};
  private:
    int damage{5};
};

Wizzard el{"Eleven"};       // deals  5 damage
Wizzard vecna{"Vecna", 50}; // deals 50 damage
```

Constructors are a big topic and have many nuances.
If you are not explicitly defining a `constructor` for your `class`, then - and only then - the compiler will do the job for you.
This has happened in the first example above.
The _silverhand_ object is created by calling the default constructor, no arguments were passed.
All variables are set to the value that was stated in the definition of the class.
If you had not given any values in that definition, the variables might be uninitialized, which might have unintended consequences.

~~~~exercism/note
## Structs

Structs came from the language's original C roots and are as old as C++ itself.
They are effectively the same thing as `classes` with one important exception.
By default, everything in a `class` is `private`.
Structs, on the other hand, are `public` until defined otherwise.
Conventionally, the `struct` keyword is often used for **data-only structures**.
The `class` keyword is preferred for objects that need to ensure certain properties.
Such an invariant could be that the `damage` of your `Wizzard` `class` cannot turn negative.
The `damage` variable is private and any function that changes the damage would ensure the invariant is preserved.
~~~~
