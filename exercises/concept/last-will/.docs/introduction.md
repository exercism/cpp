# Introduction

## Namespaces

An important method for code organization is the use of namespaces.
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
