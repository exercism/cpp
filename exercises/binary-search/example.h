#if !defined(BINARY_SEARCH_H)
#define BINARY_SEARCH_H

#include <vector>
#include <cstddef>

namespace binary_search 
{

using std::size_t;

size_t find(std::vector<int> const&, int const);

} // namespace binary_search

#endif // BINARY_SEARCH_H
