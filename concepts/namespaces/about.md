# About

An important method for code organization are namespaces.
Two functions might have a naming collision, which can be resolved by putting them in different namespaces.
Namespaces can be nested, which might help to structure big code bases.
Access to the namespaces is done via the scope-resolution operator `::`.

The example below shows the use of two different `foo` functions.
They are used together by prefixing their respective namespaces.

```cpp
namespace my_ns {
    int foo() {
        return 44;
    }
    namespace my_inner_ns {
        int baz() {
            return 90;
        }
    }
}
namespace my_other_ns {
    int foo() {
        return -2;
    }
}
int myresult{my_ns::foo() + my_other_ns::foo() * my_ns::my_inner_ns::baz()};
```

~~~~exercism/advanced
Deeply nested namespaces might be too verbose.
It is possible to remove the verbosity with a namespace import via `using`.
This moves all names into the global namespace.
To keep some differentiation aliases might be useful.

```cpp
int my_other_result{my_ns::my_inner_ns::baz()};

using namespace my_ns::my_inner_ns; // importing the complete namespace
int also_other_result{baz()};

namespace m = my_ns; // setting an alias
namespace o = my_other_ns;

int also_my_result{m::foo() + o::foo() * m::my_inner_ns::baz()};
```
~~~~
