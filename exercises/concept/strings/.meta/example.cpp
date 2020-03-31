#include "strings.h"

namespace log_line {
    std::string message(const std::string& line) {
        return line.substr(line.find(':') + 2);
    }

    std::string log_level(const std::string& line) {
        return line.substr(1, line.find(']') - 1);
    }

    std::string reformat(const std::string& line) {
        return message(line) + " (" + log_level(line) + ')';
    }
} // namespace log_line
