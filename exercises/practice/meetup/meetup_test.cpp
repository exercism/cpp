#include "meetup.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// This problem requires you to install and use the boost date_time library.
// CMake will try to find and configure it for you if it is installed on your
// system.
// See <http://www.boost.org/doc/libs/1_74_0/doc/html/date_time.html> for
// documentation on boost::gregorian::date

TEST_CASE("monteenth_of_May_2013")
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 13};
    REQUIRE(expected == meetup.monteenth());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("monteenth_of_August_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 19};
    REQUIRE(expected == meetup.monteenth());
}

TEST_CASE("monteenth_of_September_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 16};
    REQUIRE(expected == meetup.monteenth());
}

TEST_CASE("tuesteenth_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 19};
    REQUIRE(expected == meetup.tuesteenth());
}

TEST_CASE("tuesteenth_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 16};
    REQUIRE(expected == meetup.tuesteenth());
}

TEST_CASE("tuesteenth_of_August_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 13};
    REQUIRE(expected == meetup.tuesteenth());
}

TEST_CASE("wednesteenth_of_January_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 16};
    REQUIRE(expected == meetup.wednesteenth());
}

TEST_CASE("wednesteenth_of_February_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 13};
    REQUIRE(expected == meetup.wednesteenth());
}

TEST_CASE("wednesteenth_of_June_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 19};
    REQUIRE(expected == meetup.wednesteenth());
}

TEST_CASE("thursteenth_of_May_2013")
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 16};
    REQUIRE(expected == meetup.thursteenth());
}

TEST_CASE("thursteenth_of_June_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 13};
    REQUIRE(expected == meetup.thursteenth());
}

TEST_CASE("thursteenth_of_September_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 19};
    REQUIRE(expected == meetup.thursteenth());
}

TEST_CASE("friteenth_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 19};
    REQUIRE(expected == meetup.friteenth());
}

TEST_CASE("friteenth_of_Aug_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 16};
    REQUIRE(expected == meetup.friteenth());
}

TEST_CASE("friteenth_of_September_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 13};
    REQUIRE(expected == meetup.friteenth());
}

TEST_CASE("saturteenth_of_February_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 16};
    REQUIRE(expected == meetup.saturteenth());
}

TEST_CASE("saturteenth_of_October_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 19};
    REQUIRE(expected == meetup.saturteenth());
}

TEST_CASE("sunteenth_of_May_2013")
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 19};
    REQUIRE(expected == meetup.sunteenth());
}

TEST_CASE("sunteenth_of_June_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 16};
    REQUIRE(expected == meetup.sunteenth());
}

TEST_CASE("sunteenth_of_October_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 13};
    REQUIRE(expected == meetup.sunteenth());
}

TEST_CASE("first_Monday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 4};
    REQUIRE(expected == meetup.first_monday());
}

TEST_CASE("first_Monday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 1};
    REQUIRE(expected == meetup.first_monday());
}

TEST_CASE("first_Tuesday_of_May_2013")
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 7};
    REQUIRE(expected == meetup.first_tuesday());
}

TEST_CASE("first_Tuesday_of_June_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 4};
    REQUIRE(expected == meetup.first_tuesday());
}

TEST_CASE("first_Wednesday_of_July_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 3};
    REQUIRE(expected == meetup.first_wednesday());
}

TEST_CASE("first_Wednesday_of_August_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 7};
    REQUIRE(expected == meetup.first_wednesday());
}

TEST_CASE("first_Thursday_of_September_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 5};
    REQUIRE(expected == meetup.first_thursday());
}

TEST_CASE("first_Thursday_of_October_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 3};
    REQUIRE(expected == meetup.first_thursday());
}

TEST_CASE("first_Friday_of_November_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 1};
    REQUIRE(expected == meetup.first_friday());
}

TEST_CASE("first_Friday_of_December_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 6};
    REQUIRE(expected == meetup.first_friday());
}

TEST_CASE("first_Saturday_of_January_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 5};
    REQUIRE(expected == meetup.first_saturday());
}

TEST_CASE("first_Saturday_of_February_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 2};
    REQUIRE(expected == meetup.first_saturday());
}

TEST_CASE("first_Sunday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 3};
    REQUIRE(expected == meetup.first_sunday());
}

TEST_CASE("first_Sunday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 7};
    REQUIRE(expected == meetup.first_sunday());
}

TEST_CASE("second_Monday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 11};
    REQUIRE(expected == meetup.second_monday());
}

TEST_CASE("second_Monday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 8};
    REQUIRE(expected == meetup.second_monday());
}

TEST_CASE("second_Tuesday_of_May_2013")
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 14};
    REQUIRE(expected == meetup.second_tuesday());
}

TEST_CASE("second_Tuesday_of_June_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 11};
    REQUIRE(expected == meetup.second_tuesday());
}

TEST_CASE("second_Wednesday_of_July_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 10};
    REQUIRE(expected == meetup.second_wednesday());
}

TEST_CASE("second_Wednesday_of_August_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 14};
    REQUIRE(expected == meetup.second_wednesday());
}

TEST_CASE("second_Thursday_of_September_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 12};
    REQUIRE(expected == meetup.second_thursday());
}

TEST_CASE("second_Thursday_of_October_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 10};
    REQUIRE(expected == meetup.second_thursday());
}

TEST_CASE("second_Friday_of_November_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 8};
    REQUIRE(expected == meetup.second_friday());
}

TEST_CASE("second_Friday_of_December_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 13};
    REQUIRE(expected == meetup.second_friday());
}

