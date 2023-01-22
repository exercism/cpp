# Introduction

Functions, methods and classes allows you to group code into a reusable unit. We are focusing on on methods, which 
are functions that attached to a class. You'll learn more about classes concepts later on. 

## Variables and values

All parameters must be explicitly typed; there is no type inference for parameters.
It is good practice to initialize values right after the declaration.

## Arithmetics operators

All arithmetic operators compute the result of specific arithmetic operation and returns its result. The arguments are not modified. Examples are `*`, `+` or `/`.

```cpp
int i = 6;
int j = 7;
int addition = i + j;        // addition is 13
int multiplication = i * j;  // multiplication is 42
```

## Methods

Methods in the same class can be called without any prefixes. They differ by return type, name and the number of parameters and their types. If you call a method you have to match all of these. 

```cpp
// A definition of a method that returns and integer and has three integer arguments:
int myFormula(int a, int b, int c) {
    int x = a * b;
    int m = -c;
    return m*x;
}

int intermediate = myFormula(1, 3, 52);
int final_result = myFormula(10, intermediate, 11);
```

## Parameters vs. Arguments

```cpp
int secretFormula(int first, int second) {
    int secret = 14;
    return first * secret - second;
}
```
Let's quickly cover two terms that are often confused together: `parameters` and `arguments`. 
Method parameters are the names defined in the function's signature, such as `first` and `second` in the function `secretFormula` above.
The arguments are the concrete values passed to the method parameters when we invoke the function.
For instance, in the example below, `11` and `-4` are the arguments passed to the `first` and `second` parameters:

```cpp
secretFormula(11, 1-4);
```

## Return Values

Values are returned to the calling code from functions using the `return` keyword.
The execution of the function ends as soon as it hits one of those `return` statements.
The type of the return value is defined by the type in front of the method's name. In the 
case above we know that `secretFormula` will return an integer. The hello-world example was 
a function that returned a `string`.

## A word on classes

C++ code is often divided into a header file, that ends in `.h` and the implementation in the `.cpp` file.
The definition of the class can tell you, which methods it has and how you can use them.

```cpp
namespace bikeInfo {
    class ShigeruSpecial {
        public:
            static int getGears();
            int getID();
    };
}
```
The code above does not tell you about the implementation details, but you know that the `ShigeruSpecial` bike has 
a `getGears` and a `getID` method. Both return an integer. Both have the `public` modifier, meaning they can be accessed from code outside the `ShigeruSpecial` class. Another information is the `static` modifier. It tells you, that the `getGears` method can be invoked without creating an object of the class first. All those bikes have the same amount of gears, but every bike has its own ID.

## Invoking methods

Invoking a function is done by specifying the function's name and passing arguments for each of the function's parameters in parenthesis. It is also possible to have function and methods without parameters. Class methods 
can be called with the `.` operator with the object, or with the `::` operator, when you do not want to create 
an object for a static method.

When you are writing methods in a class you can invoke other class methods without the `::` operator.

```cpp

using namespace bikeInfo;

// calling the static method directly
int gearNumber = ShigeruSpecial::getGears();

// Creating the object and calling the method on the object
ShigeruSpecial bike = new ShigeruSpecial();
int gearsFromObject = bike.gearNumber();

// this way you can also call non-static methods:
int id = bike.getID();
```

## Comments

C++ has single line comments that start with `//` and continue until the end of the line. There are also multi-line comments as shown below:

```cpp
int myInteger = -1; // Comments can be in the same line as instructions

/* Multi-line comments
   do not end 
   until they are closed via:
*/
``` 