#if !defined(SERIES_H)
#define SERIES_H

#include <string>
#include <vector>

namespace series {

std::string digits(const std::string &input);

std::vector<std::string> slice(const std::string &input, size_t window);

}  // namespace series

#endif
