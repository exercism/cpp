#pragma once

#include <string>

namespace zebra_puzzle {

struct Solution {
    std::string drinksWater;
    std::string ownsZebra;
};

Solution solve();

}  // namespace zebra_puzzle
