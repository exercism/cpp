#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>

namespace robot_name
{

class robot
{
public:
    robot();

    std::string const &name() const { return name_; }

    void reset();

private:
    std::string name_;
};

}

#endif
