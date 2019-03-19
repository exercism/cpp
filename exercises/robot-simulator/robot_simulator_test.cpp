#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "robot_simulator.h"

using robot_simulator::Robot;
using robot_simulator::Bearing;

// Robot-Simulator exercise test case data version 3.1.0

BOOST_AUTO_TEST_CASE(A_robots_is_created_with_a_position_and_a_direction)
{
    const Robot r;

    const std::pair<int, int> expected_robot_position{0, 0};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::NORTH == r.get_bearing());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(Negative_positions_are_allowed)
{
    const std::pair<int, int> robot_position{-1, -1};
    const Bearing robot_bearing {Bearing::SOUTH};
    const Robot r{robot_position, robot_bearing};

    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::SOUTH == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_north_to_east)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::NORTH};
    Robot r{robot_position, robot_bearing};
    
    r.turn_right();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::EAST == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_east_to_south)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::EAST};
    Robot r{robot_position, robot_bearing};
    
    r.turn_right();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position== r.get_position());
    BOOST_CHECK(Bearing::SOUTH == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_south_to_west)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::SOUTH};
    Robot r{robot_position, robot_bearing};
    
    r.turn_right();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::WEST == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_west_to_north)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::WEST};
    Robot r{robot_position, robot_bearing};
    
    r.turn_right();

    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::NORTH == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_north_to_west)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::NORTH};
    Robot r{robot_position, robot_bearing};
    
    r.turn_left();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::WEST == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_west_to_south)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::WEST};
    Robot r{robot_position, robot_bearing};
    
    r.turn_left();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::SOUTH == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_south_to_east)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::SOUTH};
    Robot r{robot_position, robot_bearing};
    
    r.turn_left();

    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::EAST == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Changes_the_direction_from_east_to_north)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::EAST};
    Robot r{robot_position, robot_bearing};
    
    r.turn_left();
    
    const std::pair<int, int> expected_robot_position = robot_position;
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::NORTH == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Increases_the_y_coordinate_by_one_when_facing_north)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::NORTH};
    Robot r{robot_position, robot_bearing};
    
    r.advance();
    
    const std::pair<int, int> expected_robot_position{0, 1};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::NORTH == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Decreases_the_y_coordinate_by_one_when_facing_south)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::SOUTH};
    Robot r{robot_position, robot_bearing};
    
    r.advance();
    
    const std::pair<int, int> expected_robot_position{0, -1};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::SOUTH == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Increases_the_x_coordinate_by_one_when_facing_east)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::EAST};
    Robot r{robot_position, robot_bearing};
    
    r.advance();
    
    const std::pair<int, int> expected_robot_position{1, 0};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::EAST == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Decreases_the_x_coordinate_by_one_when_facing_west)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::WEST};
    Robot r{robot_position, robot_bearing};
    
    r.advance();

    const std::pair<int, int> expected_robot_position{-1, 0};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::WEST == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Instructions_to_move_east_and_north_from_readme)
{
    const std::pair<int, int> robot_position{7, 3};
    const Bearing robot_bearing {Bearing::NORTH};
    Robot r{robot_position, robot_bearing};
    
    r.execute_sequence("RAALAL");

    const std::pair<int, int> expected_robot_position{9, 4};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::WEST == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Instructions_to_move_west_and_north)
{
    const std::pair<int, int> robot_position{0, 0};
    const Bearing robot_bearing {Bearing::NORTH};
    Robot r{robot_position, robot_bearing};
    
    r.execute_sequence("LAAARALA");

    const std::pair<int, int> expected_robot_position{-4, 1};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::WEST == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Instructions_to_move_west_and_south)
{
    const std::pair<int, int> robot_position{2, -7};
    const Bearing robot_bearing {Bearing::EAST};
    Robot r{robot_position, robot_bearing};
    
    r.execute_sequence("RRAAAAALA");

    const std::pair<int, int> expected_robot_position{-3, -8};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::SOUTH == r.get_bearing());
}

BOOST_AUTO_TEST_CASE(Instructions_to_move_east_and_north)
{
    const std::pair<int, int> robot_position{8, 4};
    const Bearing robot_bearing {Bearing::SOUTH};
    Robot r{robot_position, robot_bearing};
    
    r.execute_sequence("LAAARRRALLLL");

    const std::pair<int, int> expected_robot_position{11, 5};
    BOOST_CHECK(expected_robot_position == r.get_position());
    BOOST_CHECK(Bearing::NORTH == r.get_bearing());
}
#endif
