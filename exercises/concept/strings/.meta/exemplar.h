#if !defined(STRINGS_H_)
#define STRINGS_H_

#include <string>

namespace log_line {
    std::string message(const std::string& line);
    std::string log_level(const std::string& line);
    std::string reformat(const std::string& line);
} // namespace log_line

#endif  // !STRINGS_H_
