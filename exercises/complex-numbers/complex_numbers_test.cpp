#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <complex>
#include <cmath>
#include "complex_numbers.h"

// Complex Numbers exercise test case data version 1.0.0

BOOST_AUTO_TEST_CASE(Add_purely_real_numbers)
{
    const complex_numbers::Complex c1 {1.0, 0.0};
    
    const complex_numbers::Complex c2 {2.0, 0.0};
    
    const complex_numbers::Complex actual = c1 + c2;

    const complex_numbers::Complex expected {3.0, 0.0};

    BOOST_CHECK(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(Add_purely_imaginary_numbers)
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 2.0};
    
    const complex_numbers::Complex actual = c1 + c2;

    const complex_numbers::Complex expected {0.0, 3.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Add_numbers_with_real_and_imaginary_part)
{
    const complex_numbers::Complex c1 {1.0, 2.0};
    
    const complex_numbers::Complex c2 {3.0, 4.0};
    
    const complex_numbers::Complex actual = c1 + c2;

    const complex_numbers::Complex expected {4.0, 6.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Subtract_purely_real_numbers)
{
    const complex_numbers::Complex c1 {1.0, 0.0};
    
    const complex_numbers::Complex c2 {2.0, 0.0};
    
    const complex_numbers::Complex actual = c1 - c2;

    const complex_numbers::Complex expected {-1.0, 0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Subtract_purely_imaginary_numbers)
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 2.0};
    
    const complex_numbers::Complex actual = c1 - c2;

    const complex_numbers::Complex expected {0.0, -1.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Subtract_numbers_with_real_and_imaginary_part)
{
    const complex_numbers::Complex c1 {1.0, 2.0};
    
    const complex_numbers::Complex c2 {3.0, 4.0};
    
    const complex_numbers::Complex actual = c1 - c2;

    const complex_numbers::Complex expected {-2.0, -2.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Multiply_purely_real_numbers)
{
    const complex_numbers::Complex c1 {1.0, 0.0};
    
    const complex_numbers::Complex c2 {2.0, 0.0};
    
    const complex_numbers::Complex actual = c1 * c2;

    const complex_numbers::Complex expected {2.0, 0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Multiply_purely_imaginary_numbers)
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 2.0};
    
    const complex_numbers::Complex actual = c1 * c2;

    const complex_numbers::Complex expected {-2.0, 0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Multiply_numbers_with_real_and_imaginary_part)
{
    const complex_numbers::Complex c1 {1.0, 2.0};
    
    const complex_numbers::Complex c2 {3.0, 4.0};
    
    const complex_numbers::Complex actual = c1 * c2;

    const complex_numbers::Complex expected {-5.0, 10.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Imaginary_unit)
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 1.0};
    
    const complex_numbers::Complex actual = c1 * c2;

    const complex_numbers::Complex expected {-1.0, 0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Divide_purely_real_numbers)
{
    const complex_numbers::Complex c1 {1.0, 0.0};
    
    const complex_numbers::Complex c2 {2.0, 0.0};
    
    const complex_numbers::Complex actual = c1 / c2;

    const complex_numbers::Complex expected {0.5, 0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Divide_purely_imaginary_numbers)
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 2.0};
    
    const complex_numbers::Complex actual = c1 / c2;

    const complex_numbers::Complex expected {0.5, 0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Divide_numbers_with_real_and_imaginary_part)
{
    const complex_numbers::Complex c1 {1.0, 2.0};
    
    const complex_numbers::Complex c2 {3.0, 4.0};
    
    const complex_numbers::Complex actual = c1 / c2;

    const complex_numbers::Complex expected {0.44, 0.08};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Absolute_value_of_a_positive_purely_real_number)
{
    const complex_numbers::Complex c {5.0, 0.0};
    
    const double actual = c.abs();

    const double expected {5.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Absolute_value_of_a_negative_purely_real_number)
{
    const complex_numbers::Complex c {-5.0, 0.0};
    
    const double actual = c.abs();

    const double expected {5.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Absolute_value_of_a_purely_imaginary_number_with_positive_imaginary_part)
{
    const complex_numbers::Complex c {0.0, 5.0};
    
    const double actual = c.abs();

    const double expected {5.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Absolute_value_of_a_purely_imaginary_number_with_negative_imaginary_part)
{
    const complex_numbers::Complex c {0.0, -5.0};
    
    const double actual = c.abs();

    const double expected {5.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Absolute_value_of_a_number_with_real_and_imaginary_part)
{
    const complex_numbers::Complex c {3.0, 4.0};
   
    const double actual = c.abs();

    const double expected {5.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Conjugate_a_purely_real_number)
{
    const complex_numbers::Complex c {5.0, 0.0};
   
    const complex_numbers::Complex actual = c.conj();

    const complex_numbers::Complex expected {5.0, 0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Conjugate_a_purely_imaginary_number)
{
    const complex_numbers::Complex c {0.0, 5.0};
   
    const complex_numbers::Complex actual = c.conj();

    const complex_numbers::Complex expected {0.0, -5.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Conjugate_a_number_with_real_and_imaginary_part)
{
    const complex_numbers::Complex c {1.0, 1.0};
   
    const complex_numbers::Complex actual = c.conj();

    const complex_numbers::Complex expected {1.0, -1.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Real_part_of_a_purely_real_number)
{
    const complex_numbers::Complex c {1.0, 0.0};
   
    const double actual = c.real();

    const double expected {1.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Real_part_of_a_purely_imaginary_number)
{
    const complex_numbers::Complex c {0.0, 1.0};
   
    const double actual = c.real();

    const double expected {0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Real_part_of_a_number_with_real_and_imaginary_number)
{
    const complex_numbers::Complex c {1.0, 2.0};
   
    const double actual = c.real();

    const double expected {1.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Imaginary_part_of_a_purely_real_number)
{
    const complex_numbers::Complex c {1.0, 0.0};
   
    const double actual = c.imag();

    const double expected {0.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Imaginary_part_of_a_purely_imaginary_number)
{
    const complex_numbers::Complex c {0.0, 1.0};
   
    const double actual = c.imag();

    const double expected {1.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Imaginary_part_of_a_number_with_real_and_imaginary_part)
{
    const complex_numbers::Complex c {1.0, 2.0};
   
    const double actual = c.imag();

    const double expected {2.0};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Eulers_identity)
{
    const complex_numbers::Complex c {0.0, M_PI};
    
    const complex_numbers::Complex actual = c.exp();
    
    const std::complex<double> cx {0.0, M_PI};
    
    const complex_numbers::Complex expected {exp(cx).real(), exp(cx).imag()};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Exponential_of_zero)
{
    const complex_numbers::Complex c {0.0, 0.0};
    
    const complex_numbers::Complex actual = c.exp();
    
    const std::complex<double> cx {0.0, 0.0};
    
    const complex_numbers::Complex expected {exp(cx).real(), exp(cx).imag()};

    BOOST_CHECK(expected == actual);
}

BOOST_AUTO_TEST_CASE(Exponential_of_a_purely_real_number)
{
    const complex_numbers::Complex c {1.0, 0.0};
    
    const complex_numbers::Complex actual = c.exp();
    
    const std::complex<double> cx {1.0, 0.0};
    
    const complex_numbers::Complex expected {exp(cx).real(), exp(cx).imag()};

    BOOST_CHECK(expected == actual);
}

#endif
