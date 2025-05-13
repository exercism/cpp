#pragma once

namespace perfect_numbers {
enum class classification { deficient, perfect, abundant };

classification classify(int n);

}  // namespace perfect_numbers
