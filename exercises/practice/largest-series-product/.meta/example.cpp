#include <algorithm>
#include <numeric>
#include <regex>
#include <stdexcept>

#include "largest_series_product.h"
namespace largest_series_product {

int largest_product(const std::string& digits, int span) {
    if (span == 0) {
        return 1;
    }

    if (span < 0) {
        throw std::domain_error("span must not be negative");
    }

    if (digits.size() < static_cast<std::size_t>(span)) {
        throw std::domain_error("span must be smaller than string length");
    }

    if (!std::regex_match(digits, std::regex("\\d*"))) {
        throw std::domain_error("digits input must only contain digits");
    }

    int max = 0;
    for (size_t i = 0; i < digits.size() - span + 1; ++i) {
        auto start_iter = digits.begin() + i;
        auto end_iter = digits.begin() + i + span;
        auto val = std::accumulate(std::next(start_iter), end_iter,
                                   (*start_iter) - '0',
                                   [](int value, char current_val) {
                                       return value *= (current_val - '0');
                                   });
        max = std::max(max, val);
    }
    return max;
}
}  // namespace largest_series_product
