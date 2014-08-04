#include "gigasecond.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

// See <http://www.boost.org/doc/libs/1_55_0/doc/html/date_time.html>
// for documentation on boost::gregorian::date

BOOST_AUTO_TEST_CASE(test_1)
{
    const auto actual = gigasecond::advance(boost::gregorian::date(2011, 4, 26));

    const boost::gregorian::date expected(2043, 1, 2);
    BOOST_REQUIRE_EQUAL(expected, actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(test_2)
{
    const auto actual = gigasecond::advance(boost::gregorian::date(1977, 6, 14));

    const boost::gregorian::date expected(2009, 2, 20);
    BOOST_REQUIRE_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(test_3)
{
    const auto actual = gigasecond::advance(boost::gregorian::date(1959, 7, 20));

    const boost::gregorian::date expected(1991, 3, 28);
    BOOST_REQUIRE_EQUAL(expected, actual);
}
#endif
