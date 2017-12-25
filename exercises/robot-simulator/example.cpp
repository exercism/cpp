#include "robot_simulator.h"

robot_simulator::Robot::Robot() : robot_position(std::make_pair(0, 0)), robot_bearing(robot_simulator::Bearing::NORTH) {}

robot_simulator::Robot::Robot(std::pair<int, int> p, robot_simulator::Bearing b) : robot_position(p), robot_bearing(b) {}

robot_simulator::Bearing robot_simulator::Robot::get_bearing() const
{
    return robot_bearing;
}

std::pair<int, int> robot_simulator::Robot::get_position() const
{
    return robot_position;
}

void robot_simulator::Robot::turn_right()
{
    switch(robot_bearing)
    {
        case robot_simulator::Bearing::NORTH:
            robot_bearing = robot_simulator::Bearing::EAST;
            break;
        case robot_simulator::Bearing::EAST:
            robot_bearing = robot_simulator::Bearing::SOUTH;
            break;
        case robot_simulator::Bearing::SOUTH:
            robot_bearing = robot_simulator::Bearing::WEST;
            break;
        case robot_simulator::Bearing::WEST:
            robot_bearing = robot_simulator::Bearing::NORTH;
    }
}

void robot_simulator::Robot::turn_left()
{
    switch(robot_bearing)
    {
        case robot_simulator::Bearing::NORTH:
            robot_bearing = robot_simulator::Bearing::WEST;
            break;
        case robot_simulator::Bearing::WEST:
            robot_bearing = robot_simulator::Bearing::SOUTH;
            break;
        case robot_simulator::Bearing::SOUTH:
            robot_bearing = robot_simulator::Bearing::EAST;
            break;
        case robot_simulator::Bearing::EAST:
            robot_bearing = robot_simulator::Bearing::NORTH;
    }
}

void robot_simulator::Robot::advance()
{
    switch(robot_bearing)
    {
        case robot_simulator::Bearing::NORTH:
            robot_position.second++;
            break;
        case robot_simulator::Bearing::WEST:
            robot_position.first--;
            break;
        case robot_simulator::Bearing::SOUTH:
            robot_position.second--;
            break;
        case robot_simulator::Bearing::EAST:
            robot_position.first++;
    } 
}

void robot_simulator::Robot::execute_sequence(std::string sequence)
{
    for(char c : sequence)
    {
        switch(c)
        {
            case 'L':
                turn_left();
                break;
            case 'R':
                turn_right();
                break;
            case 'A':
                advance();
        }
    }
}
