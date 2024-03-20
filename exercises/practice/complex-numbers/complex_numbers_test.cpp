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
    REQUIRE_THAT(lhs.real(),
                 Catch::Matchers::WithinAbs(rhs.real(), eps));
    REQUIRE_THAT(lhs.imag(),
                 Catch::Matchers::WithinAbs(rhs.imag(), eps));
}

TEST_CASE("Real part -> Real part of a purely real number", "[9f98e133-eb7f-45b0-9676-cce001cd6f7a]") {
    const Complex c{1.0, 0.0};

    REQUIRE_THAT(c.real(), Catch::Matchers::WithinAbs(1.0, eps));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Real part -> Real part of a purely imaginary number", "[07988e20-f287-4bb7-90cf-b32c4bffe0f3]") {
    const Complex c{0.0, 1.0};

    REQUIRE_THAT(c.real(), Catch::Matchers::WithinAbs(0.0, eps));
}

TEST_CASE("Real part -> Real part of a number with real and imaginary part", "[4a370e86-939e-43de-a895-a00ca32da60a]") {
    const Complex c{1.0, 2.0};

    REQUIRE_THAT(c.real(), Catch::Matchers::WithinAbs(1.0, eps));
}

TEST_CASE("Imaginary part -> Imaginary part of a purely real number", "[9b3fddef-4c12-4a99-b8f8-e3a42c7ccef6]") {
    const Complex c{1.0, 0.0};

    REQUIRE_THAT(c.imag(), Catch::Matchers::WithinAbs(0.0, eps));
}

TEST_CASE("Imaginary part -> Imaginary part of a purely imaginary number", "[a8dafedd-535a-4ed3-8a39-fda103a2b01e]") {
    const Complex c{0.0, 1.0};

    REQUIRE_THAT(c.imag(), Catch::Matchers::WithinAbs(1.0, eps));
}

TEST_CASE("Imaginary part -> Imaginary part of a number with real and imaginary part", "[0f998f19-69ee-4c64-80ef-01b086feab80]") {
    const Complex c{1.0, 2.0};

    REQUIRE_THAT( c.imag(), Catch::Matchers::WithinAbs(2.0, eps));
}

TEST_CASE("Imaginary unit", "[a39b7fd6-6527-492f-8c34-609d2c913879]") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 1.0};

    require_approx_equal(Complex(-1.0, 0.0), c1 * c2);
}

TEST_CASE("Arithmetic -> Addition -> Add purely real numbers", "[9a2c8de9-f068-4f6f-b41c-82232cc6c33e]") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    require_approx_equal(Complex(3.0, 0.0), c1 + c2);
}

TEST_CASE("Arithmetic -> Addition -> Add purely imaginary numbers", "[657c55e1-b14b-4ba7-bd5c-19db22b7d659]") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    require_approx_equal(Complex(0.0, 3.0), c1 + c2);
}

TEST_CASE("Arithmetic -> Addition -> Add numbers with real and imaginary part", "[4e1395f5-572b-4ce8-bfa9-9a63056888da]") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    require_approx_equal(Complex(4.0, 6.0), c1 + c2);
}

TEST_CASE("Arithmetic -> Subtraction -> Subtract purely real numbers", "[1155dc45-e4f7-44b8-af34-a91aa431475d]") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    require_approx_equal(Complex(-1.0, 0.0), c1 - c2);
}

TEST_CASE("Arithmetic -> Subtraction -> Subtract purely imaginary numbers", "[f95e9da8-acd5-4da4-ac7c-c861b02f774b]") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    require_approx_equal(Complex(0.0, -1.0), c1 - c2);
}

TEST_CASE("Arithmetic -> Subtraction -> Subtract numbers with real and imaginary part", "[f876feb1-f9d1-4d34-b067-b599a8746400]") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    require_approx_equal(Complex(-2.0, -2.0), c1 - c2);
}

