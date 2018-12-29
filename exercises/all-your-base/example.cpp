#include "all_your_base.h"
#include <vector>

namespace all_your_base {

std::vector<unsigned int> convert(unsigned int input_base,
                                  const std::vector<unsigned int>& input_digits,
                                  unsigned int output_base) {
    std::vector<unsigned int> b;
    unsigned int value = 0;
    if (input_digits.empty())
        return {};
    if (!input_digits.empty() && input_digits.front() == 0)
        return {};
    if (input_base == 0 || output_base <= 1)
        return {};
    for (unsigned int d : input_digits) {
        if (d >= input_base)
            return {};
        value = value * input_base + d;
    }
    while (value != 0) {
        unsigned int new_digit = value % output_base;
        value = (unsigned int)(value / output_base);
        b.insert(b.begin(), new_digit);
    }
    return b;
}

}
