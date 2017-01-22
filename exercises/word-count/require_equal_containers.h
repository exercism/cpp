#if !defined(REQUIRE_EQUAL_CONTAINERS_H)
#define REQUIRE_EQUAL_CONTAINERS_H

#include <utility>
#include <vector>
#include <boost/version.hpp>

#if BOOST_VERSION >= 105900

namespace boost
{
namespace test_tools
{
namespace tt_detail
{

// teach Boost.Test how to print std::vector<T>
template <typename T>
inline std::ostream &operator<<(std::ostream &str, std::vector<T> const &items)
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
inline std::ostream &operator<<(std::ostream &str, std::pair<K, V> const& item)
{
    return str << '<' << item.first << ',' << item.second << '>';
}

} // namespace tt_detail
} // namespace test_tools
} // namespace boost

#else // BOOST_VERSION < 105900

namespace boost
{

// teach Boost.Test how to print std::vector to wrap_stringstream
template <typename T>
inline wrap_stringstream&
operator<<(wrap_stringstream& wrapped, std::vector<T> const& item)
{
    wrapped << '[';
    bool first = true;
    for (auto const& element : item) {
        wrapped << (!first ? "," : "") << element;
        first = false;
    }
    return wrapped << ']';
}

// teach Boost.Test how to print std::pair<K,V> to wrap_stringstream
template <typename K, typename V>
inline wrap_stringstream &operator<<(wrap_stringstream &str, std::pair<K, V> const& item)
{
    return str << '<' << item.first << ',' << item.second << '>';
}

namespace test_tools
{

// teach Boost.Test how to print std::pair with BOOST_REQUIRE_EQUAL
template<>
struct print_log_value<std::pair<int, int>>
{
    void operator()(std::ostream& ostr, std::pair<int, int> const& item)
    {
        ostr << '<' << item.first << ',' << item.second << '>';
    }
};

} // namespace test_tools
} // namespace boost

#endif // BOOST_VERSION

#define REQUIRE_EQUAL_CONTAINERS(left_, right_) \
    BOOST_REQUIRE_EQUAL_COLLECTIONS(left_.begin(), left_.end(), right_.begin(), right_.end())

#endif
