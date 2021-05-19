#include "reverse_string.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("an_empty_string")
{
    REQUIRE("" == reverse_string::reverse_string(""));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("a_word")
{
    REQUIRE("tobor" == reverse_string::reverse_string("robot"));
}

TEST_CASE("a_capitalized_word")
{
    REQUIRE("nemaR" == reverse_string::reverse_string("Ramen"));
}

TEST_CASE("a_sentence_with_punctuation")
{
    REQUIRE("!yrgnuh m'I" == reverse_string::reverse_string("I'm hungry!"));
}

TEST_CASE("a_palindrome")
{
   REQUIRE("racecar" == reverse_string::reverse_string("racecar"));
}
#endif
