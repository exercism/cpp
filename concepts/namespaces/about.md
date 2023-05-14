# About

[comment]: # (Copy content from introduction, once it is agreed upoon)

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