#include "scrabble_score.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("scores_an_empty_word_as_zero")
{
    REQUIRE(0 == scrabble_score::score(""));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("scores_a_very_short_word")
{
    REQUIRE(1 == scrabble_score::score("a"));
}

TEST_CASE("scores_the_word_by_the_number_of_letters")
{
    REQUIRE(6 == scrabble_score::score("street"));
}

TEST_CASE("scores_more_complicated_words_with_more")
{
    REQUIRE(22 == scrabble_score::score("quirky"));
}

TEST_CASE("scores_case_insensitive_words")
{
    REQUIRE(41 == scrabble_score::score("OXYPHENBUTAZONE"));
}

TEST_CASE("scores_z_word")
{
    REQUIRE(12 == scrabble_score::score("zoo"));
}
#endif
