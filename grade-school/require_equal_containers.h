#if !defined(REQUIRE_EQUAL_CONTAINERS_H)
#define REQUIRE_EQUAL_CONTAINERS_H

#include <utility>
#include <vector>

namespace boost
{

#if BOOST_VERSION >= 105900
typedef std::ostream Stream;
namespace test_tools
{
namespace tt_detail
{
#else
typedef wrap_stringstream Stream;
#endif

// teach Boost.Test how to print std::vector<T>
template <typename T>
inline Stream &operator<<(Stream &str, std::vector<T> const &items)
{
    str << '[';
    bool first = true;
    for (auto const& element : items) {
        str << (!first ? "," : "") << element;
        first = false;
    }
    return str << ']';
}

// teach Boost.Test how to print std::pair<K,V>
template <typename K, typename V>
inline Stream &operator<<(Stream &str, std::pair<K, V> const& item)
{
    return str << '<' << item.first << ',' << item.second << '>';
}

#if BOOST_VERSION >= 105900
} // namespace tt_detail
} // namespace test_tools
#endif

} // namespace boost

#define REQUIRE_EQUAL_CONTAINERS(left_, right_) \
    BOOST_REQUIRE_EQUAL_COLLECTIONS(left_.begin(), left_.end(), right_.begin(), right_.end())

#endif
