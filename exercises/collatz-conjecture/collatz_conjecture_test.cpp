#include "collatz_conjecture.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <stdexcept>

BOOST_AUTO_TEST_CASE(zero_steps_for_one)
{
	BOOST_REQUIRE_EQUAL(collatz::steps(1), 0);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(divide_if_even)
{
	BOOST_REQUIRE_EQUAL(collatz::steps(16), 4);
}

BOOST_AUTO_TEST_CASE(even_and_odd_steps)
{
	BOOST_REQUIRE_EQUAL(collatz::steps(12), 9);
}

BOOST_AUTO_TEST_CASE(large_number_of_even_and_odd_steps)
{
	BOOST_REQUIRE_EQUAL(collatz::steps(1000000), 152);
}

BOOST_AUTO_TEST_CASE(zero_is_an_error)
{
	BOOST_REQUIRE_THROW(collatz::steps(0), std::domain_error);
}

BOOST_AUTO_TEST_CASE(negative_is_an_error)
{
	BOOST_REQUIRE_THROW(collatz::steps(-15), std::domain_error);
}
#endif
