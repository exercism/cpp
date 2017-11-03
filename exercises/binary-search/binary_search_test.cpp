#include "binary_search.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <vector>

using namespace std;

BOOST_AUTO_TEST_CASE(finds_a_value_in_an_array_with_one_element)
{
    const std::vector<int> data {6};
    
    const int actual = binary_search::find(data, 6);

    const int expected = 0;

    BOOST_TEST(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(finds_a_value_in_the_middle_of_an_array)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const int actual = binary_search::find(data, 6);

    const int expected = 3;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(finds_a_value_at_the_beginning_of_an_array)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const int actual = binary_search::find(data, 1);

    const int expected = 0;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(finds_a_value_at_the_end_of_an_array)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const int actual = binary_search::find(data, 11);

    const int expected = 6;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(finds_a_value_in_an_array_of_odd_length)
{
    const std::vector<int> data {1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 634};
    
    const int actual = binary_search::find(data, 144);

    const int expected = 9;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(finds_a_value_in_an_array_of_even_length)
{
    const std::vector<int> data {1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
    
    const int actual = binary_search::find(data, 21);

    const int expected = 5;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(identifies_that_a_value_is_not_included_in_the_array)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const int actual = binary_search::find(data, 7);

    const int expected = -1;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(a_value_smaller_than_the_arrays_smallest_value_is_not_included)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const int actual = binary_search::find(data, 0);

    const int expected = -1;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(a_value_larger_than_the_arrays_largest_value_is_not_included)
{
    const std::vector<int> data {1, 3, 4, 6, 8, 9, 11};
    
    const int actual = binary_search::find(data, 13);

    const int expected = -1;

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(nothing_is_included_in_an_empty_array)
{
    const std::vector<int> data {};
    
    const int actual = binary_search::find(data, 1);

    const int expected = -1;

    BOOST_TEST(expected == actual);
}

#endif
