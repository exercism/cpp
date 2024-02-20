#include "gigasecond.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include "boost/date_time/posix_time/posix_time.hpp"

// This problem requires you to install and use the boost date_time library.
// CMake will try to find and configure it for you if it is installed on your
// system.
// See <http://www.boost.org/doc/libs/1_74_0/doc/html/date_time/posix_time.html>
// for documentation on boost::posix_time

using namespace boost::posix_time;

TEST_CASE("date only specification of time",
          "[92fbe71c-ea52-4fac-bd77-be38023cacf7]") {
    const ptime actual =
        gigasecond::advance(time_from_string("2011-04-25 00:00:00"));

    const ptime expected(time_from_string("2043-01-01 01:46:40"));
    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("second test for date only specification of time",
          "[6d86dd16-6f7a-47be-9e58-bb9fb2ae1433]") {
    const auto actual =
        gigasecond::advance(time_from_string("1977-06-13 00:00:00"));

    const ptime expected(time_from_string("2009-02-19 01:46:40"));
    REQUIRE(expected == actual);
}

TEST_CASE("third test for date only specification of time",
          "[77eb8502-2bca-4d92-89d9-7b39ace28dd5]") {
    const auto actual =
        gigasecond::advance(time_from_string("1959-07-19 00:00:00"));

    const ptime expected(time_from_string("1991-03-27 01:46:40"));
    REQUIRE(expected == actual);
}

TEST_CASE("full time specified", "[c9d89a7d-06f8-4e28-a305-64f1b2abc693]") {
    const auto actual =
        gigasecond::advance(time_from_string("2015-01-24 22:00:00"));

    const ptime expected(time_from_string("2046-10-02 23:46:40"));
    REQUIRE(expected == actual);
}

TEST_CASE("full time with day roll-over",
          "[09d4e30e-728a-4b52-9005-be44a58d9eba]") {
    const auto actual =
        gigasecond::advance(time_from_string("2015-01-24 23:59:59"));

    const ptime expected(time_from_string("2046-10-03 01:46:39"));
    REQUIRE(expected == actual);
}
#endif
