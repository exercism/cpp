#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H
#include <complex>
#include <iostream>

namespace complex_numbers {

class Complex {
   public:
    Complex(double, double);
    Complex(std::complex<double>);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    double abs() const;
    Complex conj() const;
    double real() const;
    double imag() const;
    Complex exp() const;

   private:
    double re, im;
};

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator==(const std::complex<double>& lhs, const Complex& rhs);
bool operator==(const Complex& lhs, const std::complex<double>& rhs);
std::ostream& operator<<(std::ostream& os, Complex const& value);

}  // namespace complex_numbers

#endif
