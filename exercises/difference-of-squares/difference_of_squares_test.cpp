#include "difference_of_squares.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(up_to_5)
{
    BOOST_REQUIRE_EQUAL(225, squares::square_of_sum(5));
    BOOST_REQUIRE_EQUAL(55, squares::sum_of_squares(5));
    BOOST_REQUIRE_EQUAL(170, squares::difference(5));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(up_to_10)
{
    BOOST_REQUIRE_EQUAL(3025, squares::square_of_sum(10));
    BOOST_REQUIRE_EQUAL(385, squares::sum_of_squares(10));
    BOOST_REQUIRE_EQUAL(2640, squares::difference(10));
}

BOOST_AUTO_TEST_CASE(up_to_100)
{
    BOOST_REQUIRE_EQUAL(25502500, squares::square_of_sum(100));
    BOOST_REQUIRE_EQUAL(338350, squares::sum_of_squares(100));
    BOOST_REQUIRE_EQUAL(25164150, squares::difference(100));
}
#endif
