# Instructions

In this exercise, you will be simulating a windowing based computer system.
You will create some windows that can be moved and resized.
The following image is representative of the values you will be working with below.

```
                  <--------------------- screenSize.width --------------------->

       ^          ╔════════════════════════════════════════════════════════════╗
       |          ║                                                            ║
       |          ║          position.x,_                                      ║
       |          ║          position.y  \                                     ║
       |          ║                       \<----- size.width ----->            ║
       |          ║                 ^      *──────────────────────┐            ║
       |          ║                 |      │        title         │            ║
       |          ║                 |      ├──────────────────────┤            ║
screenSize.height ║                 |      │                      │            ║
       |          ║            size.height │                      │            ║
       |          ║                 |      │       contents       │            ║
       |          ║                 |      │                      │            ║
       |          ║                 |      │                      │            ║
       |          ║                 v      └──────────────────────┘            ║
       |          ║                                                            ║
       |          ║                                                            ║
       v          ╚════════════════════════════════════════════════════════════╝
```

## 1. Define a `size` struct for storing the dimensions of the window

Define a `struct` named `size`.
It should have two member variables `width` and `height` that store the window's current dimensions.
The constructor function should accept initial values for these fields.
The width is provided as the first parameter, the height as the second one.
The default width and height should be `80` and `60`, respectively.

Additionally, define a member function `void resize(int newWidth, int newHeight)` that takes a new width and height as parameters and changes the fields to reflect the new size.

```cpp
size aSize{1080, 764};
aSize.width;
// => 1080
aSize.height;
// => 764

aSize.resize(1920, 1080);
aSize.width;
// => 1920
aSize.height;
// => 1080
```

## 2. Define a `position` struct to store a window position

Define a struct (or class) named `position` with two member variables, `x` and `y` that store the current horizontal and vertical position, respectively, of the window's upper left corner.
The constructor function should accept initial values for these fields.
The value for `x` is provided as the first parameter, the value for `y` as the second one.
The default value should be `0` for both variables.

The position (0, 0) is the upper left corner of the screen with `x` values getting larger as you move right and `y` values getting larger as you move down.

Also define a method `void move(int newX, int newY)` that takes new x and y parameters and changes the properties to reflect the new position.

```cpp
position point{};
point.x;
// => 0
point.y;
// => 0

point.move(100, 200);
point.x;
// => 100
point.y;
// => 200
```

## 3. Define a `programWindow` class

Define a `programWindow` class or struct with __pointers__ to the following member variables:

- `screenSize`: holds a pointer of type `size` with `width` 800 and `height` 600
- `windowSize` : holds a pointer of type `size`, the initial value is the default value of the `size` instance
- `windowPosition` : holds a pointer of type `position`, the initial value is the default value of the `position` instance

When the window is opened (initialized), it always has the default `windowSize` and `windowPosition` in the beginning.
Its constructor should not take any input parameters.

```cpp
programWindow aProgramWindow{};
programWindow.screenSize->width;
// => 800

// Similar for the other fields.
```

## 4. Add a method to resize the window

The `programWindow` class should include a function `resize`.
It should accept a __pointer__ of type `size` as input and attempts to resize the window to the specified size.

However, the new size cannot exceed certain bounds.

- The minimum allowed height or width is 1.
  Requested heights or widths less than 1 will be clipped to 1.
- The maximum height and width depend on the current position of the window, the edges of the window cannot move past the edges of the screen.
  Values larger than these bounds will be clipped to the largest size they can take.
  E.g. if the window's position is at `x` = 400, `y` = 300 and a resize to `height` = 400, `width` = 300 is requested, then the window would be resized to `height` = 300, `width` = 300 as the screen is not large enough in the `y` direction to fully accommodate the request.

```cpp
programWindow aProgramWindow{};

size newSize{600, 400};
aProgramWindow.resize(&newSize);
aProgramWindow.size->width;
// => 600
aProgramWindow.size->height;
// => 400
```

## 5. Add a method to move the window

Besides the resize functionality, the `programWindow` class should also include a function `move`.
It should accept a parameter as a __pointer__ of type `position` as input.
The `move` function is similar to `resize` however, this function adjusts the _position_ of the window to the requested value, rather than the size.

As with `resize` the new position cannot exceed certain limits.

- The smallest position is 0 for both `x` and `y`.
- The maximum position in either direction depends on the current size of the window.
  The edges cannot move past the edges of the screen.
  Values larger than these bounds will be clipped to the largest size they can take.
  E.g. if the window's size is at `x` = 250, `y` = 100 and a move to `x` = 600, `y` = 200 is requested, then the window would be moved to `x` = 550, `y` = 200 as the screen is not large enough in the `x` direction to fully accommodate the request.

```cpp
programWindow aProgramWindow{};

position newPosition{50, 100};
aProgramWindow.move(&newPosition);
aProgramWindow.position->x;
// => 50
aProgramWindow.position->y;
// => 100
```

## 6. Change a program window

Implement a `changeWindow` function that accepts a __pointer__ to a `programWindow` object as input and changes the window to the specified size and position.

The window should get a width of 400, a height of 300 and be positioned at x = 100, y = 150.

```cpp
programWindow aProgramWindow{};
changeWindow(&programWindow);
aProgramWindow.size->width;
// => 400

// Similar for the other fields.
```