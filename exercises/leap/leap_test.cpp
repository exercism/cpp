#include "leap.h"
#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

TEST_CASE("a_known_leap_year")
{
    REQUIRE(leap::is_leap_year(1996));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("any_old_year")
{
    REQUIRE(!leap::is_leap_year(1997));
}

TEST_CASE("turn_of_the_20th_century")
{
    REQUIRE(!leap::is_leap_year(1900));
}

TEST_CASE("turn_of_the_21st_century")
{
    REQUIRE(leap::is_leap_year(2000));
}

TEST_CASE("turn_of_the_25th_century")
{
    REQUIRE(leap::is_leap_year(2400));
}
#endif
