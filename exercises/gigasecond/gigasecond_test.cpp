#include "gigasecond.h"
#include "test/catch.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

// This problem requires you to install and use the boost date_time library.
// CMake will try to find and configure it for you if it is installed on your
// system.
// See <http://www.boost.org/doc/libs/1_58_0/doc/html/date_time/posix_time.html>
// for documentation on boost::posix_time

using namespace boost::posix_time;

TEST_CASE("test_1")
{
    const ptime actual = gigasecond::advance(time_from_string("2011-04-25 00:00:00"));

    const ptime expected(time_from_string("2043-01-01 01:46:40"));
    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("test_2")
{
    const auto actual = gigasecond::advance(time_from_string("1977-06-13 00:00:00"));

    const ptime expected(time_from_string("2009-02-19 01:46:40"));
    REQUIRE(expected == actual);
}

TEST_CASE("test_3")
{
    const auto actual = gigasecond::advance(time_from_string("1959-07-19 00:00:00"));

    const ptime expected(time_from_string("1991-03-27 01:46:40"));
    REQUIRE(expected == actual);
}

TEST_CASE("test_4")
{
    const auto actual = gigasecond::advance(time_from_string("2015-01-24 22:00:00"));

    const ptime expected(time_from_string("2046-10-02 23:46:40"));
    REQUIRE(expected == actual);
}

TEST_CASE("test_5")
{
    const auto actual = gigasecond::advance(time_from_string("2015-01-24 23:59:59"));

    const ptime expected(time_from_string("2046-10-03 01:46:39"));
    REQUIRE(expected == actual);
}
#endif
