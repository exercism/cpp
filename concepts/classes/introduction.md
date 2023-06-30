# Introduction

It is time to get to one of the core principles of C++: object-oriented programming (OOP).
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
All members are `private` by default and need to be explicitly marked to be usable outside of the class.

## Basic example

The definition of a new `class` can be seen in the following example.
Notice the `;` after the definition.

```cpp
class Wizzard {
  public:
    int cast_spell() {
      return damage;
    }
    std::string name{};
  private:
    int damage{5};
};

```

You can access all variables from within the class.
Take a look at `damage` inside the `cast_spell` function.
You cannot read or change `private`  members outside of the class:

```cpp
Wizzard silverhand{};
// calling the `cast_spell` function is okay, it is public:
iggwilv.cast_spell();
// => 5
// name is public and can be changed:
silverhand.name = "Laeral";
// damage is private -> Compilation error
silverhand.damage = 500; 
```

## Constructors

Constructors offer the possibility to assign values to member variables at object creation.
They have the same name as the `class` and do not have return type.
A class can have several constructors:

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
If you are not explicitly defining a `constructor` for your `class`, the compiler will do the job for you.
This has happened in the first example above.
All variables are set to the value that was stated in the definition of the class.
If you had not given any values in that definition, the variables would be uninitialized, which might have unintended consequences.

## Structs

Structs are a holdover from the C past that developed into C++.
They are effectively the same thing as `classes` with one important exception.
By default, everything in a `class` is `private`.
Structs, on the other hand are `public` until defined otherwise.
Conventionally, the `struct` keyword is often used for **data-only structures**.
The `class` keyword is preferred for objects that have both data **and** function members.
The class keyword is preferred for objects that have both data and functions.