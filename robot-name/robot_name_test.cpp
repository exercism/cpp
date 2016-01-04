#include "robot_name.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/regex.hpp>

using namespace std;

namespace
{
const boost::regex name_pattern{R"name(^[[:alpha:]]{2}\d{3}$)name"};
}

BOOST_AUTO_TEST_CASE(has_a_name)
{
    const robot_name::robot robot;

    BOOST_REQUIRE(boost::regex_match(robot.name(), name_pattern));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(name_is_the_same_each_time)
{
    const robot_name::robot robot;

    BOOST_REQUIRE_EQUAL(robot.name(), robot.name());
}

BOOST_AUTO_TEST_CASE(different_robots_have_different_names)
{
    const robot_name::robot robot_one;
    const robot_name::robot robot_two;

    BOOST_REQUIRE_NE(robot_one.name(), robot_two.name());
}

BOOST_AUTO_TEST_CASE(is_able_to_reset_name)
{
    robot_name::robot robot;
    const auto original_name = robot.name();

    robot.reset();

    BOOST_REQUIRE_NE(original_name, robot.name());
}

BOOST_AUTO_TEST_CASE(exhausting_digits_yields_different_names)
{
    robot_name::robot robot;
    auto last_name = robot.name();

    for (int i = 0; i < 1000; ++i) {
        robot.reset();
        BOOST_REQUIRE_NE(last_name, robot.name());
        BOOST_REQUIRE(boost::regex_match(robot.name(), name_pattern));
    }
}
#endif
