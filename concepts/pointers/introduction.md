# Introduction

Like many other languages, C++ has pointers.
You already know `references` and pointers are similar, but think of them as a level closer to the inner workings of your computer.
Pointers are variables that hold memory addresses.
They are used to directly interact with memory, enabling dynamic memory allocation and efficient data manipulation in C++.

If you're new to pointers, they can feel a little mysterious but once you get used to them, they're quite straight-forward.

They're a crucial part of C++, so take some time to really understand them.
The bare-bone version in this concept is also called _dumb pointer_ or _raw pointer_.
With modern C++ there are also `smart pointers`, the basic type is not smart at all and you have to handle all the work manually.

Before digging into the details, it's worth understanding the use of pointers.
Pointers are a way to share memory with other parts of our program, which is useful for two major reasons:
1. When you have large amounts of data, making copies to pass between functions is very inefficient.
  By passing the memory location of where the data is stored instead, you can dramatically reduce the resource-footprint of our programs.
2. By passing pointers between functions, you can access and modify the single copy of the data directly, meaning that any changes made by one function are immediately visible to other parts of the program when the function ends.

## General Syntax

A pointer declaration in C++ involves specifying the data type the pointer points to, followed by an asterisk (`*`) and the pointer's name.
When pointers are declared, they are not automatically initialized.
Without explicit assignment, a pointer typically holds an indeterminate value, often referred to as a "garbage address."
While certain compilers might initialize pointers to `nullptr`, this behavior is not guaranteed across all compilers, so it's essential not to rely on it.
It's best practice to explicitly initialize raw pointers and verify their non-null status before utilization to avoid potential issues.

```cpp
int* ptr = nullptr; // Declares a pointer and makes sure it is not invalid
```

To assign the address of a variable to a pointer, you use the address-of operator (`&`).
Dereferencing a pointer is done using the asterisk (`*`) operator.

```cpp
std::string opponent = "Solomon Lane";
// 'ethan' points to the memory address of the string opponent
std::string* ethan = &opponent; 
// Instead of ethan's, the opponent's name stored at the memory address
std::string passportName = *ethan;
```

Attention: dereferencing has to be done explicitly, while `references` just worked like an alias.

## Pointer Arithmetic

Pointer arithmetic allows you to perform arithmetic operations on pointers, which is particularly useful when working with arrays.
Adding an integer to a pointer moves it to a different memory location based on the size of the data type it points to.

```cpp
// Stargate addresses
int gateAddresses[] = {462, 753, 218, 611, 977};
// 'ptr' points to the first element of 'gateAddresses'
int* ptr = gateAddresses; 
// Accesses the third Stargate address through pointer arithmetic
int dialedAddress = *(ptr + 2); 
// Chevron encoded! Dialing Stargate address:
openStarGate(dialedAddress);
```

~~~~exercism/caution
Pointer arithmetic in C++ can easily lead to undefined behavior if not handled carefully.
Undefined behavior can manifest in unexpected program outcomes, crashes, or even security vulnerabilities.
One infamous example of the consequences of undefined behavior occurred in the [explosion of the Ariane 5 rocket][ariane-flight-v88] in 1996, where a software exception caused by the conversion of a 64-bit floating-point number to a 16-bit signed integer led to a catastrophic failure.
~~~~

## Accessing member variables

In C++, the `->` operator is used to access members of an object through a pointer to that object.
It is a shorthand which simplifies accessing members of objects pointed to by pointers.
For instance, if `ptr` is a pointer to an object with a member variable `x`, instead of using `(*ptr).x`, you can directly use `ptr->x`.
This operator enhances code readability and reduces verbosity when working with pointers to objects.

Here's a brief example, with a `struct` `Superhero` that has a member variable `superpower`.
The main function creates a pointer `dianaPrince` to a `Superhero` object (representing Wonder Woman).
The `->` operator is used to access the member variable `superpower`, showcasing Wonder Woman's iconic "Lasso of Truth."

```cpp
struct Superhero {
    std::string superpower;
};

Superhero* dianaPrince = new Superhero;
dianaPrince->superpower = "Lasso of Truth";
// Using the -> operator to access member variable superpower:
std::cout << "Wonder Woman, possesses the mighty " << dianaPrince->superpower;
// Memory cleanup:
delete dianaPrince; 
```

## Dynamic Memory Allocation and Null Pointers

In C++, `new` is used to dynamically allocate memory for objects on the heap during runtime.
It returns a pointer to the allocated memory, allowing objects to have lifetimes not tied to a specific scope.
However, it's important to always pair `new` with `delete` to properly deallocate memory and avoid memory leaks.
Dynamic memory allocation should be used cautiously to prevent common issues like memory leaks and accessing deallocated memory.

Pointers can also be set to a special value called a null pointer, which indicates that they do not point to a valid memory address.
Null pointers are commonly used to initialize pointers before assigning them to valid addresses.

```cpp
// There is a dark mark bearer, but who is it?
std::string* darkMarkBearer{nullptr};
// It is Bellatrix!
darkMarkBearer = new std::string{"Bellatrix Lestrange"};
// She has been defeated
delete darkMarkBearer;
// Reset pointer to null, symbolizing there is no more darkMarkBearer at the moment
darkMarkBearer = nullptr; 
```

A pointer should either hold the address of a valid object, or be set to `nullptr`.
That way you only need to test pointers for null, and can assume any non-null pointer is valid.
When an object is destroyed, any pointers to the destroyed object will be left _dangling_ (they will not be automatically set to `nullptr`).
It is your responsibility to detect these cases and ensure those pointers are subsequently set to `nullptr`.

~~~~exercism/advanced
In older code, you might encounter two alternatives to `nullptr`.
Firstly, the literal `0` is specifically interpreted as a null value for pointers, though it's the only scenario where an integral literal can be assigned to a pointer.
Secondly, the `preprocessor macro` `NULL`, inherited from C and defined in the `<cstddef>` header, is another representation of a null pointer, though its usage is less common in modern C++ code.
~~~~

## Pointers vs. references

Pointers and references both enable indirect access to objects, but they differ in their capabilities and safety considerations.
Pointers offer the flexibility of changing their target object and can be assigned null.
However, this flexibility introduces risks, such as dereferencing null pointers or creating dangling pointers.
References, on the other hand, cannot be null and are bound to valid objects upon creation, avoiding these risks.
Given their safer nature, references should be preferred over pointers unless the additional functionalities provided by pointers are necessary.

[ariane-flight-v88]: https://en.wikipedia.org/wiki/Ariane_flight_V88
