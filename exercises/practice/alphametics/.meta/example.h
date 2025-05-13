#pragma once

#include <map>
#include <optional>
#include <string>

namespace alphametics {

std::optional<std::map<char, int>> solve(const std::string& puzzle);

}  // namespace alphametics