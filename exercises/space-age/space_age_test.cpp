#include "space_age.h"
#include "test/catch.hpp"

TEST_CASE("age_in_seconds")
{
    const space_age::space_age age(1000000);

    REQUIRE(age.seconds() == 1000000);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
namespace
{
const double accuracy = 0.005;
}

TEST_CASE("age_in_earth_years")
{
    const space_age::space_age age(1000000000);

    // 'Approx' is a helper from the test suite for comparing floating point
    // numbers.
    REQUIRE(age.on_earth() == Approx(31.69).margin(accuracy));
}

TEST_CASE("age_in_mercury_years")
{
    const space_age::space_age age(2134835688);

    REQUIRE(age.on_earth() == Approx(67.65).margin(accuracy));
    REQUIRE(age.on_mercury() == Approx(280.88).margin(accuracy));
}

TEST_CASE("age_in_venus_years")
{
    const space_age::space_age age(189839836);

    REQUIRE(age.on_earth() == Approx(6.02).margin(accuracy));
    REQUIRE(age.on_venus() == Approx(9.78).margin(accuracy));
}

TEST_CASE("age_in_mars_years")
{
    const space_age::space_age age(2329871239);

    REQUIRE(age.on_earth() == Approx(73.83).margin(accuracy));
    REQUIRE(age.on_mars() == Approx(39.25).margin(accuracy));
}

TEST_CASE("age_in_jupiter_years")
{
    const space_age::space_age age(901876382);

    REQUIRE(age.on_earth() == Approx(28.58).margin(accuracy));
    REQUIRE(age.on_jupiter() == Approx(2.41).margin(accuracy));
}

TEST_CASE("age_in_saturn_years")
{
    const space_age::space_age age(3000000000);

    REQUIRE(age.on_earth() == Approx(95.06).margin(accuracy));
    REQUIRE(age.on_saturn() == Approx(3.23).margin(accuracy));
}

TEST_CASE("age_in_uranus_years")
{
    const space_age::space_age age(3210123456);

    REQUIRE(age.on_earth() == Approx(101.72).margin(accuracy));
    REQUIRE(age.on_uranus() == Approx(1.21).margin(accuracy));
}

TEST_CASE("age_in_neptune_year")
{
    const space_age::space_age age(8210123456);

    REQUIRE(age.on_earth() == Approx(260.16).margin(accuracy));
    REQUIRE(age.on_neptune() == Approx(1.58).margin(accuracy));
}
#endif
