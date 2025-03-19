#include <algorithm>
#include <stdexcept>

#include "hamming.h"

namespace hamming {

int compute(std::string const& lhs, std::string const& rhs) {
    if (rhs.length() != lhs.length()) {
        throw std::domain_error(
            "Hamming distance is not defined for different length strings.");
    }

    int count = 0;
    for (auto p = std::mismatch(lhs.begin(), lhs.end(), rhs.begin());
         p.first != lhs.end();
         p = std::mismatch(++p.first, lhs.end(), ++p.second)) {
        ++count;
    }
    return count;
}

}  // namespace hamming
