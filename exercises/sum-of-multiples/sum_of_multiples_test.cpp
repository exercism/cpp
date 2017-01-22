#include "sum_of_multiples.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sum_to_1_yields_0)
{
    BOOST_REQUIRE_EQUAL(0, sum_of_multiples::to({3, 5}, 0));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(sum_to_4_yields_3)
{
    BOOST_REQUIRE_EQUAL(3, sum_of_multiples::to({3, 5}, 4));
}

BOOST_AUTO_TEST_CASE(sum_to_10_yields_23)
{
    BOOST_REQUIRE_EQUAL(23, sum_of_multiples::to({3, 5}, 10));
}

BOOST_AUTO_TEST_CASE(sum_to_100)
{
    BOOST_REQUIRE_EQUAL(2318, sum_of_multiples::to({3, 5}, 100));
}

BOOST_AUTO_TEST_CASE(sum_to_1000)
{
    BOOST_REQUIRE_EQUAL(233168, sum_of_multiples::to({3, 5}, 1000));
}

BOOST_AUTO_TEST_CASE(sum_of_7_13_17_to_20_yields_51)
{
    BOOST_REQUIRE_EQUAL(51, sum_of_multiples::to({7, 13, 17}, 20));
}

BOOST_AUTO_TEST_CASE(sum_of_4_6_to_15)
{
    BOOST_REQUIRE_EQUAL(30, sum_of_multiples::to({4, 6}, 15));
}

BOOST_AUTO_TEST_CASE(sum_of_5_6_8_to_150)
{
    BOOST_REQUIRE_EQUAL(4419, sum_of_multiples::to({5, 6, 8}, 150));
}

BOOST_AUTO_TEST_CASE(sum_of_5_25_to_51)
{
    BOOST_REQUIRE_EQUAL(275, sum_of_multiples::to({5, 25}, 51));
}

BOOST_AUTO_TEST_CASE(sum_of_43_47_to_10000)
{
    BOOST_REQUIRE_EQUAL(2203160, sum_of_multiples::to({43, 47}, 10000));
}

BOOST_AUTO_TEST_CASE(sum_of_1_to_100)
{
    BOOST_REQUIRE_EQUAL(4950, sum_of_multiples::to({1}, 100));
}

BOOST_AUTO_TEST_CASE(sum_of_empty_list)
{
    BOOST_REQUIRE_EQUAL(0, sum_of_multiples::to({}, 10000));
}
#endif
