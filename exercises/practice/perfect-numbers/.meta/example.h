#if !defined(PERFECT_NUMBERS_H)
#define PERFECT_NUMBERS_H

namespace perfect_numbers {
enum class classification { deficient, perfect, abundant };

classification classify(int n);

}  // namespace perfect_numbers

#endif
