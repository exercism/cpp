# Introduction

Like many other languages, C++ has _pointers_.
You already know _references_ and _pointers_ are similar, but think of them as a level closer to the inner workings of your computer.
_Pointers_ are variables that hold object addresses.
They are used to directly interact with objects, enabling dynamic memory allocation and efficient data manipulation in C++.

If you're new to _pointers_, they can feel a little mysterious but once you get used to them, they're quite straight-forward.

They're a crucial part of C++, so take some time to really understand them.
The bare-bone version in this concept is also called _dumb pointer_ or _raw pointer_.
With modern C++ there are also _smart pointers_, the basic type is not smart at all and you have to handle all the work manually.

Before digging into the details, it's worth understanding the use of _pointers_.
_Pointers_ are a way to share an object's address with other parts of our program, which is useful for two major reasons:
1. Like _references_, pointers avoid copies and help to reduce the resource-footprint of your program.
2. Unlike _references_, pointers can be reassigned to different objects.
3. Pointers can also point to a null value, to indicate, that they currently do not point to any object.

## General Syntax

A pointer declaration in C++ involves specifying the data type to which the the pointer is pointing, followed by an asterisk (`*`) and the pointer's name.
When pointers are declared, they are not automatically initialized.
Without explicit assignment, a pointer typically holds an indeterminate value, often referred to as a "garbage address."
While certain compilers might initialize pointers to `nullptr`, this behavior is not guaranteed across all compilers, so it's essential not to rely on it.
It's best practice to explicitly initialize raw pointers and verify their non-null status before utilization to avoid potential issues.

```cpp
int* ptr{nullptr}; // Declares a pointer and makes sure it is not invalid
```

To assign the address of a variable to a pointer, you use the address-of operator (`&`).
Dereferencing a pointer is done using the _indirection operator_ (`*`) operator.

```cpp
std::string opponent{"Solomon Lane"};
// 'ethan' points to the address of the string opponent
std::string* ethan{&opponent}; 
// Instead of ethan's, the opponent's name address is given to the passPort
std::string passportName{*ethan};
```

Attention: dereferencing has to be done explicitly, while _references_ just worked like an alias.

## Pointer Arithmetic

_Pointer arithmetic_ allows you to perform arithmetic operations on pointers, which is particularly useful when working with arrays.
Adding an integer to a pointer makes it point to a different element.

```cpp
// Stargate addresses
int gateAddresses[] = {462, 753, 218, 611, 977};
// 'ptr' points to the first element of 'gateAddresses'
int* ptr{gateAddresses}; 
// Accesses the third Stargate address through pointer arithmetic
int dialedAddress{*(ptr + 2)}; 
// Chevron encoded! Dialing Stargate address:
openStarGate(dialedAddress);
```

~~~~exercism/caution
Pointer arithmetic in C++ can easily lead to __undefined behavior__ if not handled carefully.
Undefined behavior can manifest in unexpected program outcomes, crashes, or even security vulnerabilities.
One infamous example of the consequences of undefined behavior occurred in the [explosion of the Ariane 5 rocket][ariane-flight-v88] in 1996, where a software exception caused by the conversion of a 64-bit floating-point number to a 16-bit signed integer led to a catastrophic failure.
~~~~

## Accessing member variables

In C++, the `->` operator is used to access members of an object through a pointer to that object.
It is a shorthand which simplifies accessing members of objects pointed to by pointers.
For instance, if `ptr` is a pointer to an object with a member variable `x`, instead of using `(*ptr).x`, you can directly use `ptr->x`.
This operator enhances code readability and reduces verbosity when working with pointers to objects.

Here's a brief example, with a _struct_ `Superhero` that has a member variable `superpower`.
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

## Pointers vs. references

Pointers and references both enable indirect access to objects, but they differ in their capabilities and safety considerations.
Pointers offer the flexibility of changing their target object and can be assigned null.
However, this flexibility introduces risks, such as dereferencing null pointers or creating dangling pointers.
References, on the other hand, cannot be null and are bound to valid objects upon creation, avoiding these risks.
Given their safer nature, references should be preferred over pointers unless the additional functionalities provided by pointers are necessary.

~~~~exercism/advanced
## Dynamic Memory Allocation and Null Pointers

In C++, `new` is used to dynamically allocate memory for objects on the heap during runtime.
It returns a pointer to the allocated memory address, allowing objects to have lifetimes not tied to a specific scope.
However, it's important to always pair `new` with `delete` to properly deallocate memory.
Dynamic memory allocation should be used cautiously to prevent common issues like memory leaks and accessing deallocated memory.

Pointers can also be set to a special value called a _null pointer_, which indicates that they do not point to a valid address.
Null pointers are commonly used to initialize pointers before assigning them to valid values.

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


In older code, you might encounter two alternatives to `nullptr`.
Firstly, the literal `0` is specifically interpreted as a null value for pointers, though it's the only scenario where an integral literal can be assigned to a pointer.
Secondly, the `preprocessor macro` `NULL`, inherited from C and defined in the `<cstddef>` header, is another representation of a null pointer, though its usage is less common in modern C++ code.
~~~~

[ariane-flight-v88]: https://en.wikipedia.org/wiki/Ariane_flight_V88
