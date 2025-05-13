#include "robot_simulator.h"

namespace robot_simulator {

Robot::Robot()
    : robot_position(std::make_pair(0, 0)), robot_bearing(Bearing::NORTH) {}

Robot::Robot(std::pair<int, int> p, Bearing b)
    : robot_position(p), robot_bearing(b) {}

Bearing Robot::get_bearing() const { return robot_bearing; }

std::pair<int, int> Robot::get_position() const { return robot_position; }

void Robot::turn_right() {
    switch (robot_bearing) {
        case Bearing::NORTH: {
            robot_bearing = Bearing::EAST;
            break;
        }
        case Bearing::EAST: {
            robot_bearing = Bearing::SOUTH;
            break;
        }
        case Bearing::SOUTH: {
            robot_bearing = Bearing::WEST;
            break;
        }
        case Bearing::WEST:
            robot_bearing = Bearing::NORTH;
    }
}

void Robot::turn_left() {
    switch (robot_bearing) {
        case Bearing::NORTH: {
            robot_bearing = Bearing::WEST;
            break;
        }
        case Bearing::WEST: {
            robot_bearing = Bearing::SOUTH;
            break;
        }
        case Bearing::SOUTH: {
            robot_bearing = Bearing::EAST;
            break;
        }
        case Bearing::EAST: {
            robot_bearing = Bearing::NORTH;
        }
    }
}

void Robot::advance() {
    switch (robot_bearing) {
        case Bearing::NORTH: {
            robot_position.second++;
            break;
        }
        case Bearing::WEST: {
            robot_position.first--;
            break;
        }
        case Bearing::SOUTH: {
            robot_position.second--;
            break;
        }
        case Bearing::EAST: {
            robot_position.first++;
        }
    }
}

void Robot::execute_sequence(std::string const& sequence) {
    for (char c : sequence) {
        switch (c) {
            case 'L': {
                turn_left();
                break;
            }
            case 'R': {
                turn_right();
                break;
            }
            case 'A': {
                advance();
            }
        }
    }
}

}  // namespace robot_simulator
