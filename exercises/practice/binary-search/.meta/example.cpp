#include <stdexcept>

#include "binary_search.h"

namespace binary_search {

bool is_value_in_range(std::vector<int> const& data, int const value) {
    return ((data.front() <= value) && (value <= data.back()));
}

size_t find(std::vector<int> const& data, int const value) {
    if (data.empty() || !is_value_in_range(data, value)) {
        throw std::domain_error("Value not in input vector!");
    }

    size_t lpos{0};
    size_t rpos{data.size() - 1};
    size_t mid{0};

    while (lpos <= rpos) {
        mid = lpos + ((rpos - lpos) / 2);

        if (data.at(mid) == value) {
            return mid;
        }

        if (value < data.at(mid)) {
            rpos = mid - 1;
        }

        if (value > data.at(mid)) {
            lpos = mid + 1;
        }
    }

    throw std::domain_error("Value not in input vector!");
}

}  // namespace binary_search
