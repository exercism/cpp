#include "complex_numbers.h"

#include <cmath>

#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// Complex Numbers exercise test case data version 1.3.0

using complex_numbers::Complex;

// Define constants for platforms that don't include it
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif

// Define a margin to use for float comparisons. Catch does not compute a good
// epsilon for float values near 0.
static const double eps = 0.005;

// Helper function for comparing Complex numbers with approximate float values.
static void require_approx_equal(const Complex& lhs, const Complex& rhs) {
    REQUIRE(Approx(lhs.real()).margin(eps) == rhs.real());
    REQUIRE(Approx(lhs.imag()).margin(eps) == rhs.imag());
}

TEST_CASE("Real part of a purely real number") {
    const Complex c{1.0, 0.0};

    REQUIRE(Approx(1.0) == c.real());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Real part of a purely imaginary number") {
    const Complex c{0.0, 1.0};

    REQUIRE(Approx(0.0).margin(eps) == c.real());
}

TEST_CASE("Real part of a number with real and imaginary part") {
    const Complex c{1.0, 2.0};

    REQUIRE(Approx(1.0) == c.real());
}

TEST_CASE("Imaginary part of a purely real number") {
    const Complex c{1.0, 0.0};

    REQUIRE(Approx(0.0).margin(eps) == c.imag());
}

TEST_CASE("Imaginary part of a purely imaginary number") {
    const Complex c{0.0, 1.0};

    REQUIRE(Approx(1.0) == c.imag());
}

TEST_CASE("Imaginary part of a number with real and imaginary part") {
    const Complex c{1.0, 2.0};

    REQUIRE(Approx(2.0) == c.imag());
}

TEST_CASE("Imaginary unit") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 1.0};

    require_approx_equal(Complex(-1.0, 0.0), c1 * c2);
}

TEST_CASE("Add purely real numbers") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    require_approx_equal(Complex(3.0, 0.0), c1 + c2);
}

TEST_CASE("Add purely imaginary numbers") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    require_approx_equal(Complex(0.0, 3.0), c1 + c2);
}

TEST_CASE("Add numbers with real and imaginary part") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    require_approx_equal(Complex(4.0, 6.0), c1 + c2);
}

TEST_CASE("Subtract purely real numbers") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    require_approx_equal(Complex(-1.0, 0.0), c1 - c2);
}

TEST_CASE("Subtract purely imaginary numbers") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    require_approx_equal(Complex(0.0, -1.0), c1 - c2);
}

TEST_CASE("Subtract numbers with real and imaginary part") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    require_approx_equal(Complex(-2.0, -2.0), c1 - c2);
}

TEST_CASE("Multiply purely real numbers") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    require_approx_equal(Complex(2.0, 0.0), c1 * c2);
}

TEST_CASE("Multiply purely imaginary numbers") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    require_approx_equal(Complex(-2.0, 0.0), c1 * c2);
}

TEST_CASE("Multiply numbers with real and imaginary part") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    require_approx_equal(Complex(-5.0, 10.0), c1 * c2);
}

TEST_CASE("Divide purely real numbers") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    require_approx_equal(Complex(0.5, 0.0), c1 / c2);
}

TEST_CASE("Divide purely imaginary numbers") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    require_approx_equal(Complex(0.5, 0.0), c1 / c2);
}

TEST_CASE("Divide numbers with real and imaginary part") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    require_approx_equal(Complex(0.44, 0.08), c1 / c2);
}

TEST_CASE("Absolute value of a positive purely real number") {
    const Complex c{5.0, 0.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE("Absolute value of a negative purely real number") {
    const Complex c{-5.0, 0.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE(
    "Absolute value of a purely imaginary number with positive imaginary "
    "part") {
    const Complex c{0.0, 5.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE(
    "Absolute value of a purely imaginary number with negative imaginary "
    "part") {
    const Complex c{0.0, -5.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE("Absolute value of a number with real and imaginary part") {
    const Complex c{3.0, 4.0};

    REQUIRE(Approx(5.0) == c.abs());
}

TEST_CASE("Conjugate a purely real number") {
    const Complex c{5.0, 0.0};

    require_approx_equal(Complex(5.0, 0.0), c.conj());
}

TEST_CASE("Conjugate a purely imaginary number") {
    const Complex c{0.0, 5.0};

    require_approx_equal(Complex(0.0, -5.0), c.conj());
}

TEST_CASE("Conjugate a number with real and imaginary part") {
    const Complex c{1.0, 1.0};

    require_approx_equal(Complex(1.0, -1.0), c.conj());
}

TEST_CASE("Eulers identity") {
    const Complex c{0.0, M_PI};

    require_approx_equal(Complex(-1.0, 0.0), c.exp());
}

TEST_CASE("Exponential of zero") {
    const Complex c{0.0, 0.0};

    require_approx_equal(Complex(1.0, 0.0), c.exp());
}

TEST_CASE("Exponential of a purely real number") {
    const Complex c{1.0, 0.0};

    require_approx_equal(Complex(M_E, 0.0), c.exp());
}

// Extra Credit
TEST_CASE("Exponential of a number with real and imaginary part") {
    const Complex c{std::log(2.0), M_PI};

    require_approx_equal(Complex(-2.0, 0.0), c.exp());
}

#endif
