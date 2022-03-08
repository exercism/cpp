#include "example.h"
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <regex>
namespace largest_series_product {

    int largest_product(const std::string& series, int size) {
        if (size == 0) {
            return 1;
        }

        if(size < 0) {
            throw std::domain_error("span must not be negative");
        }

        if (series.size() < static_cast<std::size_t>(size)) {
            throw std::domain_error("span must be smaller than string length");
        }

        if (!std::regex_match(series, std::regex("\\d*"))) {
            throw std::domain_error("digits input must only contain digits");
        }

        int max = 0;
        for(size_t i = 0; i < series.size() - size + 1; ++i) {
            auto start_iter = series.begin() + i;
            auto end_iter = series.begin() + i + size;
            auto val = std::accumulate(std::next(start_iter), end_iter, (*start_iter) - '0', [](int value, char current_val){
                return value *= (current_val - '0');
            });
            max = std::max(max, val);
        }
        return max;
    }
} // largest_series_product
