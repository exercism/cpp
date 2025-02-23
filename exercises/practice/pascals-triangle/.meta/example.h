#if !defined(PASCALS_TRIANGLE_H)
#define PASCALS_TRIANGLE_H

#include <cstddef>
#include <vector>

namespace pascals_triangle {

using std::size_t;

std::vector<std::vector<int>> generate_rows(size_t n);

}  // namespace pascals_triangle

#endif
