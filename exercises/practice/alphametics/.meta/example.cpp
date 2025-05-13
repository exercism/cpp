#include <algorithm>
#include <functional>
#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

#include "alphametics.h"

namespace alphametics {

std::optional<std::map<char, int>> solve(const std::string& puzzle) {
    auto sep = puzzle.find("==");
    if (sep == std::string::npos) return std::nullopt;
    std::string left = puzzle.substr(0, sep);
    std::string right = puzzle.substr(sep + 2);

    auto trim = [&](std::string& s) {
        auto b = s.find_first_not_of(' ');
        auto e = s.find_last_not_of(' ');
        s = (b == std::string::npos) ? std::string() : s.substr(b, e - b + 1);
    };
    trim(left);
    trim(right);

    std::vector<std::string> addends;
    std::istringstream iss(left);
    for (std::string part; std::getline(iss, part, '+');) {
        trim(part);
        addends.push_back(part);
    }
    trim(right);
    std::string result = right;

    std::vector<char> letters;
    std::unordered_set<char> seen, leading;
    auto collect = [&](const std::string& w) {
        if (w.size() > 1) leading.insert(w.front());
        for (char c : w) {
            if (seen.insert(c).second) letters.push_back(c);
        }
    };
    for (auto& w : addends) collect(w);
    collect(result);
    if (letters.size() > 10) return std::nullopt;

    int n = letters.size();
    std::map<char, int> idx;
    for (int i = 0; i < n; ++i) idx[letters[i]] = i;
    std::vector<long long> weight(n, 0);

    for (auto& w : addends) {
        long long mult = 1;
        for (int i = (int)w.size() - 1; i >= 0; --i) {
            weight[idx[w[i]]] += mult;
            mult *= 10;
        }
    }
    {
        long long mult = 1;
        for (int i = (int)result.size() - 1; i >= 0; --i) {
            weight[idx[result[i]]] -= mult;
            mult *= 10;
        }
    }

    std::vector<bool> used(10, false);
    std::map<char, int> assign;
    bool found = false;
    std::map<char, int> solution;
    std::function<void(int, long long)> dfs = [&](int pos, long long sum) {
        if (found) return;
        if (pos == n) {
            if (sum == 0) {
                found = true;
                solution = assign;
            }
            return;
        }
        char c = letters[pos];
        for (int d = 0; d < 10 && !found; ++d) {
            if (used[d] || (d == 0 && leading.count(c))) continue;
            used[d] = true;
            assign[c] = d;
            dfs(pos + 1, sum + weight[pos] * d);
            used[d] = false;
        }
    };

    dfs(0, 0);
    if (found) return solution;
    return std::nullopt;
}

}  // namespace alphametics
