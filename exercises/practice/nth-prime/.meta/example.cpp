#include <cmath>
#include <stdexcept>

#include "nth_prime.h"

namespace {
bool is_prime(int n) {
    for (int probe = static_cast<int>(std::sqrt(n)); probe > 1; --probe) {
        if (n % probe == 0) {
            return false;
        }
    }
    return true;
}
}  // namespace

int nth_prime::nth(int n) {
    if (n < 1) {
        throw std::domain_error("Out of range");
    }
    int candidate = 1;
    int count = 0;
    while (count < n) {
        if (is_prime(++candidate)) {
            ++count;
        }
    }
    return candidate;
}
