#include <algorithm>
#include <list>
#include <numeric>

#include "sieve.h"

namespace sieve {

std::vector<int> primes(int n) {
    std::vector<int> result;
    std::list<int> candidates(n - 1);
    std::iota(candidates.begin(), candidates.end(), 2);
    while (!candidates.empty()) {
        const int next = candidates.front();
        candidates.pop_front();
        result.push_back(next);
        candidates.remove_if([next](int n) { return n % next == 0; });
    }
    return result;
}

}  // namespace sieve
