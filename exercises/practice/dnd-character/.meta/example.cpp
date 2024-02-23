#include "dnd_character.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <numeric>

namespace dnd_character {
int modifier(int score) {
    return std::floor((static_cast<double>(score) - 10) / 2);
}

int dice_roll() { return 1 + std::rand() / ((RAND_MAX + 1u) / 6); }

int ability() {
    auto rolls = {dice_roll(), dice_roll(), dice_roll(), dice_roll()};
    auto discard = std::min(rolls);

    return std::accumulate(rolls.begin(), rolls.end(), 0) - discard;
}
}  // namespace dnd_character
