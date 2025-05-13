# `vector` of `bool`s

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
    
		for (int number = 2; number <= limit; number++) {
			if (!composite[number]) {
				primes.emplace_back(number);
				for(int idx = number * number; idx <= limit; idx +=number)
					composite[idx] = true;
			}
		}
		return primes;
	}
}  // namespace sieve
```

This approach starts by defining a [`vector`][vector] to keep track of the composite numbers, with the elements initialized to `false`.
The output `vector` is also defined, and then the [`reserve`][reserve] method is used to set its capacity to half of the limit, since
at least half of the numbers will be even and so not prime.

Since values less than `2` are not prime, the iteration of the outer [`for` loop][for] begins at `2`.
If the number being iterated is not a composite number, then the [`emplace_back`][emplace-back] method is used to append the number being iterated
to the output `vector`.

Since any number evenly divisible by that prime is not prime, the inner `for` loop iterates from the prime times itself, setting each of the
elements at that index to `true` for being a composite number.

After the outer loop is done, the `vector` of primes is returned.

[size]: https://en.cppreference.com/w/cpp/container/vector/size
[vector]: https://en.cppreference.com/w/cpp/container/vector
[reserve]: https://en.cppreference.com/w/cpp/container/vector/reserve
[emplace-back]: https://en.cppreference.com/w/cpp/container/vector/emplace_back
[for]: https://en.cppreference.com/w/cpp/language/for
[if]: https://en.cppreference.com/w/cpp/language/if
[domain-error]: https://en.cppreference.com/w/cpp/error/domain_error
