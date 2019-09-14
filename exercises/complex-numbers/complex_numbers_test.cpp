#include "complex_numbers.h"

#define _USE_MATH_DEFINES // For M_PI
#include <cmath>
#include <complex>

#include "test/catch.hpp"

// Complex Numbers exercise test case data version 1.0.0

using complex_numbers::Complex;

TEST_CASE("add_purely_real_numbers") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    REQUIRE(Complex(3.0, 0.0) == c1 + c2);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("add_purely_imaginary_numbers") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    REQUIRE(Complex(0.0, 3.0) == c1 + c2);
}

TEST_CASE("add_numbers_with_real_and_imaginary_part") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    REQUIRE(Complex(4.0, 6.0) == c1 + c2);
}

TEST_CASE("subtract_purely_real_numbers") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    REQUIRE(Complex(-1.0, 0.0) == c1 - c2);
}

TEST_CASE("subtract_purely_imaginary_numbers") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    REQUIRE(Complex(0.0, -1.0) == c1 - c2);
}

TEST_CASE("subtract_numbers_with_real_and_imaginary_part") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    REQUIRE(Complex(-2.0, -2.0) == c1 - c2);
}

TEST_CASE("multiply_purely_real_numbers") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    REQUIRE(Complex(2.0, 0.0) == c1 * c2);
}

TEST_CASE("multiply_purely_imaginary_numbers") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    REQUIRE(Complex(-2.0, 0.0) == c1 * c2);
}

TEST_CASE("multiply_numbers_with_real_and_imaginary_part") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    REQUIRE(Complex(-5.0, 10.0) == c1 * c2);
}

TEST_CASE("imaginary_unit") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 1.0};

    REQUIRE(Complex(-1.0, 0.0) == c1 * c2);
}

TEST_CASE("divide_purely_real_numbers") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    REQUIRE(Complex(0.5, 0.0) == c1 / c2);
}

TEST_CASE("divide_purely_imaginary_numbers") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    REQUIRE(Complex(0.5, 0.0) == c1 / c2);
}

TEST_CASE("divide_numbers_with_real_and_imaginary_part") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    REQUIRE(Complex(0.44, 0.08) == c1 / c2);
}

TEST_CASE("absolute_value_of_a_positive_purely_real_number") {
    const Complex c{5.0, 0.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE("absolute_value_of_a_negative_purely_real_number") {
    const Complex c{-5.0, 0.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE(
    "absolute_value_of_a_purely_imaginary_number_with_positive_imaginary_"
    "part") {
    const Complex c{0.0, 5.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE(
    "absolute_value_of_a_purely_imaginary_number_with_negative_imaginary_"
    "part") {
    const Complex c{0.0, -5.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE("absolute_value_of_a_number_with_real_and_imaginary_part") {
    const Complex c{3.0, 4.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE("conjugate_a_purely_real_number") {
    const Complex c{5.0, 0.0};

    REQUIRE(Complex(5.0, 0.0) == c.conj());
}

TEST_CASE("conjugate_a_purely_imaginary_number") {
    const Complex c{0.0, 5.0};

    REQUIRE(Complex(0.0, -5.0) == c.conj());
}

TEST_CASE("conjugate_a_number_with_real_and_imaginary_part") {
    const Complex c{1.0, 1.0};

    REQUIRE(Complex(1.0, -1.0) == c.conj());
}

TEST_CASE("real_part_of_a_purely_real_number") {
    const Complex c{1.0, 0.0};

    REQUIRE(Approx(1.0) == c.real());
}

TEST_CASE("real_part_of_a_purely_imaginary_number") {
    const Complex c{0.0, 1.0};

    REQUIRE(Approx(0.0) == c.real());
}

TEST_CASE("real_part_of_a_number_with_real_and_imaginary_number") {
    const Complex c{1.0, 2.0};

    REQUIRE(Approx(1.0) == c.real());
}

TEST_CASE("imaginary_part_of_a_purely_real_number") {
    const Complex c{1.0, 0.0};

    REQUIRE(Approx(0.0) == c.imag());
}

TEST_CASE("imaginary_part_of_a_purely_imaginary_number") {
    const Complex c{0.0, 1.0};

    REQUIRE(Approx(1.0) == c.imag());
}

TEST_CASE("imaginary_part_of_a_number_with_real_and_imaginary_part") {
    const Complex c{1.0, 2.0};

    REQUIRE(Approx(2.0) == c.imag());
}

TEST_CASE("eulers_identity") {
    const Complex c{0.0, M_PI};
    const std::complex<double> cx{0.0, M_PI};

    REQUIRE(Complex(exp(cx).real(), exp(cx).imag()) == c.exp());
}

TEST_CASE("exponential_of_zero") {
    const Complex c{0.0, 0.0};
    const std::complex<double> cx{0.0, 0.0};

    REQUIRE(Complex(exp(cx).real(), exp(cx).imag()) == c.exp());
}

TEST_CASE("exponential_of_a_purely_real_number") {
    const Complex c{1.0, 0.0};
    const std::complex<double> cx{1.0, 0.0};

    REQUIRE(Complex(exp(cx).real(), exp(cx).imag()) == c.exp());
}

#endif
