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
    return lhs.real() == rhs.real() && lhs.imag() == rhs.imag();
}

std::ostream& operator<<(std::ostream& os, Complex const& value) {
    os << "(" << value.real() << "," << value.imag() << ")";
    return os;
}

}  // namespace complex_numbers
