#include <cmath>

#include "prime_factors.h"

namespace prime_factors {

std::vector<long long> of(long long n) {
    std::vector<long long> factors;
    const long long end{static_cast<long long>(std::sqrt(n))};
    for (long long candidate{2}; candidate <= end; ++candidate) {
        while (n % candidate == 0) {
            factors.push_back(candidate);
            n /= candidate;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

}  // namespace prime_factors
