#include "scrabble_score.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(scores_an_empty_word_as_zero)
{
    BOOST_REQUIRE_EQUAL(0, scrabble_score::score(""));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(scores_a_very_short_word)
{
    BOOST_REQUIRE_EQUAL(1, scrabble_score::score("a"));
}

BOOST_AUTO_TEST_CASE(scores_the_word_by_the_number_of_letters)
{
    BOOST_REQUIRE_EQUAL(6, scrabble_score::score("street"));
}

BOOST_AUTO_TEST_CASE(scores_more_complicated_words_with_more)
{
    BOOST_REQUIRE_EQUAL(22, scrabble_score::score("quirky"));
}

BOOST_AUTO_TEST_CASE(scores_case_insensitive_words)
{
    BOOST_REQUIRE_EQUAL(20, scrabble_score::score("MULTIBILLIONAIRE"));
}

BOOST_AUTO_TEST_CASE(scores_z_word)
{
    BOOST_REQUIRE_EQUAL(12, scrabble_score::score("zoo"));
}
#endif
