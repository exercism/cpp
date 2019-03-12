#include "binary_search.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <vector>
#include <cstddef>

using namespace std;

// Binary-Search exercise test case data version 1.3.0

BOOST_AUTO_TEST_CASE(finds_a_value_in_an_array_with_one_element)
{
    const std::vector<int> data {6};
    
    const std::size_t actual = binary_search::find(data, 6);

    const std::size_t expected = 0;

    BOOST_TEST(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(finds_a_value_in_the_middle_of_an_array)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const std::size_t actual = binary_search::find(data, 6);

    const std::size_t expected = 3;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(finds_a_value_at_the_beginning_of_an_array)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const std::size_t actual = binary_search::find(data, 1);

    const std::size_t expected = 0;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(finds_a_value_at_the_end_of_an_array)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const std::size_t actual = binary_search::find(data, 11);

    const std::size_t expected = 6;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(finds_a_value_in_an_array_of_odd_length)
{
    const std::vector<int> data {1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 634};
    
    const std::size_t actual = binary_search::find(data, 144);

    const std::size_t expected = 9;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(finds_a_value_in_an_array_of_even_length)
{
    const std::vector<int> data {1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
    
    const std::size_t actual = binary_search::find(data, 21);

    const std::size_t expected = 5;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(identifies_that_a_value_is_not_included_in_the_array)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    BOOST_REQUIRE_THROW(binary_search::find(data, 7), std::domain_error);
}

BOOST_AUTO_TEST_CASE(a_value_smaller_than_the_arrays_smallest_value_is_not_found)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    BOOST_REQUIRE_THROW(binary_search::find(data, 0), std::domain_error);
}

BOOST_AUTO_TEST_CASE(a_value_larger_than_the_arrays_largest_value_is_not_found)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    BOOST_REQUIRE_THROW(binary_search::find(data, 13), std::domain_error);
}

BOOST_AUTO_TEST_CASE(nothing_is_found_in_an_empty_array)
{
    const std::vector<int> data {};
    
    BOOST_REQUIRE_THROW(binary_search::find(data, 1), std::domain_error);
}

BOOST_AUTO_TEST_CASE(nothing_is_found_when_the_left_and_right_bounds_cross)
{
    const std::vector<int> data {1, 2};
    
    BOOST_REQUIRE_THROW(binary_search::find(data, 0), std::domain_error);
}

#endif
