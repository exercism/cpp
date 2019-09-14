#include "complex_numbers.h"
#include "test/catch.hpp"
#include <complex>
#include <cmath>

// Complex Numbers exercise test case data version 1.0.0

TEST_CASE("add_purely_real_numbers")
{
    const complex_numbers::Complex c1 {1.0, 0.0};
    
    const complex_numbers::Complex c2 {2.0, 0.0};
    
    const complex_numbers::Complex actual = c1 + c2;

    const complex_numbers::Complex expected {3.0, 0.0};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("add_purely_imaginary_numbers")
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 2.0};
    
    const complex_numbers::Complex actual = c1 + c2;

    const complex_numbers::Complex expected {0.0, 3.0};

    REQUIRE(expected == actual);
}

TEST_CASE("add_numbers_with_real_and_imaginary_part")
{
    const complex_numbers::Complex c1 {1.0, 2.0};
    
    const complex_numbers::Complex c2 {3.0, 4.0};
    
    const complex_numbers::Complex actual = c1 + c2;

    const complex_numbers::Complex expected {4.0, 6.0};

    REQUIRE(expected == actual);
}

TEST_CASE("subtract_purely_real_numbers")
{
    const complex_numbers::Complex c1 {1.0, 0.0};
    
    const complex_numbers::Complex c2 {2.0, 0.0};
    
    const complex_numbers::Complex actual = c1 - c2;

    const complex_numbers::Complex expected {-1.0, 0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("subtract_purely_imaginary_numbers")
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 2.0};
    
    const complex_numbers::Complex actual = c1 - c2;

    const complex_numbers::Complex expected {0.0, -1.0};

    REQUIRE(expected == actual);
}

TEST_CASE("subtract_numbers_with_real_and_imaginary_part")
{
    const complex_numbers::Complex c1 {1.0, 2.0};
    
    const complex_numbers::Complex c2 {3.0, 4.0};
    
    const complex_numbers::Complex actual = c1 - c2;

    const complex_numbers::Complex expected {-2.0, -2.0};

    REQUIRE(expected == actual);
}

