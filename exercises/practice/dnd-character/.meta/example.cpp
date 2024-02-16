#include "dnd_character.h"

#include <cmath>
#include <cstdlib>

namespace dnd_character {
int modifier(int score) {
    return std::floor((static_cast<double>(score) - 10) / 2);
}

int dice_roll() { return 1 + std::rand() / ((RAND_MAX + 1u) / 6); }

// Throwing three dice is not the same as selecting a random number between 3
// and 18.
int ability() { return dice_roll() + dice_roll() + dice_roll(); }

}  // namespace dnd_character
