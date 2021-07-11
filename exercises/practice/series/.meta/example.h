#if !defined(SERIES_H)
#define SERIES_H

#include <string>
#include <vector>

namespace series
{

std::vector<int> digits(std::string const& sequence);

std::vector<std::vector<int>> slice(std::string const& sequence, int span);

}

#endif
