#include "gigasecond.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <cstdio>
#include <ctime>

using namespace std;

// Helper function to construct a time_t type from the given date settings
static time_t time_from_string(const std::string& s)
{
    struct tm date;
    sscanf(s.c_str(), "%4d-%2d-%2d %2d:%2d:%2d", &date.tm_year, &date.tm_mon, &date.tm_mday,
                                         &date.tm_hour, &date.tm_min, &date.tm_sec);
    date.tm_year -= 1900;
    date.tm_mon -= 1;
    return mktime(&date);
}

BOOST_AUTO_TEST_CASE(test_1)
{
    const time_t actual = gigasecond::advance(time_from_string("2011-04-25 00:00:00"));

    const time_t expected(time_from_string("2043-01-01 01:46:40"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(test_2)
{
    const auto actual = gigasecond::advance(time_from_string("1977-06-13 00:00:00"));

    const time_t expected(time_from_string("2009-02-19 01:46:40"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(test_3)
{
    const auto actual = gigasecond::advance(time_from_string("1959-07-19 00:00:00"));

    const time_t expected(time_from_string("1991-03-27 01:46:40"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(test_4)
{
    const auto actual = gigasecond::advance(time_from_string("2015-01-24 22:00:00"));

    const time_t expected(time_from_string("2046-10-02 23:46:40"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(test_5)
{
    const auto actual = gigasecond::advance(time_from_string("2015-01-24 23:59:59"));

    const time_t expected(time_from_string("2046-10-03 01:46:39"));
    BOOST_REQUIRE_EQUAL(expected, actual);
}
#endif
