#include <cmath>
#include <stdexcept>

#include "perfect_numbers.h"

using namespace std;

constexpr int aliquot(const int n) {
    if (n == 1) {
        return 0;
    }
    int acc = 1;
    for (int i = 2; i <= sqrt(n); ++i) {
        if ((n % i) == 0) {
            acc += i;
            int complement = n / i;
            if (complement != i) {
                acc += complement;
            }
        }
    }
    return acc;
}

namespace perfect_numbers {
classification classify(int n) {
    if (n <= 0) {
        throw std::domain_error("Input must be a positive integer");
    }
    int aliq = aliquot(n);
    if (aliq < n) {
        return classification::deficient;
    }
    if (aliq > n) {
        return classification::abundant;
    }
    return classification::perfect;
}
}  // namespace perfect_numbers