#pragma once

#include <vector>

namespace all_your_base {

std::vector<unsigned int> convert(unsigned int input_base,
                                  const std::vector<unsigned int>& input_digits,
                                  unsigned int output_base);
}
