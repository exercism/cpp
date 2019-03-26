#include "leap.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(not_divisible_by_4)
{
    BOOST_REQUIRE(!leap::is_leap_year(2015));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(divisible_by_2_not_divisible_by_4)
{
    BOOST_REQUIRE(!leap::is_leap_year(1970));
}

BOOST_AUTO_TEST_CASE(divisible_by_4_not_divisible_by_100)
{
    BOOST_REQUIRE(leap::is_leap_year(1996));
}

BOOST_AUTO_TEST_CASE(divisible_by_100_not_divisible_by_400)
{
    BOOST_REQUIRE(!leap::is_leap_year(2100));
}

BOOST_AUTO_TEST_CASE(divisible_by_400)
{
    BOOST_REQUIRE(leap::is_leap_year(2000));
}

BOOST_AUTO_TEST_CASE(divisible_by_200_not_divisible_by_400)
{
    BOOST_REQUIRE(!leap::is_leap_year(1800));
}
#endif
