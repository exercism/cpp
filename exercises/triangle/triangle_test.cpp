#include "triangle.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(equilateral_if_all_sides_equal)
{
    BOOST_REQUIRE_EQUAL(true, triangle(2, 2, 2).Equilateral);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(not_equilateral_if_any_side_is_unequal)
{
    BOOST_REQUIRE_EQUAL(false, triangle(2, 3, 2).Equilateral);
}

BOOST_AUTO_TEST_CASE(not_equilateral_if_no_sides_are_equal)
{
    BOOST_REQUIRE_EQUAL(false, triangle(5 , 4, 6).Equilateral);
}

BOOST_AUTO_TEST_CASE(not_equilateral_if_all_sides_are_zero)
{
    BOOST_REQUIRE_EQUAL(false, triangle(0, 0, 0).Equilateral);
}

BOOST_AUTO_TEST_CASE(equilateral_sides_may_be_floats)
{
    BOOST_REQUIRE_EQUAL(true, triangle(0.5, 0.5, 0.5).Equilateral);
}

BOOST_AUTO_TEST_CASE(isosceles_if_last_two_sides_are_equal)
{
    BOOST_REQUIRE_EQUAL(true, triangle(3, 4, 4).Isosceles);
}

BOOST_AUTO_TEST_CASE(isosceles_if_first_two_sides_are_equal)
{
    BOOST_REQUIRE_EQUAL(true, triangle(4, 4, 3).Isosceles);
}

BOOST_AUTO_TEST_CASE(isosceles_if_first_and_last_sides_are_equal)
{
    BOOST_REQUIRE_EQUAL(true, triangle(4 , 3 , 4).Isosceles);
}

BOOST_AUTO_TEST_CASE(equilateral_triangles_are_also_isosceles)
{
    BOOST_REQUIRE_EQUAL(true, triangle(4, 4, 4).Isosceles);
}

BOOST_AUTO_TEST_CASE(not_isosceles_if_no_sides_are_equal)
{
    BOOST_REQUIRE_EQUAL(false, triangle(2, 3, 4).Isosceles);
}

BOOST_AUTO_TEST_CASE(not_isosceles_when_it_violates_triangle_inequality)
{
    BOOST_REQUIRE_EQUAL(false , triangle(1 , 1, 3).Isosceles);
}

BOOST_AUTO_TEST_CASE(isosceles_sides_may_be_floats)
{
    BOOST_REQUIRE_EQUAL(true , triangle(0.5 , 0.4, 0.5).Isosceles);
}

BOOST_AUTO_TEST_CASE(scalene_if_no_sides_are_equal)
{
    BOOST_REQUIRE_EQUAL(true , triangle(5 , 4, 6).Scalene);
}

BOOST_AUTO_TEST_CASE(not_scalene_if_all_sides_are_equal)
{
    BOOST_REQUIRE_EQUAL(false , triangle(4 , 4 , 4).Scalene);
}

BOOST_AUTO_TEST_CASE(not_scalene_if_two_sides_are_equal)
{
    BOOST_REQUIRE_EQUAL(false , triangle(4 , 4, 3).Scalene);
}

BOOST_AUTO_TEST_CASE(not_scalene_when_it_violates_triangle_inequality)
{
    BOOST_REQUIRE_EQUAL(false , triangle(7 , 3 , 2).Scalene);
}

BOOST_AUTO_TEST_CASE(scalene_sides_may_be_floats)
{
    BOOST_REQUIRE_EQUAL(true , triangle(0.5 , 0.4 , 0.6).Scalene);
}
#endif
