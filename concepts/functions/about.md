# Functions

Functions are a way to group code that belongs together. 
They can be called from other functions or from the main function. 
Functions can be used to structure code and to avoid repetition. Functions can also be used to make code more readable. 

## Function declaration

A function declaration consists of a return type, a name, and a parameter list. 
The return type is the type of the value that the function returns. 
The name is used to call the function. 
The parameter list is a comma-separated list of parameters. Each parameter consists of a type and a name. The parameter list can be empty. 

```cpp
// Function declaration
int add(int first_argument, int second_argument);
```

## Function definition

A function definition consists of a function declaration and a function body. 
The function body is a block of code that is executed when the function is called. The function body is enclosed in curly braces. 

```cpp
// Function definition
int add(int first_number, int second_number) {
    return first_number + second_number;
}
```


## Function call

A function call consists of a function name and a comma-separated list of arguments. 
Each argument is an expression that is passed to the function. The arguments are assigned to the parameters in the function declaration. 

```cpp
// Function call
int sum{add(1, 2)};
// The function call add(1, 2) and returns 3 which is assigned to the variable sum.
```

## void Functions

A void function is a function that does not return any value. 
The return type of a void function is void. 
However, it is recommended to use the **return** keyword to return from a void function, even if the function does not return a value. So the function can exit properly. 


```cpp
// void Function
void print_hello_world() {
    std::cout << "Hello World" << std::endl;
    return;
}
// The function call print_hello_world() prints "Hello World" to the console. And does not return any value.
``` 

## Function overloading

Function overloading is a feature that allows multiple functions with the same name to exist in the same scope. 
The functions must have different parameter lists. 

```cpp
// Function overloading
int add(int first_number, int second_number) {
    return first_number + second_number;
}

double add(double first_number, double second_number) {
    return first_number + second_number;
}

int sum_int{add(1, 2)};
// sum_int is 3

double sum_double{add(1.5, 2.7)};
// sum_double is 3.2
```

## Function template

A function template is a function that can be used to create functions with different types. 
The function template must have a template parameter list. The template parameter list is a comma-separated list of template parameters. Each template parameter consists of a type and a name. 
The template parameter list can be empty. 

```cpp
// Function template
// The T is a template parameter.
// We can replace the T with any type. E.g. int, double, float, char, etc.

template <typename T>
T add(T first_number, T second_number) {
    return first_number + second_number;
}

int sum_int{add<int>(1, 2)};
// sum_int is 3

double sum_double{add<double>(1.5, 2.7)};
// sum_double is 3.2
```

## Default arguments

A default argument is an argument that is used when no argument is passed to the function. 
A default argument is specified in the function declaration. It is specified by assigning a value to the parameter in the function declaration. 
A default argument must be the last argument in the parameter list. 
It can be overridden by passing an argument to the function.

```cpp
// Default arguments
// Can you make the default argument more useful?
int add(int first_number, int second_number = 1) {
    return first_number + second_number;
}

int sum_with_one_argument{add(1)};
// sum_with_one_argument is 2

int sum_with_two_arguments{add(1, 2)};
// sum_with_two_argument is 3
```
