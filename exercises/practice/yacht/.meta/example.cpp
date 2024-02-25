#include "yacht.h"

#include <algorithm>
#include <numeric>
#include <stdexcept>

namespace yacht {

int simple_scores(const std::array<int, 5>& dice, int target) {
    return std::accumulate(
        dice.begin(), dice.end(), 0,
        [target](int acc, int i) { return i == target ? acc + i : acc; });
}

bool is_yacht(const std::array<int, 5>& dice) {
    return std::all_of(dice.begin(), dice.end(),
                       [&dice](int i) { return i == dice[0]; });
}

bool is_full_house(const std::array<int, 5>& dice) {
    const int min{dice.at(0)};
    const int max{dice.at(4)};
    if (min == max) return false;
    std::array<int, 5> full_house{min, min, max, max, max};
    if (dice == full_house) return true;
    full_house[2] = min;
    return dice == full_house;
}

int four_of_a_kind_count(const std::array<int, 5>& dice) {
    const int min{dice.at(0)};
    const int max{dice.at(4)};
    int count_min{};
    int count_max{};
    for (auto element : dice) {
        if (element == min) ++count_min;
        if (element == max) ++count_max;
    }
    if (count_min >= 4) return min * 4;
    if (count_max >= 4) return max * 4;
    return 0;
}

int score(std::array<int, 5> dice, const std::string& category) {
    if (category == "yacht") {
        return is_yacht(dice) ? 50 : 0;
    }
    if (category == "ones") {
        return simple_scores(dice, 1);
    }
    if (category == "twos") {
        return simple_scores(dice, 2);
    }
    if (category == "threes") {
        return simple_scores(dice, 3);
    }
    if (category == "fours") {
        return simple_scores(dice, 4);
    }
    if (category == "fives") {
        return simple_scores(dice, 5);
    }
    if (category == "sixes") {
        return simple_scores(dice, 6);
    }
    // the rest of the categories can make use of a sorted array:
    std::sort(dice.begin(), dice.end());
    if (category == "four of a kind") {
        return four_of_a_kind_count(dice);
    }
    if (category == "little straight") {
        std::array<int, 5> little_straight{1, 2, 3, 4, 5};
        return dice == little_straight ? 30 : 0;
    }
    if (category == "big straight") {
        std::array<int, 5> big_straight{2, 3, 4, 5, 6};
        return dice == big_straight ? 30 : 0;
    }
    // the last two categories need the sum of the dice:
    int total = std::reduce(dice.begin(), dice.end());
    if (category == "full house") {
        return is_full_house(dice) ? total : 0;
    }
    if (category == "choice") {
        return total;
    }
    throw std::invalid_argument("unknown category: " + category);
}
}  // namespace yacht
