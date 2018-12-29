#include "gigasecond.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"

// See <http://www.boost.org/doc/libs/1_59_0/doc/html/date_time/posix_time.html>
// for documentation on boost::posix_time

using namespace boost::posix_time;

BOOST_AUTO_TEST_CASE(test_1)
{
    const ptime actual = gigasecond::advance(time_from_string("2011-04-25 00:00:00"));

    const ptime expected(time_from_string("2043-01-01 01:46:40"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(test_2)
{
    const auto actual = gigasecond::advance(time_from_string("1977-06-13 00:00:00"));

    const ptime expected(time_from_string("2009-02-19 01:46:40"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(test_3)
{
    const auto actual = gigasecond::advance(time_from_string("1959-07-19 00:00:00"));

    const ptime expected(time_from_string("1991-03-27 01:46:40"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(test_4)
{
    const auto actual = gigasecond::advance(time_from_string("2015-01-24 22:00:00"));

    const ptime expected(time_from_string("2046-10-02 23:46:40"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(test_5)
{
    const auto actual = gigasecond::advance(time_from_string("2015-01-24 23:59:59"));

    const ptime expected(time_from_string("2046-10-03 01:46:39"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}
#endif
