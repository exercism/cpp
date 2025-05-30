# Introduction

There are several variants of a general approach for solving Sieve.
A general approach is to keep track of composite numbers with a `vector` of `bool` values.

## General guidance

Something to consider is to keep the number of allocations and iterations at a minimum to get the best performance.

## Approach: `vector` of `bool`s

**sieve.h**
```cpp
#pragma once
#include <vector>
namespace sieve {
    std::vector<int> primes(int);
}  // namespace sieve
```

**sieve.cpp**
```cpp
#include "sieve.h"

namespace sieve {

	std::vector<int> primes(int limit) {
		std::vector<bool> composite(limit + 1, false);
		std::vector<int> primes;
		primes.reserve(limit / 2);

		for (long long number = 2; number <= limit; number++) {
			if (!composite[number]) {
				primes.emplace_back(number);
				for(long long idx = number * number; idx <= limit; idx +=number)
					composite[idx] = true;
			}
		}
		return primes;
	}
}  // namespace sieve
```

For more information, check the [`vector` of `bool`s approach][approach-vector-of-bools].

[approach-vector-of-bools]: https://exercism.org/tracks/cpp/exercises/sieve/approaches/vector-of-bools
