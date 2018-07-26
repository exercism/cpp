#include "binary_search.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(find_value_with_one_element)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 6 }, 6), 0);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(find_value_in_middle)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 1, 3, 4, 6, 8, 9, 11 }, 6), 3);
}

BOOST_AUTO_TEST_CASE(find_value_at_beginning)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 1, 3, 4, 6, 8, 9, 11 }, 1), 0);
}

BOOST_AUTO_TEST_CASE(find_value_at_end)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 1, 3, 4, 6, 8, 9, 11 }, 11), 6);
}

BOOST_AUTO_TEST_CASE(find_value_in_array_with_odd_length)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 634 }, 144), 9);
}

BOOST_AUTO_TEST_CASE(find_value_in_array_with_even_length)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 634 }, 21), 5);
}

BOOST_AUTO_TEST_CASE(identify_value_not_in_array)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 1, 3, 4, 6, 8, 9, 11 }, 7), -1);
}

BOOST_AUTO_TEST_CASE(identify_smaller_than_smallest_element_not_in_array)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 1, 3, 4, 6, 8, 9, 11 }, 0), -1);
}

BOOST_AUTO_TEST_CASE(identify_larger_than_largest_element_not_in_array)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ 1, 3, 4, 6, 8, 9, 11 }, 13), -1);
}

BOOST_AUTO_TEST_CASE(nothing_is_included_in_an_empty_array)
{
	BOOST_REQUIRE_EQUAL(binary_search::find({ }, 1), -1);
}
#endif
