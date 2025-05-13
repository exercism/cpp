#include <array>
#include <limits>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "book_store.h"

namespace book_store {

constexpr std::array price_after_discount = {0, 800, 1520, 2160, 2560, 3000};

int dfs(const std::array<int, 5>& state,
        std::map<std::array<int, 5>, int>& memo) {
    auto it = memo.find(state);
    if (it != memo.end()) return it->second;

    const bool empty = std::all_of(state.cbegin(), state.cend(),
                                   [](auto state) { return state == 0; });
    if (empty) {
        memo[state] = 0;
        return 0;
    }

    int best = std::numeric_limits<int>::max();

    std::vector<int> idx;
    for (int i = 0; i < 5; ++i) {
        if (state[i] > 0) idx.push_back(i);
    }
    int n = static_cast<int>(idx.size());

    int maxMask = 1 << n;
    for (int mask = 1; mask < maxMask; ++mask) {
        std::array<int, 5> next = state;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                next[idx[i]]--;
                ++k;
            }
        }
        int cost = price_after_discount[k] + dfs(next, memo);
        if (cost < best) best = cost;
    }

    memo[state] = best;
    return best;
}

int total(const std::vector<int>& basket) {
    std::array<int, 5> counts{};
    for (int id : basket) {
        if (id < 1 || id > 5) {
            throw std::invalid_argument("book ID is out of range (1–5)");
        }
        counts[id - 1]++;
    }

    std::map<std::array<int, 5>, int> memo;
    return dfs(counts, memo);
}

}  // namespace book_store