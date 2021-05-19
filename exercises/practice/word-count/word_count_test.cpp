#include "word_count.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <map>

using namespace std;

// Word-count exercise test case data version 1.4.0

TEST_CASE("counts_one_word")
{
    const map<string, int> expected{{"word", 1}};

    const auto actual = word_count::words("word");

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("counts_one_of_each")
{
    const map<string, int> expected{{"one", 1}, {"of", 1}, {"each", 1}};

    const auto actual = word_count::words("one of each");

    REQUIRE(expected == actual);
}

TEST_CASE("counts_multiple_occurrences")
{
    const map<string, int> expected{{"one", 1}, {"fish", 4}, {"two", 1}, {"red", 1}, {"blue", 1}};

    const auto actual = word_count::words("one fish two fish red fish blue fish");

    REQUIRE(expected == actual);
}

TEST_CASE("handles_cramped_list")
{
    const map<string, int> expected{{"one", 1}, {"two", 1}, {"three", 1}};

    const auto actual = word_count::words("one,two,three");

    REQUIRE(expected == actual);
}

TEST_CASE("handles_expanded_list")
{
    const map<string, int> expected{{"one", 1}, {"two", 1}, {"three", 1}};

    const auto actual = word_count::words("one,\ntwo,\nthree");

    REQUIRE(expected == actual);
}

TEST_CASE("ignores_punctuation")
{
    const map<string, int> expected{{"car", 1}, {"carpet", 1}, {"as", 1}, {"java", 1}, {"javascript", 1}};

    const auto actual = word_count::words("car: carpet as java: javascript!!&@$%^&");

    REQUIRE(expected == actual);
}

TEST_CASE("includes_numbers")
{
    const map<string, int> expected{{"testing", 2}, {"1", 1}, {"2", 1}};

    const auto actual = word_count::words("testing, 1, 2 testing");

    REQUIRE(expected == actual);
}

TEST_CASE("normalizes_case")
{
    const map<string, int> expected{{"go", 3}, {"stop", 2}};

    const auto actual = word_count::words("go Go GO Stop stop");

    REQUIRE(expected == actual);
}

TEST_CASE("with_apostrophes")
{
    const map<string, int> expected{{"first", 1}, {"don't", 2}, {"laugh", 1}, {"then", 1}, {"cry", 1}};

    const auto actual = word_count::words("First: don't laugh. Then: don't cry.");

    REQUIRE(expected == actual);
}

TEST_CASE("with_quotations")
{
    const map<string, int> expected{{"joe", 1}, {"can't", 1}, {"tell", 1}, {"between", 1}, {"large", 2}, {"and", 1}};

    const auto actual = word_count::words("Joe can't tell between 'large' and large.");

    REQUIRE(expected == actual);
}

TEST_CASE("substrings_from_the_beginning")
{
    const map<string, int> expected{{ "joe", 1 }, { "can't", 1 }, { "tell", 1 }, { "between", 1 }, { "app", 1 }, { "apple", 1 }, { "and", 1 }, { "a", 1 }};

    const auto actual = word_count::words("Joe can't tell between app, apple and a.");

    REQUIRE(expected == actual);
}

TEST_CASE("multiple_spaces_not_detected_as_a_word")
{
    const map<string, int> expected{{ "multiple", 1 }, { "whitespaces", 1 }};

    const auto actual = word_count::words(" multiple   whitespaces");

    REQUIRE(expected == actual);
}

TEST_CASE("alternating_word_separators_not_detected_as_a_word")
{
    const map<string, int> expected{{ "one", 1 }, { "two", 1 }, { "three", 1 }};

    const auto actual = word_count::words(",\n,one,\n ,two \n 'three'");

    REQUIRE(expected == actual);
}

#endif
