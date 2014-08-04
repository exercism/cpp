#include "etl.h"
#include <cctype>

using namespace std;

namespace etl
{

extern map<char, int> etl::transform(map<int, vector<char>> const& old)
{
    map<char, int> result;
    for (auto const& item : old) {
        for (char c : item.second) {
            result[tolower(c)] = item.first;
        }
    }
    return result;
}

}
