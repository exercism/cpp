#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {

class Complex {
    
public:
    Complex(double, double);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    const bool operator==(const Complex& other) const;
    double abs() const;
    Complex conj() const;
    double real() const;
    double imag() const;
    Complex exp() const;
    
private:
    double re, im;
};

}
#endif
