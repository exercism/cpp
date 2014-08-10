#include "space_age.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <cmath>

namespace
{
const double accuracy = 0.005;
}

BOOST_AUTO_TEST_CASE(age_in_seconds)
{
    const space_age::space_age age(1000000);

    BOOST_REQUIRE_EQUAL(1000000, age.seconds());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(age_in_earth_years)
{
    const space_age::space_age age(1000000000);

    BOOST_REQUIRE_LT(std::abs(31.69 - age.on_earth()), accuracy);
}

BOOST_AUTO_TEST_CASE(age_in_mercury_years)
{
    const space_age::space_age age(2134835688);

    BOOST_REQUIRE_LT(std::abs(67.65 - age.on_earth()), accuracy);
    BOOST_REQUIRE_LT(std::abs(280.88 - age.on_mercury()), accuracy);
}

BOOST_AUTO_TEST_CASE(age_in_venus_years)
{
    const space_age::space_age age(189839836);

    BOOST_REQUIRE_LT(std::abs(6.02- age.on_earth()), accuracy);
    BOOST_REQUIRE_LT(std::abs(9.78 - age.on_venus()), accuracy);
}

BOOST_AUTO_TEST_CASE(age_in_mars_years)
{
    const space_age::space_age age(2329871239);

    BOOST_REQUIRE_LT(std::abs(73.83 - age.on_earth()), accuracy);
    BOOST_REQUIRE_LT(std::abs(39.25 - age.on_mars()), accuracy);
}

BOOST_AUTO_TEST_CASE(age_in_jupiter_years)
{
    const space_age::space_age age(901876382);

    BOOST_REQUIRE_LT(std::abs(28.58 - age.on_earth()), accuracy);
    BOOST_REQUIRE_LT(std::abs(2.41 - age.on_jupiter()), accuracy);
}

BOOST_AUTO_TEST_CASE(age_in_saturn_years)
{
    const space_age::space_age age(3000000000);

    BOOST_REQUIRE_LT(std::abs(95.06 - age.on_earth()), accuracy);
    BOOST_REQUIRE_LT(std::abs(3.23 - age.on_saturn()), accuracy);
}

BOOST_AUTO_TEST_CASE(age_in_uranus_years)
{
    const space_age::space_age age(3210123456);

    BOOST_REQUIRE_LT(std::abs(101.72 - age.on_earth()), accuracy);
    BOOST_REQUIRE_LT(std::abs(1.21 - age.on_uranus()), accuracy);
}

BOOST_AUTO_TEST_CASE(age_in_neptune_year)
{
    const space_age::space_age age(8210123456);

    BOOST_REQUIRE_LT(std::abs(260.16 - age.on_earth()), accuracy);
    BOOST_REQUIRE_LT(std::abs(1.58 - age.on_neptune()), accuracy);
}
#endif
