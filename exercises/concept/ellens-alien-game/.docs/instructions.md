# Instructions

Ellen is making a game where the player has to fight aliens.
She has just learned about Object Oriented Programming (OOP) and is eager to take advantage of what using `classes` could offer her program.

To Ellen's delight, you have offered to help and she has given you the task of programming the aliens that the player has to fight.


## 1. Create the `Alien` Class

Define the `Alien` class with a constructor that accepts two `int` parameters `x` and `y`, putting them into `x_coordinate` and `y_coordinate` member variables.
Every alien will also start off with a health level of `3`, so the `health` member variable should be initialized as well.

`health` should be a private member variable.
To let other parts of the program read the health information, Ellen wants to have a `public` `get_health()` method which returns an `int`.

```cpp
Alien alien{2, 0};
alien.x_coordinate;
// => 2
alien.y_coordinate;
// => 0
alien.get_health();
// => 3
```

Now, each alien should be able to internally track its own position and health.

## 2. The `hit` Function

Ellen would like the Alien `class` to have a `hit` method that decrements the health of an alien object by `1` when called.
This way, she can simply call `some_alien_instance.hit()` instead of having to manually change an alien's health.
Make sure that the health points do not drop below zero.
The function should return `true`.
Ellen wants to introduce shields at a later point, which would then report `false` if the shield is up.

```cpp
Alien alien {0, 0};
alien.get_health();
// => 3 (Initial health value)

alien.hit(); // Decrements health by 1 point.
alien.get_health();
// => 2
```

## 3. The `is_alive` Function

You realize that if the health keeps decreasing, at some point it will probably hit `0`.
It would be a good idea to add an `is_alive` method that Ellen can quickly call to check if the alien is... well... alive. 😉
`some_alien_instance.is_alive()` should return a boolean.

```cpp
alien.get_health();
// => 1
alien.is_alive();
// => true
alien.hit();
alien.get_health();
// => 0
alien.is_alive();
// => false
```

## 4. The `teleport` Function

In Ellen's game, the aliens can teleport!
You will need to write a `teleport` method that takes `x_new` and `y_new` values, and changes the alien's coordinates accordingly.
For the time being, the function should return `true`.
Ellen wants to add teleport-blocking bombs in later levels, which would then report `false` for failed teleporting attempts.

```cpp
alien.teleport(5, -4);
alien.x_coordinate;
// => 5
alien.y_coordinate;
// => -4
```

## 5. The `collision_detection` Function

If the aliens can be hit by something, then they need to be able to detect when such a collision might occur.
Ellen needs to know if two aliens occupy the same coordinates.
The `collision_detection()` function takes another alien object as an argument and returns a `bool`.

```cpp
Alien lrrr {3, 6};
Alien ndnd {-2, 12};
lrrr.collision_detection(ndnd);
// => false
ndnd.teleport(3, 6);
ndnd.collision_detection(lrrr);
// => true
```
