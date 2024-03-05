#if !defined(SPIRAL_MATRIX_H)
#define SPIRAL_MATRIX_H

#include <cstdint>
#include <vector>

namespace spiral_matrix {

[[nodiscard]] std::vector<std::vector<uint32_t>> spiral_matrix(uint32_t size);

}  // namespace spiral_matrix

#endif  // SPIRAL_MATRIX_H
