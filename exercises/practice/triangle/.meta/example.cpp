#include <stdexcept>

#include "triangle.h"

namespace triangle {

namespace {

bool triangle_equality(double a, double b, double c) {
    return a < (b + c) && b < (a + c) && c < (a + b);
}

}  // namespace

flavor kind(double a, double b, double c) {
    if (a == 0 || b == 0 || c == 0) {
        throw std::domain_error("Zero triangle");
    }
    if (a < 0 || b < 0 || c < 0 || !triangle_equality(a, b, c)) {
        throw std::domain_error("Invalid triangle");
    }
    if (a == b && b == c) {
        return flavor::equilateral;
    }
    if (a == b || b == c || a == c) {
        return flavor::isosceles;
    }
    return flavor::scalene;
}

}  // namespace triangle
