#include "sum_of_multiples.h"

namespace sum_of_multiples {

int to(std::initializer_list<int> const& multiples, int num) {
    int sum = 0;
    for (int i = 0; i < num; ++i) {
        for (const int multiple : multiples) {
            if (i % multiple == 0) {
                sum += i;
                break;
            }
        }
    }
    return sum;
}

}  // namespace sum_of_multiples
