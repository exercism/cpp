#include "triangle.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <stdexcept>

// improves error messages with triangle flavor enum text instead of integers:
CATCH_REGISTER_ENUM(triangle::flavor,
        triangle::flavor::equilateral,
        triangle::flavor::isosceles,
        triangle::flavor::scalene)

TEST_CASE("equilateral triangle -> all sides are equal","[8b2c43ac-7257-43f9-b552-7631a91988af]")

{
    REQUIRE(triangle::flavor::equilateral == triangle::kind(2, 2, 2));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("larger_equilateral_triangles_also_have_equal_sides")[8b2c43ac-7257-43f9-b552-7631a91988af]
"equilateral triangle -> all sides are equal"
{
    REQUIRE(triangle::flavor::equilateral == triangle::kind(10, 10, 10));
}

TEST_CASE("isosceles triangle -> last two sides are equal","[cbc612dc-d75a-4c1c-87fc-e2d5edd70b71]")
description = "isosceles triangle -> last two sides are equal"

{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(3, 4, 4));
}

TEST_CASE("isosceles triangle -> first and last sides are equal",[d2080b79-4523-4c3f-9d42-2da6e81ab30f])

{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(4, 3, 4));
}

TEST_CASE("isosceles triangle -> first two sides are equal","[e388ce93-f25e-4daf-b977-4b7ede992217]")

{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(4, 4, 3));
}
TEST_CASE("scalene triangle -> first and third sides are equal", "[3da23a91-a166-419a-9abf-baf4868fd985")

{
    REQUIRE(triangle::flavor::scalene == triangle::kind(3,4,3));
}
TEST_CASE("scalene triangle -> second and third sides are equal","[b6a75d98-1fef-4c42-8e9a-9db854ba0a4d]")

{
    REQUIRE(triangle::flavor:scalene == triangle::kind(4,3,3));
}
TEST_CASE("isosceles triangle -> first two sides are equal","[e388ce93-f25e-4daf-b977-4b7ede992217]")

{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(10, 10, 2));
}

TEST_CASE("scalene triangle -> no sides are equal", "[e8b5f09c-ec2e-47c1-abec-f35095733afb]")

{
    REQUIRE(triangle::flavor::scalene == triangle::kind(3, 4, 5));
}

TEST_CASE("scalene triangle -> no sides are equal", "[e8b5f09c-ec2e-47c1-abec-f35095733afb]")

{
    REQUIRE(triangle::flavor::scalene == triangle::kind(10, 11, 12));
}

TEST_CASE("scalene triangle -> may not violate triangle inequality","[70ad5154-0033-48b7-af2c-b8d739cd9fdc]")
{
    REQUIRE(triangle::flavor::scalene == triangle::kind(5, 4, 2));
}

TEST_CASE("scalene triangle -> sides may be floats", "[26d9d59d-f8f1-40d3-ad58-ae4d54123d7d]")

{
    REQUIRE(triangle::flavor::scalene == triangle::kind(0.4, 0.6, 0.3));
}

TEST_CASE("equilateral triangle -> all zero sides is not a triangle","[16e8ceb0-eadb-46d1-b892-c50327479251]")
{
    REQUIRE_THROWS_AS(triangle::kind(0, 0, 0), std::domain_error);
}

TEST_CASE("triangles_with_negative_sides_are_illegal")
{
    REQUIRE_THROWS_AS(triangle::kind(3, 4, -5), std::domain_error);
}

TEST_CASE("scalene triangle -> may not violate triangle inequality","[70ad5154-0033-48b7-af2c-b8d739cd9fdc]") 

{
    REQUIRE_THROWS_AS(triangle::kind(1, 1, 3), std::domain_error);
}

TEST_CASE("scalene triangle -> may not violate triangle inequality","[70ad5154-0033-48b7-af2c-b8d739cd9fdc]")

{
    REQUIRE_THROWS_AS(triangle::kind(7, 3, 2), std::domain_error);
}

TEST_CASE("double_and_integer_arguments")
{
    REQUIRE(triangle::flavor::scalene == triangle::kind(5.5, 4, 2));
}
TEST_CASE("isosceles triangle -> first and last sides are equal","[d2080b79-4523-4c3f-9d42-2da6e81ab30f]")

{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(3, 4, 3));
}

TEST_CASE("scalene triangle -> second and third sides are equal","[b6a75d98-1fef-4c42-8e9a-9db854ba0a4d]")
{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(4, 3, 3));
}
#endif
