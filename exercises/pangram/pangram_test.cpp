#include "pangram.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sentence_empty)
{
    BOOST_REQUIRE(!pangram::is_pangram(""));
}

#ifdef EXERCISM_RUN_ALL_TESTS
BOOST_AUTO_TEST_CASE(pangram_with_only_lower_case)
{
    BOOST_REQUIRE(pangram::is_pangram("the quick brown fox jumps over the lazy dog"));
}

BOOST_AUTO_TEST_CASE(missing_character_x)
{
    BOOST_REQUIRE(!pangram::is_pangram("a quick movement of the enemy will jeopardize five gunboats"));
}

BOOST_AUTO_TEST_CASE(another_missing_x)
{
    BOOST_REQUIRE(!pangram::is_pangram("the quick brown fish jumps over the lazy dog"));
}

BOOST_AUTO_TEST_CASE(pangram_with_underscores)
{
    BOOST_REQUIRE(pangram::is_pangram("the_quick_brown_fox_jumps_over_the_lazy_dog"));
}

BOOST_AUTO_TEST_CASE(pangram_with_numbers)
{
    BOOST_REQUIRE(pangram::is_pangram("the 1 quick brown fox jumps over the 2 lazy dogs"));
}

BOOST_AUTO_TEST_CASE(missing_letters_replaced_with_numbers)
{
    BOOST_REQUIRE(!pangram::is_pangram("7h3 qu1ck brown fox jumps ov3r 7h3 lazy dog"));
}

BOOST_AUTO_TEST_CASE(pangram_with_mixed_case_and_punctuation)
{
    BOOST_REQUIRE(pangram::is_pangram("\"Five quacking Zephyrs jolt my wax bed.\""));
}

BOOST_AUTO_TEST_CASE(upper_and_lower_should_not_be_counted_seperately)
{
    BOOST_REQUIRE(!pangram::is_pangram("the quick brown fox jumps over with lazy FX"));
}
#endif
