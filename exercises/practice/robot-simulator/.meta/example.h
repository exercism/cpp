#pragma once
#include <string>
#include <utility>

namespace robot_simulator {

enum class Bearing { NORTH, WEST, SOUTH, EAST };

class Robot {
   public:
    Robot();
    Robot(std::pair<int, int>, Bearing);
    Robot(Robot const&) = delete;
    Robot& operator=(Robot const&) = delete;
    Robot(Robot const&&) = delete;
    Robot& operator=(Robot const&&) = delete;
    ~Robot() = default;
    void turn_left();
    void turn_right();
    void advance();
    void execute_sequence(std::string const&);
    std::pair<int, int> get_position() const;
    Bearing get_bearing() const;

   private:
    std::pair<int, int> robot_position;
    Bearing robot_bearing;
};

}  // namespace robot_simulator
