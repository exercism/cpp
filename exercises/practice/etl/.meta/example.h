#pragma once

#include <map>
#include <vector>

namespace etl {

std::map<char, int> transform(std::map<int, std::vector<char>> const& old);

}
