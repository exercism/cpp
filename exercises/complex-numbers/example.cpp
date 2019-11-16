#include <cmath>
#include <limits>

#include "complex_numbers.h"

namespace complex_numbers {

Complex::Complex(double r, double i) : re(r), im(i) {}

Complex Complex::operator+(const Complex& other) const {
    Complex sum{re + other.re, im + other.im};
    return sum;
}

Complex Complex::operator-(const Complex& other) const {
    Complex diff{re - other.re, im - other.im};
    return diff;
}

Complex Complex::operator*(const Complex& other) const {
    Complex prod{re * other.re - im * other.im, im * other.re + re * other.im};
    return prod;
}

Complex Complex::operator/(const Complex& other) const {
    Complex quot{(re * other.re + im * other.im) /
                     (other.re * other.re + other.im * other.im),
                 (im * other.re - re * other.im) /
                     (other.re * other.re + other.im * other.im)};
    return quot;
}

double Complex::abs() const { return sqrt(re * re + im * im); }

Complex Complex::conj() const {
    Complex cx{re, -im};
    return cx;
}

double Complex::real() const { return re; }

double Complex::imag() const { return im; }

Complex Complex::exp() const {
    Complex ex{std::exp(re) * std::cos(im), std::exp(re) * std::sin(im)};
    return ex;
}

bool operator==(const Complex& lhs, const Complex& rhs) {
    // Adapted from
    // https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
    using std::abs;
    using std::ceil;
    using std::numeric_limits;
    auto almost_equal = [](double x, double y, int ulp) {
        // the machine epsilon has to be scaled to the magnitude of the
        // values used and multiplied by the desired precision in ULPs
        // (units in the last place) unless the result is subnormal
        return abs(x - y) <=
                   numeric_limits<double>::epsilon() * ceil(abs(x + y)) * ulp ||
               abs(x - y) < numeric_limits<double>::min();
    };
    return almost_equal(lhs.real(), rhs.real(), 2) &&
           almost_equal(lhs.imag(), rhs.imag(), 2);
}

std::ostream& operator<<(std::ostream& os, Complex const& value) {
    os << "(" << value.real() << "," << value.imag() << ")";
    return os;
}

}  // namespace complex_numbers
