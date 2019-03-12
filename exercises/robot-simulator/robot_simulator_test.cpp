#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "robot_simulator.h"

// Robot-Simulator exercise test case data version 3.1.0

BOOST_AUTO_TEST_CASE(A_robots_is_created_with_a_position_and_a_direction)
{
    const robot_simulator::Robot r;

    const std::pair<int, int> expected_robot_position {0, 0};
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing {robot_simulator::Bearing::NORTH};
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(Negative_positions_are_allowed)
{
    const std::pair<int, int> robot_position {-1, -1};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::SOUTH};
    
    const robot_simulator::Robot r {robot_position, robot_bearing};

    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::SOUTH;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_north_to_east)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::NORTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.turn_right();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::EAST;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_east_to_south)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::EAST};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.turn_right();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position== actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::SOUTH;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_south_to_west)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::SOUTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.turn_right();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::WEST;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_west_to_north)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::WEST};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.turn_right();

    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::NORTH;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_north_to_west)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::NORTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.turn_left();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::WEST;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_west_to_south)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::WEST};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.turn_left();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::SOUTH;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_south_to_east)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::SOUTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.turn_left();

    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::EAST;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_east_to_north)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::EAST};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.turn_left();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::NORTH;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Increases_the_y_coordinate_by_one_when_facing_north)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::NORTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.advance();
    
    const std::pair<int, int> expected_robot_position {0, 1};
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position == actual_robot_position);
}

BOOST_AUTO_TEST_CASE(Decreases_the_y_coordinate_by_one_when_facing_south)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::SOUTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.advance();
    
    const std::pair<int, int> expected_robot_position {0, -1};
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position == actual_robot_position);
}

BOOST_AUTO_TEST_CASE(Increases_the_x_coordinate_by_one_when_facing_east)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::EAST};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.advance();
    
    const std::pair<int, int> expected_robot_position {1, 0};
    
    const std::pair<int, int> actual_robot_position = r.get_position();

    BOOST_CHECK(expected_robot_position == actual_robot_position);
}

BOOST_AUTO_TEST_CASE(Decreases_the_x_coordinate_by_one_when_facing_west)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::WEST};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.advance();

    const std::pair<int, int> expected_robot_position {-1, 0};
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
}

BOOST_AUTO_TEST_CASE(Instructions_to_move_east_and_north_from_readme)
{
    const std::pair<int, int> robot_position {7, 3};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::NORTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.execute_sequence("RAALAL");

    const std::pair<int, int> expected_robot_position {9, 4};
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::WEST;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Instructions_to_move_west_and_north)
{
    const std::pair<int, int> robot_position {0, 0};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::NORTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.execute_sequence("LAAARALA");

    const std::pair<int, int> expected_robot_position {-4, 1};
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::WEST;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Instructions_to_move_west_and_south)
{
    const std::pair<int, int> robot_position {2, -7};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::EAST};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.execute_sequence("RRAAAAALA");

    const std::pair<int, int> expected_robot_position {-3, -8};
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::SOUTH;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}

BOOST_AUTO_TEST_CASE(Instructions_to_move_east_and_north)
{
    const std::pair<int, int> robot_position {8, 4};
    
    const robot_simulator::Bearing robot_bearing {robot_simulator::Bearing::SOUTH};
    
    robot_simulator::Robot r {robot_position, robot_bearing};
    
    r.execute_sequence("LAAARRRALLLL");

    const std::pair<int, int> expected_robot_position {11, 5};
    
    const std::pair<int, int> actual_robot_position = r.get_position();
    
    BOOST_CHECK(expected_robot_position == actual_robot_position);
    
    const robot_simulator::Bearing expected_robot_bearing = robot_simulator::Bearing::NORTH;
    
    const robot_simulator::Bearing actual_robot_bearing = r.get_bearing();
    
    BOOST_CHECK(expected_robot_bearing == actual_robot_bearing);
}
#endif
