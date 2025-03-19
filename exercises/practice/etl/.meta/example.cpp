#include <cctype>

#include "etl.h"

using namespace std;

namespace etl {

map<char, int> transform(map<int, vector<char>> const& old) {
    map<char, int> result;
    for (auto const& item : old) {
        for (char c : item.second) {
            result[tolower(c)] = item.first;
        }
    }
    return result;
}

}  // namespace etl
