# Introduction

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


~~~~exercism/advanced
## Weak Pointers

`std::weak_ptr` is a companion class to `std::shared_ptr` that provides a non-owning "weak" reference to an object managed by a shared pointer.

```cpp
// Creating a shared pointer
auto your_account = std::make_shared<std::string>("secret_subscription_password");
// Creating a shared pointer that shares ownership
auto your_flatmates_account = your_account;

// Creating a weak pointer from the shared pointer
auto your_flatmates_boyfriends_account = your_flatmates_account;
// if your_account and your_flatmates_account are deleted, there is no more reference to the shared pointer.
// your_flatmates_boyfriends_account will be a null pointer and cannot use the associated object any longer.
```

Weak pointers are useful in scenarios where cyclic references need to be broken to prevent memory leaks.
`std::weak_ptr` was designed to address the issue of cyclic ownership, also known as circular references, that can occur when using `std::shared_ptr`.
In a cyclic ownership scenario, two or more `std::shared_ptr` objects are referencing each other, creating a cycle where none of the objects can be deleted because they have strong references to each other, leading to memory leaks.
`std::weak_ptr` provides a solution to this problem by allowing weak references to shared objects without contributing to their reference count.
This means that it can observe and access the shared object but doesn't prevent it from being deleted.
~~~~

## Usage advice

Use smart pointers by default: `std::unique_ptr` for exclusive ownership and `std::shared_ptr` for shared ownership.
Reserve raw pointers for non-owning references or when interfacing with legacy code.
In most cases, `std::unique_ptr` is sufficient for exclusive ownership, as it offers lightweight memory management without the overhead of reference counting.
`std::shared_ptr` should be used sparingly, as it introduces overhead and complexity unless true shared ownership is needed.
`std::weak_ptr` is specialized for breaking cyclic dependencies or observing shared objects, but it's not commonly used.
