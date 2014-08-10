#include "triangle.h"
#include <stdexcept>

namespace triangle
{

namespace
{

bool triangle_equality(double a, double b, double c)
{
    return a < (b + c)
        && b < (a + c)
        && c < (a + b);
}

}

flavor kind(double a, double b, double c)
{
    if (a == 0 || b == 0 || c == 0) {
        throw std::domain_error("Zero triangle");
    }
    if (a < 0 || b < 0 || c < 0 || !triangle_equality(a, b, c)) {
        return illegal;
    }
    if (a == b && b == c) {
        return equilateral;
    }
    if (a == b || b == c || a == c) {
        return isosceles;
    }
    return scalene;
}

}
