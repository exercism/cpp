#include "acronym.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("basic")
{
    const string actual = acronym::acronym("Portable Network Graphics");

    const string expected{"PNG"};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("lowercase_words")
{
    const string actual = acronym::acronym("Ruby on Rails");

    const string expected{"ROR"};

    REQUIRE(expected == actual);
}

TEST_CASE("punctuation")
{
    const string actual = acronym::acronym("First In, First Out");

    const string expected{"FIFO"};

    REQUIRE(expected == actual);
}

TEST_CASE("all_caps_word")
{
    const string actual = acronym::acronym("GNU Image Manipulation Program");

    const string expected{"GIMP"};

    REQUIRE(expected == actual);
}

TEST_CASE("punctuation_without_whitespace")
{
    const string actual = acronym::acronym("Complementary metal-oxide semiconductor");

    const string expected{"CMOS"};

    REQUIRE(expected == actual);
}

TEST_CASE("very_long_abbreviation")
{
    const string actual = acronym::acronym("Rolling On The Floor Laughing So Hard That My Dogs Came Over And Licked Me");

    const string expected{"ROTFLSHTMDCOALM"};

    REQUIRE(expected == actual);
}

TEST_CASE("consecutive_delimiters")
{
    const string actual = acronym::acronym("Something - I made up from thin air");

    const string expected{"SIMUFTA"};

    REQUIRE(expected == actual);
}

TEST_CASE("apostrophes")
{
    const string actual = acronym::acronym("Halley's Comet");

    const string expected{"HC"};

    REQUIRE(expected == actual);
}

TEST_CASE("underscore_emphasis")
{
    const string actual = acronym::acronym("The Road _Not_ Taken");

    const string expected{"TRNT"};

    REQUIRE(expected == actual);
}
#endif
