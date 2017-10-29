#include "gigasecond.h"
#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include <string>

using namespace std;

// This problem is easiest when using a library
// The std library <ctime> is one option: See http://en.cppreference.com/w/cpp/header/ctime
// Third-party libraries are allowed and encouraged for this problem
//   e.g. Boost.DateTime: See http://www.boost.org/doc/libs/1_59_0/doc/html/date_time/posix_time.html

TEST_CASE("test_1")
{
    const string actual = gigasecond::advance("2011-04-25 00:00:00");

    const string expected{"2043-01-01 01:46:40"};

    REQUIRE(expected == actual);
}

TEST_CASE("test_2")
{
    const auto actual = gigasecond::advance("1977-06-13 00:00:00");

    const string expected{"2009-02-19 01:46:40"};
    REQUIRE(expected == actual);
}

TEST_CASE("test_3")
{
    const auto actual = gigasecond::advance("1959-07-19 00:00:00");

    const string expected{"1991-03-27 01:46:40"};
    REQUIRE(expected == actual);
}

TEST_CASE("test_4")
{
    const auto actual = gigasecond::advance("2015-01-24 22:00:00");

    const string expected{"2046-10-02 23:46:40"};
    REQUIRE(expected == actual);
}

TEST_CASE("test_5")
{
    const auto actual = gigasecond::advance("2015-01-24 23:59:59");

    const string expected{"2046-10-03 01:46:39"};
    REQUIRE(expected == actual);
}
