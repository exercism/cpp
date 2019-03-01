#include "reverse_string.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(an_empty_string)
{
    BOOST_REQUIRE_EQUAL("", reverse_string::reverse_string(""));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(a_word)
{
    BOOST_REQUIRE_EQUAL("tobor", reverse_string::reverse_string("robot"));
}

BOOST_AUTO_TEST_CASE(a_capitalized_word)
{
    BOOST_REQUIRE_EQUAL("nemaR", reverse_string::reverse_string("Ramen"));
}

BOOST_AUTO_TEST_CASE(a_sentence_with_punctuation)
{
    BOOST_REQUIRE_EQUAL("!yrgnuh m'I", reverse_string::reverse_string("I'm hungry!"));
}

BOOST_AUTO_TEST_CASE(a_palindrome)
{
   BOOST_REQUIRE_EQUAL("racecar", reverse_string::reverse_string("racecar"));
}
#endif
