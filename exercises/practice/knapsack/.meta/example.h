#pragma once

#include <vector>

namespace knapsack {

struct Item {
    int weight;
    int value;
};

int maximum_value(int maximum_weight, const std::vector<Item>& items);

}  // namespace knapsack
