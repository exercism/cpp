#include "pascals_triangle.h"

namespace pascals_triangle {

std::vector<std::vector<int>> generate_rows(size_t n) {
    std::vector<std::vector<int>> res;

    for (size_t i = 0; i < n; i++) {
        std::vector<int> rowNum;

        int val = 1;
        for (size_t k = 0; k <= i; k++) {
            rowNum.push_back(val);
            val = val * (i - k) / (k + 1);
        }

        res.push_back(rowNum);
    }

    return res;
}

}  // namespace pascals_triangle
