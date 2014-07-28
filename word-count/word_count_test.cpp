#include <iostream>
#include <map>
#include <string>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "word_count.h"

using namespace std;

boost::test_tools::predicate_result compare_counts(
    map<string, int> const& expected,
    map<string, int> const& actual)
{
    boost::test_tools::predicate_result result{true};
    if (expected.size() != actual.size()) {
        result.message() << "\nMismatched sizes: " << expected.size() << " != " << actual.size();
        result = false;
    }
    if (expected != actual) {
        result.message() << "\nMismatched elements: ";
        for (auto const& item : expected) {
            result.message() << item.first << ',' << item.second << ' ';
        }
        result.message() << "!=";
        for (auto const& item : actual) {
            result.message() << ' ' << item.first << ',' << item.second;
        }
        result = false;
    }
    return result;
}

BOOST_AUTO_TEST_CASE(counts_one_word)
{
    map<string, int> const expected_counts{{ "word", 1 }};
    BOOST_REQUIRE(compare_counts(expected_counts, word_count::words("word")));
}

BOOST_AUTO_TEST_CASE(counts_one_of_each)
{
    map<string, int> expected_counts{{ "one", 1 }, { "of", 1 }, { "each", 1 }};
    BOOST_REQUIRE(compare_counts(expected_counts, word_count::words("one of each")));
}

BOOST_AUTO_TEST_CASE(counts_multiple_occurrences)
{
    map<string, int> expected_counts{{ "one", 1 }, { "fish", 4 }, { "two", 1 }, { "red", 1 }, { "blue", 1 }};
    BOOST_REQUIRE(compare_counts(expected_counts, word_count::words("one fish two fish red fish blue fish")));
}

BOOST_AUTO_TEST_CASE(ignores_punctuation)
{
    map<string, int> expected_counts{{ "car", 1 }, { "carpet", 1 }, { "as", 1 }, { "java", 1 }, { "javascript", 1 }};
    BOOST_REQUIRE(compare_counts(expected_counts, word_count::words("car : carpet as java : javascript!!&@$%^&")));
}

BOOST_AUTO_TEST_CASE(includes_numbers)
{
    map<string, int> expected_counts{{ "testing", 2 }, { "1", 1 }, { "2", 1 }};
    BOOST_REQUIRE(compare_counts(expected_counts, word_count::words("testing, 1, 2 testing")));
}

BOOST_AUTO_TEST_CASE(normalizes_case)
{
    map<string, int> expected_counts{{ "go", 3 }};
    BOOST_REQUIRE(compare_counts(expected_counts, word_count::words("go Go GO")));
}

BOOST_AUTO_TEST_CASE(counts_constructor)
{
    map<string, int> expected_counts{{ "constructor", 2 }};
    BOOST_REQUIRE(compare_counts(expected_counts, word_count::words("constructor Constructor")));
}

BOOST_AUTO_TEST_CASE(counts_multiline)
{
    map<string, int> expected_counts{{ "hello", 1 }, { "world", 1 }};
    BOOST_REQUIRE(compare_counts(expected_counts, word_count::words("hello\nworld")));
}
