#ifndef ALPHAMETICS_H
#define ALPHAMETICS_H

#include <optional>
#include <map>
#include <string>

namespace alphametics {

    std::optional<std::map<char,int>> solve(const std::string& puzzle);

} // namespace alphametics

#endif // ALPHAMETICS_H