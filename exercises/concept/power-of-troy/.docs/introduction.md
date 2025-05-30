# Introduction

## The `auto` Keyword in C++

In C++, the `auto` keyword is a powerful feature introduced in C++11, used to declare variables with an inferred data type.
The compiler deduces the type of the variable based on its initializer, which can make code more readable and easier to maintain.

## Example Usage

Consider the following example where `auto` is used to declare variables:

```cpp
auto dragon_population{3};          // dragon_population is deduced as an integer
auto westeros{7.7777};              // westeros is deduced as a double
auto wedding_location{"The Twins"}; // wedding_location is deduced as a const char*, not std::string
```

In each case, the type of the variable is inferred from the value it is initialized with.

## Type Inference

The `auto` keyword helps by writing more concise and readable code by reducing the verbosity of explicit types.

```cpp
const std::vector<std::string> pigeon_pie{"flour", "butter", "pigeon", "salt"};
auto purple_wedding_pie{pigeon_pie};
purple_wedding_pie.emplace_back("the strangler");
```

In this loop, `auto` deduces the type of `purple_wedding_pie` as `std::vector<std::string>`, avoiding the need to explicitly specify the type again.

## Compatibility

The `auto` keyword is compatible with various C++ constructs making it a versatile tool in modern C++ programming.

```cpp
auto& element{array[0]};           // reference to an element
const auto object{otherObject};    // const type version of otherObject's type
auto* ptr{&x};                     // pointer to x with the same type as x, but as a pointer.
```

In later concept we will often see the `auto` keyword with lambda expressions, range-based for-loops, and iterators.

## Smart Pointers

Smart pointers are a modern C++ feature designed to provide automatic memory management, helping to prevent memory leaks and dangling pointers commonly associated with raw pointers.
They act as wrappers around raw pointers, adding additional functionality such as automatic memory deallocation when the pointer is no longer needed.

## General Syntax

Smart pointers are typically implemented as class templates in the C++ standard library.
The two most commonly used smart pointers are `std::unique_ptr` and `std::shared_ptr`.

## Unique Pointers

`std::unique_ptr` is a smart pointer that owns the object exclusively.
It ensures that at any given time, only one `std::unique_ptr` object owns the resource.
When the owning `std::unique_ptr` is destroyed or reset, it automatically destructs the objects and releases its memory.

```cpp
#include <memory>
// Declaring and defining a unique pointer
auto rightful_king_of_england = std::make_unique<std::string>("Excalibur");

// Unique pointers cannot be copied or assigned
auto mordred = rightful_king_of_england; // Error: Cannot copy a unique_ptr
```

## Advantages of `std::make_unique()`

When creating a `std::unique_ptr`, it's preferable to use `std::make_unique()` instead of directly using `new` to allocate memory.
`std::make_unique()` provides several advantages:
1. **Exception Safety**: `std::make_unique()` guarantees exception safety.
  If an exception is thrown during the construction of the object, memory will be automatically deallocated, preventing memory leaks.
2. **Clarity**: Using `std::make_unique()` makes code clearer and more concise.
  It eliminates the need to explicitly specify the type being allocated, as the template arguments are deduced automatically.
3. **Optimization Opportunities**: Compilers have the opportunity to optimize `std::make_unique()` more effectively than manually allocating memory with `new`, potentially resulting in improved performance.
4. **Avoiding Misuse**: Deleting the underlying resource is possible, when the `std::unique_ptr` is constructed manually.
  That would lead to undefined behavior, when the `std::unique_ptr` tries to delete it at its end of scope.

## Shared Pointers

`std::shared_ptr` is a smart pointer that allows multiple `std::shared_ptr` objects to share ownership of the same resource.
It keeps track of how many shared pointers are referencing the resource, and deallocates the memory only when the last shared pointer owning the resource goes out of scope or is reset.

```cpp
// Declaring and defining a shared pointer to a dynamically allocated string
auto martian_congressional_republic = std::make_shared<std::string>("protomolecule");

// Creating more shared pointer that shares ownership
auto outer_planets_alliance = martian_congressional_republic;
auto united_nations = martian_congressional_republic;
```

~~~~exercism/caution
In C++17 and below, using `std::shared_ptr` with arrays via `std::make_shared<T[]>` is not directly supported.
While it's possible to allocate arrays with `std::make_shared<T[]>`, creating shared pointers directly from them may lead to undefined behavior due to differences in memory management between single objects and arrays.
Instead, consider using `std::vector` or custom deletion functions to manage arrays with shared pointers effectively.
Always ensure compatibility with your compiler and standard library implementation when dealing with array allocations and shared pointers in C++17.
~~~~

## Advantages of `std::make_shared()`

Similar to `std::make_unique()`, `std::make_shared()` offers benefits such as improved memory efficiency, exception safety, and readability.
It combines memory allocation for the control block and the managed object into a single operation, enhancing efficiency and reducing the risk of memory leaks.
Additionally, automatic deduction of template arguments simplifies code and enhances readability.
Using `std::make_shared()` promotes cleaner, safer, and more efficient code when working with `std::shared_ptr` objects in C++.

## Usage advice

Use smart pointers by default: `std::unique_ptr` for exclusive ownership and `std::shared_ptr` for shared ownership.
Reserve raw pointers for non-owning references or when interfacing with legacy code.
In most cases, `std::unique_ptr` is sufficient for exclusive ownership, as it offers lightweight memory management without the overhead of reference counting.
`std::shared_ptr` should be used sparingly, as it introduces overhead and complexity unless true shared ownership is needed.
