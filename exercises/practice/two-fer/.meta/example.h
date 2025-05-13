#pragma once

#include <string>

namespace two_fer {
inline std::string two_fer(const std::string& name = "you") {
    return "One for " + name + ", one for me.";
}
}  // namespace two_fer
