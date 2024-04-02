#include <cmath>

#include "prime_factors.h"

namespace prime_factors {

std::vector<int> of(int n) {
    std::vector<int> factors;
    const int end{static_cast<int>(std::sqrt(n))};
    for (int candidate{2}; candidate <= end; ++candidate) {
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