TEST_CASE("multiply_purely_real_numbers")
{
    const complex_numbers::Complex c1 {1.0, 0.0};
    
    const complex_numbers::Complex c2 {2.0, 0.0};
    
    const complex_numbers::Complex actual = c1 * c2;

    const complex_numbers::Complex expected {2.0, 0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("multiply_purely_imaginary_numbers")
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 2.0};
    
    const complex_numbers::Complex actual = c1 * c2;

    const complex_numbers::Complex expected {-2.0, 0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("multiply_numbers_with_real_and_imaginary_part")
{
    const complex_numbers::Complex c1 {1.0, 2.0};
    
    const complex_numbers::Complex c2 {3.0, 4.0};
    
    const complex_numbers::Complex actual = c1 * c2;

    const complex_numbers::Complex expected {-5.0, 10.0};

    REQUIRE(expected == actual);
}

TEST_CASE("imaginary_unit")
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 1.0};
    
    const complex_numbers::Complex actual = c1 * c2;

    const complex_numbers::Complex expected {-1.0, 0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("divide_purely_real_numbers")
{
    const complex_numbers::Complex c1 {1.0, 0.0};
    
    const complex_numbers::Complex c2 {2.0, 0.0};
    
    const complex_numbers::Complex actual = c1 / c2;

    const complex_numbers::Complex expected {0.5, 0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("divide_purely_imaginary_numbers")
{
    const complex_numbers::Complex c1 {0.0, 1.0};
    
    const complex_numbers::Complex c2 {0.0, 2.0};
    
    const complex_numbers::Complex actual = c1 / c2;

    const complex_numbers::Complex expected {0.5, 0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("divide_numbers_with_real_and_imaginary_part")
{
    const complex_numbers::Complex c1 {1.0, 2.0};
    
    const complex_numbers::Complex c2 {3.0, 4.0};
    
    const complex_numbers::Complex actual = c1 / c2;

    const complex_numbers::Complex expected {0.44, 0.08};

    REQUIRE(expected == actual);
}

TEST_CASE("absolute_value_of_a_positive_purely_real_number")
{
    const complex_numbers::Complex c {5.0, 0.0};
    
    const double actual = c.abs();

    const double expected {5.0};

    REQUIRE(expected == actual);
}

TEST_CASE("absolute_value_of_a_negative_purely_real_number")
{
    const complex_numbers::Complex c {-5.0, 0.0};
    
    const double actual = c.abs();

    const double expected {5.0};

    REQUIRE(expected == actual);
}

TEST_CASE("absolute_value_of_a_purely_imaginary_number_with_positive_imaginary_part")
{
    const complex_numbers::Complex c {0.0, 5.0};
    
    const double actual = c.abs();

    const double expected {5.0};

    REQUIRE(expected == actual);
}

TEST_CASE("absolute_value_of_a_purely_imaginary_number_with_negative_imaginary_part")
{
    const complex_numbers::Complex c {0.0, -5.0};
    
    const double actual = c.abs();

    const double expected {5.0};

    REQUIRE(expected == actual);
}

TEST_CASE("absolute_value_of_a_number_with_real_and_imaginary_part")
{
    const complex_numbers::Complex c {3.0, 4.0};
   
    const double actual = c.abs();

    const double expected {5.0};

    REQUIRE(expected == actual);
}

TEST_CASE("conjugate_a_purely_real_number")
{
    const complex_numbers::Complex c {5.0, 0.0};
   
    const complex_numbers::Complex actual = c.conj();

    const complex_numbers::Complex expected {5.0, 0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("conjugate_a_purely_imaginary_number")
{
    const complex_numbers::Complex c {0.0, 5.0};
   
    const complex_numbers::Complex actual = c.conj();

    const complex_numbers::Complex expected {0.0, -5.0};

    REQUIRE(expected == actual);
}

TEST_CASE("conjugate_a_number_with_real_and_imaginary_part")
{
    const complex_numbers::Complex c {1.0, 1.0};
   
    const complex_numbers::Complex actual = c.conj();

    const complex_numbers::Complex expected {1.0, -1.0};

    REQUIRE(expected == actual);
}

TEST_CASE("real_part_of_a_purely_real_number")
{
    const complex_numbers::Complex c {1.0, 0.0};
   
    const double actual = c.real();

    const double expected {1.0};

    REQUIRE(expected == actual);
}

TEST_CASE("real_part_of_a_purely_imaginary_number")
{
    const complex_numbers::Complex c {0.0, 1.0};
   
    const double actual = c.real();

    const double expected {0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("real_part_of_a_number_with_real_and_imaginary_number")
{
    const complex_numbers::Complex c {1.0, 2.0};
   
    const double actual = c.real();

    const double expected {1.0};

    REQUIRE(expected == actual);
}

TEST_CASE("imaginary_part_of_a_purely_real_number")
{
    const complex_numbers::Complex c {1.0, 0.0};
   
    const double actual = c.imag();

    const double expected {0.0};

    REQUIRE(expected == actual);
}

TEST_CASE("imaginary_part_of_a_purely_imaginary_number")
{
    const complex_numbers::Complex c {0.0, 1.0};
   
    const double actual = c.imag();

    const double expected {1.0};

    REQUIRE(expected == actual);
}

TEST_CASE("imaginary_part_of_a_number_with_real_and_imaginary_part")
{
    const complex_numbers::Complex c {1.0, 2.0};
   
    const double actual = c.imag();

    const double expected {2.0};

    REQUIRE(expected == actual);
}

TEST_CASE("eulers_identity")
{
    const complex_numbers::Complex c {0.0, M_PI};
    
    const complex_numbers::Complex actual = c.exp();
    
    const std::complex<double> cx {0.0, M_PI};
    
    const complex_numbers::Complex expected {exp(cx).real(), exp(cx).imag()};

    REQUIRE(expected == actual);
}

TEST_CASE("exponential_of_zero")
{
    const complex_numbers::Complex c {0.0, 0.0};
    
    const complex_numbers::Complex actual = c.exp();
    
    const std::complex<double> cx {0.0, 0.0};
    
    const complex_numbers::Complex expected {exp(cx).real(), exp(cx).imag()};

    REQUIRE(expected == actual);
}

TEST_CASE("exponential_of_a_purely_real_number")
{
    const complex_numbers::Complex c {1.0, 0.0};
    
    const complex_numbers::Complex actual = c.exp();
    
    const std::complex<double> cx {1.0, 0.0};
    
    const complex_numbers::Complex expected {exp(cx).real(), exp(cx).imag()};

    REQUIRE(expected == actual);
}

#endif
