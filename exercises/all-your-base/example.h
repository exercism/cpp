#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <vector>

namespace all_your_base {

std::vector<unsigned int> convert(unsigned int input_base,
                                  std::vector<unsigned int> const &input_digits,
                                  unsigned int output_base);
}

#endif /* ALL_YOUR_BASE_H */
