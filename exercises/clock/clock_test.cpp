#include "clock.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(prints_the_hour)
{
    BOOST_REQUIRE_EQUAL("08:00", string(date_independent::clock::at(8)));
    BOOST_REQUIRE_EQUAL("09:00", string(date_independent::clock::at(9)));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(prints_past_the_hour)
{
    BOOST_REQUIRE_EQUAL("11:09", string(date_independent::clock::at(11, 9)));
    BOOST_REQUIRE_EQUAL("11:19", string(date_independent::clock::at(11, 19)));
}

BOOST_AUTO_TEST_CASE(can_add_minutes)
{
    const auto clock = date_independent::clock::at(10).plus(3);

    BOOST_REQUIRE_EQUAL("10:03", string(clock));
}

BOOST_AUTO_TEST_CASE(can_add_over_an_hour)
{
    const auto clock = date_independent::clock::at(10).plus(61);

    BOOST_REQUIRE_EQUAL("11:01", string(clock));
}

BOOST_AUTO_TEST_CASE(wraps_around_midnight)
{
    const auto clock = date_independent::clock::at(23, 59).plus(2);

    BOOST_REQUIRE_EQUAL("00:01", string(clock));
}

BOOST_AUTO_TEST_CASE(can_subtract_minutes)
{
    const auto clock = date_independent::clock::at(10, 3).minus(3);

    BOOST_REQUIRE_EQUAL("10:00", string(clock));
}

BOOST_AUTO_TEST_CASE(can_subtract_to_previous_hour)
{
    const auto clock = date_independent::clock::at(10, 3).minus(30);

    BOOST_REQUIRE_EQUAL("09:33", string(clock));
}

BOOST_AUTO_TEST_CASE(can_subtract_over_an_hour)
{
    const auto clock = date_independent::clock::at(10, 3).minus(70);

    BOOST_REQUIRE_EQUAL("08:53", string(clock));
}

BOOST_AUTO_TEST_CASE(can_know_if_its_equal_to_another_clock)
{
    const auto clock1 = date_independent::clock::at(10, 3);
    const auto clock2 = date_independent::clock::at(10, 3);

    BOOST_REQUIRE(clock1 == clock2);
}

BOOST_AUTO_TEST_CASE(can_know_if_its_not_equal_to_another_clock)
{
    const auto clock1 = date_independent::clock::at(10, 3);
    const auto clock2 = date_independent::clock::at(10, 4);

    BOOST_REQUIRE(clock1 != clock2);
}

BOOST_AUTO_TEST_CASE(wraps_around_midnight_backwards)
{
    const auto clock = date_independent::clock::at(0, 3).minus(4);

    BOOST_REQUIRE_EQUAL("23:59", string(clock));
}
#endif
