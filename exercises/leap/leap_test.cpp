#include "leap.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(a_known_leap_year)
{
    BOOST_REQUIRE(leap::is_leap_year(1996));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(any_old_year)
{
    BOOST_REQUIRE(!leap::is_leap_year(1997));
}

BOOST_AUTO_TEST_CASE(turn_of_the_20th_century)
{
    BOOST_REQUIRE(!leap::is_leap_year(1900));
}

BOOST_AUTO_TEST_CASE(turn_of_the_21st_century)
{
    BOOST_REQUIRE(leap::is_leap_year(2000));
}

BOOST_AUTO_TEST_CASE(turn_of_the_25th_century)
{
    BOOST_REQUIRE(leap::is_leap_year(2400));
}
#endif
