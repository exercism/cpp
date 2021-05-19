#include "triangle.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <stdexcept>

TEST_CASE("equilateral_triangles_have_equal_sides")
{
    REQUIRE(triangle::flavor::equilateral == triangle::kind(2, 2, 2));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("larger_equilateral_triangles_also_have_equal_sides")
{
    REQUIRE(triangle::flavor::equilateral == triangle::kind(10, 10, 10));
}

TEST_CASE("isosceles_triangles_have_last_two_sides_equal")
{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(3, 4, 4));
}

TEST_CASE("isosceles_triangles_have_first_and_last_sides_equal")
{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(4, 3, 4));
}

TEST_CASE("isosceles_triangles_have_first_two_sides_equal")
{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(4, 4, 3));
}

TEST_CASE("isosceles_triangles_have_in_fact_exactly_two_sides_equal")
{
    REQUIRE(triangle::flavor::isosceles == triangle::kind(10, 10, 2));
}

TEST_CASE("scalene_triangles_have_no_equal_sides")
{
    REQUIRE(triangle::flavor::scalene == triangle::kind(3, 4, 5));
}

TEST_CASE("scalene_triangles_have_no_equal_sides_at_a_larger_scale_too")
{
    REQUIRE(triangle::flavor::scalene == triangle::kind(10, 11, 12));
}

TEST_CASE("scalene_triangles_have_no_equal_sides_in_descending_order_either")
{
    REQUIRE(triangle::flavor::scalene == triangle::kind(5, 4, 2));
}

TEST_CASE("very_small_triangles_are_legal")
{
    REQUIRE(triangle::flavor::scalene == triangle::kind(0.4, 0.6, 0.3));
}

TEST_CASE("triangles_with_no_size_are_illegal")
{
    REQUIRE_THROWS_AS(triangle::kind(0, 0, 0), std::domain_error);
}

TEST_CASE("triangles_with_negative_sides_are_illegal")
{
    REQUIRE_THROWS_AS(triangle::kind(3, 4, -5), std::domain_error);
}

TEST_CASE("triangles_violating_triangle_inequality_are_illegal")
{
    REQUIRE_THROWS_AS(triangle::kind(1, 1, 3), std::domain_error);
}

TEST_CASE("larger_triangles_violating_triangle_inequality_are_illegal")
{
    REQUIRE_THROWS_AS(triangle::kind(7, 3, 2), std::domain_error);
}

TEST_CASE("double_and_integer_arguments")
{
    REQUIRE(triangle::flavor::scalene == triangle::kind(5.5, 4, 2));
}
#endif
