#include "word_count.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <map>

using namespace std;

namespace boost
{

// teach Boost.Test how to print std::pair
template <typename K, typename V>
inline wrap_stringstream&
operator<<(wrap_stringstream& wrapped, std::pair<const K, V> const& item)
{
    return wrapped << '<' << item.first << ',' << item.second << '>';
}

}

#define REQUIRE_EQUAL_CONTAINERS(left_, right_) \
    BOOST_REQUIRE_EQUAL_COLLECTIONS(left_.begin(), left_.end(), right_.begin(), right_.end())

BOOST_AUTO_TEST_CASE(counts_one_word)
{
    const map<string, int> expected{{"word", 1}};

    const auto actual = word_count::words("word");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(counts_one_of_each)
{
    const map<string, int> expected{{"one", 1}, {"of", 1}, {"each", 1}};

    const auto actual = word_count::words("one of each");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(counts_multiple_occurrences)
{
    const map<string, int> expected{{"one", 1}, {"fish", 4}, {"two", 1}, {"red", 1}, {"blue", 1}};

    const auto actual = word_count::words("one fish two fish red fish blue fish");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(ignores_punctuation)
{
    const map<string, int> expected{{"car", 1}, {"carpet", 1}, {"as", 1}, {"java", 1}, {"javascript", 1}};

    const auto actual = word_count::words("car : carpet as java : javascript!!&@$%^&");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(includes_numbers)
{
    const map<string, int> expected{{"testing", 2}, {"1", 1}, {"2", 1}};

    const auto actual = word_count::words("testing, 1, 2 testing");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(normalizes_case)
{
    const map<string, int> expected{{"go", 3}};

    const auto actual = word_count::words("go Go GO");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(counts_constructor)
{
    const map<string, int> expected{{"constructor", 2}};

    const auto actual = word_count::words("constructor Constructor");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(counts_multiline)
{
    const map<string, int> expected{{"hello", 1}, {"world", 1}};

    const auto actual = word_count::words("hello\nworld");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}
#endif
