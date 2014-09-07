#include "hexadecimal.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(hex_1_is_decimal_1)
{
    BOOST_REQUIRE_EQUAL(0x1, hexadecimal::convert("1"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(hex_c_is_decimal_12)
{
    BOOST_REQUIRE_EQUAL(0xc, hexadecimal::convert("c"));
}

BOOST_AUTO_TEST_CASE(hex_10_is_decimal_16)
{
    BOOST_REQUIRE_EQUAL(0x10, hexadecimal::convert("10"));
}

BOOST_AUTO_TEST_CASE(hex_af_is_decimal_175)
{
    BOOST_REQUIRE_EQUAL(0xaf, hexadecimal::convert("af"));
}

BOOST_AUTO_TEST_CASE(hex_100_is_decimal_256)
{
    BOOST_REQUIRE_EQUAL(0x100, hexadecimal::convert("100"));
}

BOOST_AUTO_TEST_CASE(hex_19ace_is_decimal_105166)
{
    BOOST_REQUIRE_EQUAL(0x19ace, hexadecimal::convert("19ace"));
}

BOOST_AUTO_TEST_CASE(invalid_hex_is_decimal_0)
{
    BOOST_REQUIRE_EQUAL(0, hexadecimal::convert("carrot"));
}

BOOST_AUTO_TEST_CASE(black)
{
    BOOST_REQUIRE_EQUAL(0x000000, hexadecimal::convert("000000"));
}

BOOST_AUTO_TEST_CASE(white)
{
    BOOST_REQUIRE_EQUAL(0xffffff, hexadecimal::convert("ffffff"));
}

BOOST_AUTO_TEST_CASE(yellow)
{
    BOOST_REQUIRE_EQUAL(0xffff00, hexadecimal::convert("ffff00"));
}
#endif
