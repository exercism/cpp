#include "word_count.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <map>
#include "require_equal_containers.h"

using namespace std;

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

BOOST_AUTO_TEST_CASE(count_everything_just_once)
{
    const map<string, int> expected{{"all", 2}, {"the", 2}, {"kings", 2}, {"horses", 1}, {"and", 1}, {"men", 1}};
    const auto actual = word_count::words("all the kings horses and all the kings men");
    
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(handles_cramped_list)
{
    const map<string, int> expected{{"one", 1}, {"two", 1}, {"three", 1}};
    const auto actual = word_count::words("one,two,three");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(with_apostrophes)
{
    const map<string, int> expected{{"first", 1}, {"don't", 2}, {"laugh", 1}, {"then", 1}, {"cry", 1}};
    const auto actual = word_count::words("First: don't laugh. Then: don't cry.");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(with_free_standing_apostrophes)
{
    const map<string, int> expected{{ "go", 3 }};
    const auto actual = word_count::words("go ' Go '' GO");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(with_apostrophes_as_quotes)
{
    const map<string, int> expected{{"she", 1}, {"said", 1}, {"let's", 1}, {"meet", 1}, {"at", 1}, {"twelve", 1}, {"o'clock", 1}};
    const auto actual = word_count::words("She said, 'let's meet at twelve o'clock'");

    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}
#endif
