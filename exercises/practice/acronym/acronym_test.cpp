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

TEST_CASE("all_caps_words")
{
    const string actual = acronym::acronym("PHP: Hypertext Preprocessor");

    const string expected{"PHP"};

    REQUIRE(expected == actual);
}

TEST_CASE("non_acronym_all_caps_word")
{
    const string actual = acronym::acronym("GNU Image Manipulation Program");

    const string expected{"GIMP"};

    REQUIRE(expected == actual);
}

TEST_CASE("hyphenated")
{
    const string actual = acronym::acronym("Complementary metal-oxide semiconductor");

    const string expected{"CMOS"};

    REQUIRE(expected == actual);
}

#endif
