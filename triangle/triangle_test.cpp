#include "triangle.h"

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <stdexcept>

BOOST_AUTO_TEST_CASE(equilateral_triangles_have_equal_sides)
{
    const triangle tri(2, 2, 2);

    BOOST_REQUIRE_EQUAL("equilateral", tri.kind());
}

BOOST_AUTO_TEST_CASE(larger_equilateral_triangles_also_have_equal_sides)
{
    const triangle tri(10, 10, 10);

    BOOST_REQUIRE_EQUAL("equilateral", tri.kind());
}

BOOST_AUTO_TEST_CASE(isosceles_triangles_have_last_two_sides_equal)
{
    const triangle tri(3, 4, 4);

    BOOST_REQUIRE_EQUAL("isosceles", tri.kind());
}

BOOST_AUTO_TEST_CASE(isosceles_triangles_have_first_and_last_sides_equal)
{
    const triangle tri(4, 3, 4);

    BOOST_REQUIRE_EQUAL("isosceles", tri.kind());
}

BOOST_AUTO_TEST_CASE(isosceles_triangles_have_first_two_sides_equal)
{
    const triangle tri(4, 4, 3);

    BOOST_REQUIRE_EQUAL("isosceles", tri.kind());
}

BOOST_AUTO_TEST_CASE(isosceles_triangles_have_in_fact_exactly_two_sides_equal)
{
    const triangle tri(10, 10, 2);

    BOOST_REQUIRE_EQUAL("isosceles", tri.kind());
}

BOOST_AUTO_TEST_CASE(scalene_triangles_have_no_equal_sides)
{
    const triangle tri(3, 4, 5);

    BOOST_REQUIRE_EQUAL("scalene", tri.kind());
}

BOOST_AUTO_TEST_CASE(scalene_triangles_have_no_equal_sides_at_a_larger_scale_too)
{
    const triangle tri(10, 11, 12);

    BOOST_REQUIRE_EQUAL("scalene", tri.kind());
}

BOOST_AUTO_TEST_CASE(scalene_triangles_have_no_equal_sides_in_descending_order_either)
{
    const triangle tri(5, 4, 2);

    BOOST_REQUIRE_EQUAL("scalene", tri.kind());
}

BOOST_AUTO_TEST_CASE(very_small_triangles_are_legal)
{
    const triangle tri(0.4, 0.6, 0.3);

    BOOST_REQUIRE_EQUAL("scalene", tri.kind());
}

BOOST_AUTO_TEST_CASE(triangles_with_no_size_are_illegal)
{
    const triangle tri(0, 0, 0);

    BOOST_REQUIRE_THROW(tri.kind(), std::domain_error);
}

BOOST_AUTO_TEST_CASE(triangles_with_negative_sides_are_illegal)
{
    const triangle tri(3, 4, -5);

    BOOST_REQUIRE_EQUAL("illegal", tri.kind());
}

BOOST_AUTO_TEST_CASE(triangles_violating_triangle_inequality_are_illegal)
{
    const triangle tri(1, 1, 3);

    BOOST_REQUIRE_EQUAL("illegal", tri.kind());
}

BOOST_AUTO_TEST_CASE(medium_triangles_violating_triangle_inequality_are_illegal)
{
    const triangle tri(2, 4, 2);

    BOOST_REQUIRE_EQUAL("illegal", tri.kind());
}

BOOST_AUTO_TEST_CASE(larger_triangles_violating_triangle_inequality_are_illegal)
{
    const triangle tri(7, 3, 2);

    BOOST_REQUIRE_EQUAL("illegal", tri.kind());
}
