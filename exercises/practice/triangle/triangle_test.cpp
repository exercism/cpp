#include "triangle.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <stdexcept>

/*
Problem spec commentary:

    Pursuant to discussion in #202, we have decided NOT to test triangles
    where all side lengths are positive but a + b = c. e.g:
    (2, 4, 2, Isosceles), (1, 3, 4, Scalene).
    It's true that the triangle inequality admits such triangles.These
    triangles have zero area, however.
    They're degenerate triangles with all three vertices collinear.
    (In contrast, we will test (0, 0, 0, Illegal), as it is a point)
    The tests assert properties of the triangle are true or false.
    See: https://github.com/exercism/problem-specifications/issues/379 for
    disscussion of this approach How you handle invalid triangles is up to you.
    These tests suggest a triangle is returned, but all of its properties are
false. But you could also have the creation of an invalid triangle return an
error or exception. Choose what is idiomatic for your language."

The CPP track has chosen to throw a domain error for invalid triangles.

Tests, that check if an equilateral is also scalene (etc.) do not work with
the chosen implementation, they are therefore not implemented for this track.

*/

// improves error messages with triangle flavor enum text instead of integers:
CATCH_REGISTER_ENUM(triangle::flavor, triangle::flavor::equilateral,
                    triangle::flavor::isosceles, triangle::flavor::scalene)

TEST_CASE("equilateral triangle -> all sides are equal",
          "[8b2c43ac-7257-43f9-b552-7631a91988af]") {
    REQUIRE(triangle::flavor::equilateral == triangle::kind(2, 2, 2));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("equilateral triangle -> any side is unequal",
          "[33eb6f87-0498-4ccf-9573-7f8c3ce92b7b]") {
    REQUIRE_FALSE(triangle::flavor::equilateral == triangle::kind(2, 3, 2));
}

TEST_CASE("equilateral triangle -> no sides are equal",
          "[c6585b7d-a8c0-4ad8-8a34-e21d36f7ad87]") {
    REQUIRE_FALSE(triangle::flavor::equilateral == triangle::kind(5, 4, 6));
}

TEST_CASE("equilateral triangle -> sides may be floats",
          "[3022f537-b8e5-4cc1-8f12-fd775827a00c]") {
    REQUIRE(triangle::flavor::equilateral == triangle::kind(0.5, 0.5, 0.5));
}

TEST_CASE("isosceles triangle -> last two sides are equal",
          "[cbc612dc-d75a-4c1c-87fc-e2d5edd70b71]") {
    REQUIRE(triangle::flavor::isosceles == triangle::kind(3, 4, 4));
}

TEST_CASE("isosceles triangle -> first two sides are equal",
          "[e388ce93-f25e-4daf-b977-4b7ede992217]") {
    REQUIRE(triangle::flavor::isosceles == triangle::kind(4, 4, 3));
}

TEST_CASE("isosceles triangle -> first and last sides are equal",
          "[d2080b79-4523-4c3f-9d42-2da6e81ab30f]") {
    REQUIRE(triangle::flavor::isosceles == triangle::kind(4, 3, 4));
}

TEST_CASE("isosceles triangle -> no sides are equal",
          "[840ed5f8-366f-43c5-ac69-8f05e6f10bbb]") {
    REQUIRE_FALSE(triangle::flavor::isosceles == triangle::kind(2, 3, 4));
}

TEST_CASE("isosceles triangle -> first triangle inequality violation",
          "[2eba0cfb-6c65-4c40-8146-30b608905eae]") {
    REQUIRE_THROWS_AS(triangle::kind(1, 1, 3), std::domain_error);
}

TEST_CASE("isosceles triangle -> second triangle inequality violation",
          "[278469cb-ac6b-41f0-81d4-66d9b828f8ac]") {
    REQUIRE_THROWS_AS(triangle::kind(1, 3, 1), std::domain_error);
}

TEST_CASE("isosceles triangle -> third triangle inequality violation",
          "[90efb0c7-72bb-4514-b320-3a3892e278ff]") {
    REQUIRE_THROWS_AS(triangle::kind(3, 1, 1), std::domain_error);
}

TEST_CASE("isosceles triangle -> sides may be floats",
          "[adb4ee20-532f-43dc-8d31-e9271b7ef2bc]") {
    REQUIRE(triangle::flavor::isosceles == triangle::kind(0.5, 0.4, 0.5));
}

TEST_CASE("scalene triangle -> no sides are equal",
          "[e8b5f09c-ec2e-47c1-abec-f35095733afb]") {
    REQUIRE(triangle::flavor::scalene == triangle::kind(5, 4, 6));
}

TEST_CASE("scalene triangle -> may not violate triangle inequality",
          "[70ad5154-0033-48b7-af2c-b8d739cd9fdc]") {
    REQUIRE_THROWS_AS(triangle::kind(7, 3, 2), std::domain_error);
}

TEST_CASE("scalene triangle -> sides may be floats",
          "[26d9d59d-f8f1-40d3-ad58-ae4d54123d7d]") {
    REQUIRE(triangle::flavor::scalene == triangle::kind(0.4, 0.6, 0.3));
}

TEST_CASE("all zero sides is not a triangle",
          "[16e8ceb0-eadb-46d1-b892-c50327479251]") {
    REQUIRE_THROWS_AS(triangle::kind(0, 0, 0), std::domain_error);
}

// Tests that are not in the problem spec
// kept for legacy and specific cpp functionality

TEST_CASE("triangles_with_negative_sides_are_illegal") {
    REQUIRE_THROWS_AS(triangle::kind(3, 4, -5), std::domain_error);
}

TEST_CASE("double_and_integer_arguments") {
    REQUIRE(triangle::flavor::scalene == triangle::kind(5.5, 4, 2));
}

#endif