TEST_CASE("second_Saturday_of_January_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 12};
    REQUIRE(expected == meetup.second_saturday());
}

TEST_CASE("second_Saturday_of_February_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 9};
    REQUIRE(expected == meetup.second_saturday());
}

TEST_CASE("second_Sunday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 10};
    REQUIRE(expected == meetup.second_sunday());
}

TEST_CASE("second_Sunday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 14};
    REQUIRE(expected == meetup.second_sunday());
}

TEST_CASE("third_Monday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 18};
    REQUIRE(expected == meetup.third_monday());
}

TEST_CASE("third_Monday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 15};
    REQUIRE(expected == meetup.third_monday());
}

TEST_CASE("third_Tuesday_of_May_2013")
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 21};
    REQUIRE(expected == meetup.third_tuesday());
}

TEST_CASE("third_Tuesday_of_June_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 18};
    REQUIRE(expected == meetup.third_tuesday());
}

TEST_CASE("third_Wednesday_of_July_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 17};
    REQUIRE(expected == meetup.third_wednesday());
}

TEST_CASE("third_Wednesday_of_August_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 21};
    REQUIRE(expected == meetup.third_wednesday());
}

TEST_CASE("third_Thursday_of_September_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 19};
    REQUIRE(expected == meetup.third_thursday());
}

TEST_CASE("third_Thursday_of_October_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 17};
    REQUIRE(expected == meetup.third_thursday());
}

TEST_CASE("third_Friday_of_November_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 15};
    REQUIRE(expected == meetup.third_friday());
}

TEST_CASE("third_Friday_of_December_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 20};
    REQUIRE(expected == meetup.third_friday());
}

TEST_CASE("third_Saturday_of_January_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 19};
    REQUIRE(expected == meetup.third_saturday());
}

TEST_CASE("third_Saturday_of_February_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 16};
    REQUIRE(expected == meetup.third_saturday());
}

TEST_CASE("third_Sunday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 17};
    REQUIRE(expected == meetup.third_sunday());
}

TEST_CASE("third_Sunday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 21};
    REQUIRE(expected == meetup.third_sunday());
}

TEST_CASE("fourth_Monday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 25};
    REQUIRE(expected == meetup.fourth_monday());
}

TEST_CASE("fourth_Monday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 22};
    REQUIRE(expected == meetup.fourth_monday());
}

TEST_CASE("fourth_Tuesday_of_May_2013")
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 28};
    REQUIRE(expected == meetup.fourth_tuesday());
}

TEST_CASE("fourth_Tuesday_of_June_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 25};
    REQUIRE(expected == meetup.fourth_tuesday());
}

TEST_CASE("fourth_Wednesday_of_July_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 24};
    REQUIRE(expected == meetup.fourth_wednesday());
}

TEST_CASE("fourth_Wednesday_of_August_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 28};
    REQUIRE(expected == meetup.fourth_wednesday());
}

TEST_CASE("fourth_Thursday_of_September_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 26};
    REQUIRE(expected == meetup.fourth_thursday());
}

TEST_CASE("fourth_Thursday_of_October_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 24};
    REQUIRE(expected == meetup.fourth_thursday());
}

TEST_CASE("fourth_Friday_of_November_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 22};
    REQUIRE(expected == meetup.fourth_friday());
}

TEST_CASE("fourth_Friday_of_December_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 27};
    REQUIRE(expected == meetup.fourth_friday());
}

TEST_CASE("fourth_Saturday_of_January_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 26};
    REQUIRE(expected == meetup.fourth_saturday());
}

TEST_CASE("fourth_Saturday_of_February_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 23};
    REQUIRE(expected == meetup.fourth_saturday());
}

TEST_CASE("fourth_Sunday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 24};
    REQUIRE(expected == meetup.fourth_sunday());
}

TEST_CASE("fourth_Sunday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 28};
    REQUIRE(expected == meetup.fourth_sunday());
}

TEST_CASE("last_Monday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 25};
    REQUIRE(expected == meetup.last_monday());
}

TEST_CASE("last_Monday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 29};
    REQUIRE(expected == meetup.last_monday());
}

TEST_CASE("last_Tuesday_of_May_2013")
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 28};
    REQUIRE(expected == meetup.last_tuesday());
}

TEST_CASE("last_Tuesday_of_June_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 25};
    REQUIRE(expected == meetup.last_tuesday());
}

TEST_CASE("last_Wednesday_of_July_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 31};
    REQUIRE(expected == meetup.last_wednesday());
}

TEST_CASE("last_Wednesday_of_August_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 28};
    REQUIRE(expected == meetup.last_wednesday());
}

TEST_CASE("last_Thursday_of_September_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 26};
    REQUIRE(expected == meetup.last_thursday());
}

TEST_CASE("last_Thursday_of_October_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 31};
    REQUIRE(expected == meetup.last_thursday());
}

TEST_CASE("last_Friday_of_November_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 29};
    REQUIRE(expected == meetup.last_friday());
}

TEST_CASE("last_Friday_of_December_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 27};
    REQUIRE(expected == meetup.last_friday());
}

TEST_CASE("last_Saturday_of_January_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 26};
    REQUIRE(expected == meetup.last_saturday());
}

TEST_CASE("last_Saturday_of_February_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 23};
    REQUIRE(expected == meetup.last_saturday());
}

TEST_CASE("last_Sunday_of_March_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 31};
    REQUIRE(expected == meetup.last_sunday());
}

TEST_CASE("last_Sunday_of_April_2013")
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 28};
    REQUIRE(expected == meetup.last_sunday());
}
#endif
