#include "binary.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(b1_is_decimal_1)
{
    BOOST_REQUIRE_EQUAL(1, binary::convert("1"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(b10_is_decimal_2)
{
    BOOST_REQUIRE_EQUAL(2, binary::convert("10"));
}

BOOST_AUTO_TEST_CASE(b11_is_decimal_3)
{
    BOOST_REQUIRE_EQUAL(3, binary::convert("11"));
}

BOOST_AUTO_TEST_CASE(b100_is_decimal_4)
{
    BOOST_REQUIRE_EQUAL(4, binary::convert("100"));
}

BOOST_AUTO_TEST_CASE(b1001_is_decimal_9)
{
    BOOST_REQUIRE_EQUAL(9, binary::convert("1001"));
}

BOOST_AUTO_TEST_CASE(b11010_is_decimal_26)
{
    BOOST_REQUIRE_EQUAL(26, binary::convert("11010"));
}

BOOST_AUTO_TEST_CASE(b10001101000_is_decimal_1128)
{
    BOOST_REQUIRE_EQUAL(1128, binary::convert("10001101000"));
}

BOOST_AUTO_TEST_CASE(carrot_is_decimal_0)
{
    BOOST_REQUIRE_EQUAL(0, binary::convert("convert"));
}

BOOST_AUTO_TEST_CASE(x1100101b_is_decimal_0)
{
    BOOST_REQUIRE_EQUAL(0, binary::convert("1100101b"));
}
#endif
