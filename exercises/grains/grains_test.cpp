#include "grains.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(square_1)
{
    BOOST_REQUIRE_EQUAL(1ULL, grains::square(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(square_2)
{
    BOOST_REQUIRE_EQUAL(2ULL, grains::square(2));
}

BOOST_AUTO_TEST_CASE(square_3)
{
    BOOST_REQUIRE_EQUAL(4ULL, grains::square(3));
}

BOOST_AUTO_TEST_CASE(square_4)
{
    BOOST_REQUIRE_EQUAL(8ULL, grains::square(4));
}

BOOST_AUTO_TEST_CASE(square_16)
{
    BOOST_REQUIRE_EQUAL(32768ULL, grains::square(16));
}

BOOST_AUTO_TEST_CASE(square_32)
{
    BOOST_REQUIRE_EQUAL(2147483648ULL, grains::square(32));
}

BOOST_AUTO_TEST_CASE(square_64)
{
    BOOST_REQUIRE_EQUAL(9223372036854775808ULL, grains::square(64));
}

BOOST_AUTO_TEST_CASE(total)
{
    BOOST_REQUIRE_EQUAL(18446744073709551615ULL, grains::total());
}
#endif
