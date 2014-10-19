#include "say.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(zero)
{
    BOOST_REQUIRE_EQUAL("zero", say::in_english(0ULL));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(one)
{
    BOOST_REQUIRE_EQUAL("one", say::in_english(1ULL));
}

BOOST_AUTO_TEST_CASE(fourteen)
{
    BOOST_REQUIRE_EQUAL("fourteen", say::in_english(14ULL));
}

BOOST_AUTO_TEST_CASE(twenty)
{
    BOOST_REQUIRE_EQUAL("twenty", say::in_english(20ULL));
}

BOOST_AUTO_TEST_CASE(twenty_two)
{
    BOOST_REQUIRE_EQUAL("twenty-two", say::in_english(22ULL));
}

BOOST_AUTO_TEST_CASE(sixty_nine)
{
    BOOST_REQUIRE_EQUAL("sixty-nine", say::in_english(69ULL));
}

BOOST_AUTO_TEST_CASE(one_hundred)
{
    BOOST_REQUIRE_EQUAL("one hundred", say::in_english(100ULL));
}

BOOST_AUTO_TEST_CASE(one_hundred_twenty_three)
{
    BOOST_REQUIRE_EQUAL("one hundred twenty-three", say::in_english(123ULL));
}

BOOST_AUTO_TEST_CASE(one_thousand)
{
    BOOST_REQUIRE_EQUAL("one thousand", say::in_english(1000ULL));
}

BOOST_AUTO_TEST_CASE(one_thousand_two_hundred_thirty_four)
{
    BOOST_REQUIRE_EQUAL("one thousand two hundred thirty-four", say::in_english(1234ULL));
}

BOOST_AUTO_TEST_CASE(one_million)
{
    BOOST_REQUIRE_EQUAL("one million", say::in_english(1000ULL*1000ULL));
}

BOOST_AUTO_TEST_CASE(one_million_two)
{
    BOOST_REQUIRE_EQUAL("one million two", say::in_english(1000ULL*1000ULL + 2ULL));
}

BOOST_AUTO_TEST_CASE(one_million_two_thousand_three_hundred_forty_five)
{
    BOOST_REQUIRE_EQUAL("one million two thousand three hundred forty-five", say::in_english(1002345ULL));
}

BOOST_AUTO_TEST_CASE(one_billion)
{
    BOOST_REQUIRE_EQUAL("one billion", say::in_english(1000ULL*1000ULL*1000ULL));
}

BOOST_AUTO_TEST_CASE(a_really_big_number)
{
    BOOST_REQUIRE_EQUAL(
            "nine hundred eighty-seven billion"
            " six hundred fifty-four million"
            " three hundred twenty-one thousand"
            " one hundred twenty-three",
        say::in_english(987654321123ULL));
}

BOOST_AUTO_TEST_CASE(raises_an_error_below_zero)
{
    BOOST_REQUIRE_THROW(say::in_english(-1), std::domain_error);
}

BOOST_AUTO_TEST_CASE(raises_an_error_for_one_trillion)
{
    BOOST_REQUIRE_THROW(say::in_english(1000ULL*1000ULL*1000ULL*1000ULL), std::domain_error);
}
#endif
