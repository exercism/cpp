#pragma once

#include <cstddef>
#include <vector>

namespace pascals_triangle {

using std::size_t;

std::vector<std::vector<int>> generate_rows(size_t n);

}  // namespace pascals_triangle
