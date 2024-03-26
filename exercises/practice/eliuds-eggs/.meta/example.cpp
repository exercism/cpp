#include "eliuds_eggs.h"

namespace chicken_coop {
int positions_to_quantity(int display_value) {
    int counter{};
    while (display_value != 0) {
        if (display_value % 2) ++counter;
        display_value /= 2;
    }
    return counter;
}
}  // namespace chicken_coop
