#include <cmath>

#include "darts.h"

namespace darts {

int score(float x, float y) {
    auto distance = std::hypot(x, y);

    if (distance <= 1.0) {
        return 10;
    } else if (distance <= 5.0) {
        return 5;
    } else if (distance <= 10.0) {
        return 1;
    } else {
        return 0;
    }
}

}  // namespace darts
