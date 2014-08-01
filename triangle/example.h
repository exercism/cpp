#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <string>

class triangle
{
public:
    triangle(double a, double b, double c);

    std::string kind() const;

private:
    const std::string kind_;
};

#endif
