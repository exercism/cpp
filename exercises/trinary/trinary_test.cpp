#include "trinary.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(_1_yields_decimal_1)
{
    BOOST_REQUIRE_EQUAL(1, trinary::to_decimal("1"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(_2_yields_decimal_2)
{
    BOOST_REQUIRE_EQUAL(2, trinary::to_decimal("2"));
}

BOOST_AUTO_TEST_CASE(_10_yields_decimal_3)
{
    BOOST_REQUIRE_EQUAL(3, trinary::to_decimal("10"));
}

BOOST_AUTO_TEST_CASE(_11_yields_decimal_4)
{
    BOOST_REQUIRE_EQUAL(4, trinary::to_decimal("11"));
}

BOOST_AUTO_TEST_CASE(_100_yields_decimal_9)
{
    BOOST_REQUIRE_EQUAL(9, trinary::to_decimal("100"));
}

BOOST_AUTO_TEST_CASE(_112_yields_decimal_14)
{
    BOOST_REQUIRE_EQUAL(14, trinary::to_decimal("112"));
}

BOOST_AUTO_TEST_CASE(_222_yields_decimal_26)
{
    BOOST_REQUIRE_EQUAL(26, trinary::to_decimal("222"));
}

BOOST_AUTO_TEST_CASE(_1122000120_yields_decimal_32091)
{
    BOOST_REQUIRE_EQUAL(32091, trinary::to_decimal("1122000120"));
}

BOOST_AUTO_TEST_CASE(invalid_yields_decimal_0)
{
    BOOST_REQUIRE_EQUAL(0, trinary::to_decimal("carrot"));
}
#endif
