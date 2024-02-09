#include "space_age.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

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

    REQUIRE_THAT(age.on_earth(), Catch::Matchers::WithinAbs(31.69, accuracy));
}

TEST_CASE("age_in_mercury_years")
{
    const space_age::space_age age(2134835688);

    REQUIRE_THAT(age.on_earth(), Catch::Matchers::WithinAbs(67.65, accuracy));
    REQUIRE_THAT(age.on_mercury(), Catch::Matchers::WithinAbs(280.88, accuracy));
}

TEST_CASE("age_in_venus_years")
{
    const space_age::space_age age(189839836);

    REQUIRE_THAT(age.on_earth(), Catch::Matchers::WithinAbs(6.02, accuracy));
    REQUIRE_THAT(age.on_venus(), Catch::Matchers::WithinAbs(9.78, accuracy));
}

TEST_CASE("age_in_mars_years")
{
    const space_age::space_age age(2329871239);

    REQUIRE_THAT(age.on_earth(), Catch::Matchers::WithinAbs(73.83, accuracy));
    REQUIRE_THAT(age.on_mars(), Catch::Matchers::WithinAbs(39.25, accuracy));
}

TEST_CASE("age_in_jupiter_years")
{
    const space_age::space_age age(901876382);

    REQUIRE_THAT(age.on_earth(), Catch::Matchers::WithinAbs(28.58, accuracy));
    REQUIRE_THAT(age.on_jupiter(), Catch::Matchers::WithinAbs(2.41, accuracy));
}

TEST_CASE("age_in_saturn_years")
{
    const space_age::space_age age(3000000000);

    REQUIRE_THAT(age.on_earth(), Catch::Matchers::WithinAbs(95.06, accuracy));
    REQUIRE_THAT(age.on_saturn(), Catch::Matchers::WithinAbs(3.23, accuracy));
}

TEST_CASE("age_in_uranus_years")
{
    const space_age::space_age age(3210123456);

    REQUIRE_THAT(age.on_earth(), Catch::Matchers::WithinAbs(101.72, accuracy));
    REQUIRE_THAT(age.on_uranus(), Catch::Matchers::WithinAbs(1.21, accuracy));
}

TEST_CASE("age_in_neptune_year")
{
    const space_age::space_age age(8210123456);

    REQUIRE_THAT(age.on_earth(), Catch::Matchers::WithinAbs(260.16, accuracy));
    REQUIRE_THAT(age.on_neptune(), Catch::Matchers::WithinAbs(1.58, accuracy));
}
#endif
