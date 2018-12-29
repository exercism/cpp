#include "triangle.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <stdexcept>

BOOST_TEST_DONT_PRINT_LOG_VALUE(triangle::flavor)

BOOST_AUTO_TEST_CASE(equilateral_triangles_have_equal_sides)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::equilateral, triangle::kind(2, 2, 2));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(larger_equilateral_triangles_also_have_equal_sides)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::equilateral, triangle::kind(10, 10, 10));
}

BOOST_AUTO_TEST_CASE(isosceles_triangles_have_last_two_sides_equal)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::isosceles, triangle::kind(3, 4, 4));
}

BOOST_AUTO_TEST_CASE(isosceles_triangles_have_first_and_last_sides_equal)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::isosceles, triangle::kind(4, 3, 4));
}

BOOST_AUTO_TEST_CASE(isosceles_triangles_have_first_two_sides_equal)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::isosceles, triangle::kind(4, 4, 3));
}

BOOST_AUTO_TEST_CASE(isosceles_triangles_have_in_fact_exactly_two_sides_equal)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::isosceles, triangle::kind(10, 10, 2));
}

BOOST_AUTO_TEST_CASE(scalene_triangles_have_no_equal_sides)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::scalene, triangle::kind(3, 4, 5));
}

BOOST_AUTO_TEST_CASE(scalene_triangles_have_no_equal_sides_at_a_larger_scale_too)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::scalene, triangle::kind(10, 11, 12));
}

BOOST_AUTO_TEST_CASE(scalene_triangles_have_no_equal_sides_in_descending_order_either)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::scalene, triangle::kind(5, 4, 2));
}

BOOST_AUTO_TEST_CASE(very_small_triangles_are_legal)
{
    BOOST_REQUIRE_EQUAL(triangle::flavor::scalene, triangle::kind(0.4, 0.6, 0.3));
}

BOOST_AUTO_TEST_CASE(triangles_with_no_size_are_illegal)
{
    BOOST_REQUIRE_THROW(triangle::kind(0, 0, 0), std::domain_error);
}

BOOST_AUTO_TEST_CASE(triangles_with_negative_sides_are_illegal)
{
    BOOST_REQUIRE_THROW(triangle::kind(3, 4, -5), std::domain_error);
}

BOOST_AUTO_TEST_CASE(triangles_violating_triangle_inequality_are_illegal)
{
    BOOST_REQUIRE_THROW(triangle::kind(1, 1, 3), std::domain_error);
}

BOOST_AUTO_TEST_CASE(larger_triangles_violating_triangle_inequality_are_illegal)
{
    BOOST_REQUIRE_THROW(triangle::kind(7, 3, 2), std::domain_error);
}
#endif
