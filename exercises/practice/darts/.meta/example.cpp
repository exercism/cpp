#include "example.h"
#include <cmath>

namespace darts {

    int score(float x, float y) {
        auto dart_location = sqrt(x*x + y*y);

        if (dart_location <= 1.0) {
            return 10;
        } else if (dart_location <= 5.0) {
            return 5;
        } else if (dart_location <= 10.0) {
            return 1;
        } else {
            return 0;
        }
    }

} //darts