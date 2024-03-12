#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H
#include <iostream>

namespace complex_numbers {

class Complex {
   public:
    Complex(double, double);
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
std::ostream& operator<<(std::ostream& os, Complex const& value);
Complex operator+(const Complex& complex, double scalar);
Complex operator+(double scalar, const Complex& complex);
Complex operator-(const Complex& complex, double scalar);
Complex operator-(double scalar, const Complex& complex);
Complex operator*(const Complex& complex, double scalar);
Complex operator*(double scalar, const Complex& complex);
Complex operator/(const Complex& complex, double scalar);
Complex operator/(double scalar, const Complex& complex);

}  // namespace complex_numbers

#endif
