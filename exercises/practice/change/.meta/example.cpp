#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

#include "change.h"

namespace change {

std::vector<int> find_fewest_coins(const std::vector<int>& coins, int target) {
    if (target < 0) {
        throw std::domain_error("target can't be negative");
    }
    if (target == 0) {
        return {};
    }
    if (coins.empty()) {
        throw std::domain_error("can't make target with given coins");
    }

    std::vector<int> dp(target + 1, std::numeric_limits<int>::max());
    std::vector<std::vector<int>> solution(target + 1);

    dp[0] = 0;

    for (int i = 1; i <= target; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != std::numeric_limits<int>::max()) {
                if (dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    solution[i] = solution[i - coin];
                    solution[i].push_back(coin);
                }
            }
        }
    }

    if (dp[target] == std::numeric_limits<int>::max()) {
        throw std::domain_error("can't make target with given coins");
    }

    std::sort(solution[target].begin(), solution[target].end());
    return solution[target];
}

}  // namespace change