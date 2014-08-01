#include "triangle.h"

namespace
{

bool triangle_equality(double a, double b, double c)
{
    return a < (b + c)
        && b < (a + c)
        && c < (a + b);
}

std::string determine_triangle_kind(double a, double b, double c)
{
    if (a == 0 || b == 0 || c == 0) {
        return "";
    }
    if (a < 0 || b < 0 || c < 0 || !triangle_equality(a, b, c)) {
        return "illegal";
    }
    if (a == b && b == c) {
        return "equilateral";
    }
    if (a == b || b == c || a == c) {
        return "isosceles";
    }
    return "scalene";
}

}

triangle::triangle(double a, double b, double c)
    : kind_(determine_triangle_kind(a, b, c))
{
}

std::string triangle::kind() const
{
    if (kind_.empty()) {
        throw std::domain_error("Zero triangle");
    }
    return kind_;
}