TEST_CASE("Arithmetic -> Multiplication -> Multiply purely real numbers", "[8a0366c0-9e16-431f-9fd7-40ac46ff4ec4]") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    require_approx_equal(Complex(2.0, 0.0), c1 * c2);
}

TEST_CASE("Arithmetic -> Multiplication -> Multiply purely imaginary numbers", "[e560ed2b-0b80-4b4f-90f2-63cefc911aaf]") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    require_approx_equal(Complex(-2.0, 0.0), c1 * c2);
}

TEST_CASE("Arithmetic -> Multiplication -> Multiply numbers with real and imaginary part", "[4d1d10f0-f8d4-48a0-b1d0-f284ada567e6]") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    require_approx_equal(Complex(-5.0, 10.0), c1 * c2);
}

TEST_CASE("Arithmetic -> Division -> Divide purely real numbers", "[b0571ddb-9045-412b-9c15-cd1d816d36c1]") {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};

    require_approx_equal(Complex(0.5, 0.0), c1 / c2);
}

TEST_CASE("Arithmetic -> Division -> Divide purely imaginary numbers", "[5bb4c7e4-9934-4237-93cc-5780764fdbdd]") {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};

    require_approx_equal(Complex(0.5, 0.0), c1 / c2);
}

TEST_CASE("Arithmetic -> Division -> Divide numbers with real and imaginary part", "[c4e7fef5-64ac-4537-91c2-c6529707701f]") {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};

    require_approx_equal(Complex(0.44, 0.08), c1 / c2);
}

TEST_CASE("Absolute value -> Absolute value of a positive purely real number", "[c56a7332-aad2-4437-83a0-b3580ecee843]") {
    const Complex c{5.0, 0.0};

    REQUIRE_THAT(c.abs(), Catch::Matchers::WithinAbs(5.0, eps));
}

TEST_CASE("Absolute value -> Absolute value of a negative purely real number", "[cf88d7d3-ee74-4f4e-8a88-a1b0090ecb0c]") {
    const Complex c{-5.0, 0.0};

    REQUIRE_THAT(c.abs(), Catch::Matchers::WithinAbs(5.0, eps));
}

TEST_CASE(
    "Absolute value -> Absolute value of a purely imaginary number with positive imaginary part", "[bbe26568-86c1-4bb4-ba7a-da5697e2b994]") {
    const Complex c{0.0, 5.0};

    REQUIRE_THAT(c.abs(), Catch::Matchers::WithinAbs(5.0, eps));
}

TEST_CASE(
    "Absolute value -> Absolute value of a purely imaginary number with negative imaginary part", "[3b48233d-468e-4276-9f59-70f4ca1f26f3]") {
    const Complex c{0.0, -5.0};

    REQUIRE_THAT(c.abs(), Catch::Matchers::WithinAbs(5.0, eps));
}

TEST_CASE("Absolute value -> Absolute value of a number with real and imaginary part", "[fe400a9f-aa22-4b49-af92-51e0f5a2a6d3]") {
    const Complex c{3.0, 4.0};

    REQUIRE_THAT(c.abs(), Catch::Matchers::WithinAbs(5.0, eps));
}

TEST_CASE("Complex conjugate -> Conjugate a purely real number", "[fb2d0792-e55a-4484-9443-df1eddfc84a2]") {
    const Complex c{5.0, 0.0};

    require_approx_equal(Complex(5.0, 0.0), c.conj());
}

TEST_CASE("Complex conjugate -> Conjugate a purely imaginary number", "[e37fe7ac-a968-4694-a460-66cb605f8691]") {
    const Complex c{0.0, 5.0};

    require_approx_equal(Complex(0.0, -5.0), c.conj());
}

TEST_CASE("Complex conjugate -> Conjugate a number with real and imaginary part", "[f7704498-d0be-4192-aaf5-a1f3a7f43e68]") {
    const Complex c{1.0, 1.0};

    require_approx_equal(Complex(1.0, -1.0), c.conj());
}

