#include "roman_numerals.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(one_yields_I)
{
    BOOST_REQUIRE_EQUAL("I", roman::convert(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(two_yields_II)
{
    BOOST_REQUIRE_EQUAL("II", roman::convert(2));
}

BOOST_AUTO_TEST_CASE(three_yields_III)
{
    BOOST_REQUIRE_EQUAL("III", roman::convert(3));
}

BOOST_AUTO_TEST_CASE(four_yields_IV)
{
    BOOST_REQUIRE_EQUAL("IV", roman::convert(4));
}

BOOST_AUTO_TEST_CASE(five_yields_V)
{
    BOOST_REQUIRE_EQUAL("V", roman::convert(5));
}

BOOST_AUTO_TEST_CASE(six_yields_VI)
{
    BOOST_REQUIRE_EQUAL("VI", roman::convert(6));
}

BOOST_AUTO_TEST_CASE(nine_yields_IX)
{
    BOOST_REQUIRE_EQUAL("IX", roman::convert(9));
}

BOOST_AUTO_TEST_CASE(twenty_seven_yields_XXVII)
{
    BOOST_REQUIRE_EQUAL("XXVII", roman::convert(27));
}

BOOST_AUTO_TEST_CASE(forty_eight_yields_XLVIII)
{
    BOOST_REQUIRE_EQUAL("XLVIII", roman::convert(48));
}

BOOST_AUTO_TEST_CASE(fifty_nine_yields_LIX)
{
    BOOST_REQUIRE_EQUAL("LIX", roman::convert(59));
}

BOOST_AUTO_TEST_CASE(ninety_three_yields_XCIII)
{
    BOOST_REQUIRE_EQUAL("XCIII", roman::convert(93));
}

BOOST_AUTO_TEST_CASE(one_hundred_forty_one_yields_CXLI)
{
    BOOST_REQUIRE_EQUAL("CXLI", roman::convert(141));
}

BOOST_AUTO_TEST_CASE(one_hundred_sixty_three_yields_CLXIII)
{
    BOOST_REQUIRE_EQUAL("CLXIII", roman::convert(163));
}

BOOST_AUTO_TEST_CASE(four_hundred_two_yields_CDII)
{
    BOOST_REQUIRE_EQUAL("CDII", roman::convert(402));
}

BOOST_AUTO_TEST_CASE(five_hundred_seventy_five_yields_DLXXV)
{
    BOOST_REQUIRE_EQUAL("DLXXV", roman::convert(575));
}

BOOST_AUTO_TEST_CASE(nine_hundred_eleven_yields_CMXI)
{
    BOOST_REQUIRE_EQUAL("CMXI", roman::convert(911));
}

BOOST_AUTO_TEST_CASE(one_thousand_twenty_four_yields_MXXIV)
{
    BOOST_REQUIRE_EQUAL("MXXIV", roman::convert(1024));
}

BOOST_AUTO_TEST_CASE(three_thousand_yields_MMM)
{
    BOOST_REQUIRE_EQUAL("MMM", roman::convert(3000));
}
#endif