TEST_CASE("Complex exponential function -> Euler's identity/formula", "[6d96d4c6-2edb-445b-94a2-7de6d4caaf60]") {
    const Complex c{0.0, M_PI};

    require_approx_equal(Complex(-1.0, 0.0), c.exp());
}

TEST_CASE("Complex exponential function -> Exponential of 0", "[2d2c05a0-4038-4427-a24d-72f6624aa45f]") {
    const Complex c{0.0, 0.0};

    require_approx_equal(Complex(1.0, 0.0), c.exp());
}

TEST_CASE("Complex exponential function -> Exponential of a purely real number", "[ed87f1bd-b187-45d6-8ece-7e331232c809]") {
    const Complex c{1.0, 0.0};

    require_approx_equal(Complex(M_E, 0.0), c.exp());
}

// Extra Credit
TEST_CASE("Complex exponential function -> Exponential of a number with real and imaginary part", "[08eedacc-5a95-44fc-8789-1547b27a8702]") {
    const Complex c{std::log(2.0), M_PI};

    require_approx_equal(Complex(-2.0, 0.0), c.exp());
}

TEST_CASE("Complex exponential function -> Exponential resulting in a number with real and imaginary part", "[d2de4375-7537-479a-aa0e-d474f4f09859]") {
    const Complex c{std::log(2.0)/2.0, M_PI/4.0};

    require_approx_equal(Complex(1.0, 1.0), c.exp());
}

TEST_CASE("Operations between real numbers and complex numbers -> Add real number to complex number", "[06d793bf-73bd-4b02-b015-3030b2c952ec]") {
    const Complex c{1.0, 2.0};

    require_approx_equal(Complex(6.0,2.0), c + 5.0);
}

TEST_CASE("Operations between real numbers and complex numbers -> Add complex number to real number", "[d77dbbdf-b8df-43f6-a58d-3acb96765328]") {
    const Complex c{1.0, 2.0};

    require_approx_equal(Complex(6.0,2.0), 5.0 + c);
}

TEST_CASE("Operations between real numbers and complex numbers -> Subtract real number from complex number", "[20432c8e-8960-4c40-ba83-c9d910ff0a0f]") {
    const Complex c{5.0, 7.0};

    require_approx_equal(Complex(1.0,7.0), c - 4.0 );
}

TEST_CASE("Operations between real numbers and complex numbers -> Subtract complex number from real number", "[b4b38c85-e1bf-437d-b04d-49bba6e55000]") {
    const Complex c{5.0, 7.0};

    require_approx_equal(Complex(-1.0,-7.0), 4.0 - c);
}

TEST_CASE("Operations between real numbers and complex numbers -> Multiply complex number by real number", "[dabe1c8c-b8f4-44dd-879d-37d77c4d06bd]") {
    const Complex c{2.0, 5.0};

    require_approx_equal(Complex(10.0,25.0), c * 5.0);
}

TEST_CASE("Operations between real numbers and complex numbers -> Multiply real number by complex number", "[6c81b8c8-9851-46f0-9de5-d96d314c3a28]") {
    const Complex c{2.0, 5.0};

    require_approx_equal(Complex(10.0,25.0), 5.0 * c);
}

TEST_CASE("Operations between real numbers and complex numbers -> Divide complex number by real number", "[8a400f75-710e-4d0c-bcb4-5e5a00c78aa0]") {
    const Complex c{10.0, 100.0};

    require_approx_equal(Complex(1.0,10.0), c / 10.0 );
}

TEST_CASE("Operations between real numbers and complex numbers -> Divide real number by complex number", "[9a867d1b-d736-4c41-a41e-90bd148e9d5e]") {
    const Complex c{1.0, 1.0};

    require_approx_equal(Complex(2.5,-2.5), 5.0 / c);
}

#endif
