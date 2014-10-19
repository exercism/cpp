#include "meetup.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

// See <http://www.boost.org/doc/libs/1_55_0/doc/html/date_time.html>
// for documentation on boost::gregorian::date

BOOST_AUTO_TEST_CASE(monteenth_of_May_2013)
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 13};
    BOOST_REQUIRE_EQUAL(expected, meetup.monteenth());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(monteenth_of_August_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.monteenth());
}

BOOST_AUTO_TEST_CASE(monteenth_of_September_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 16};
    BOOST_REQUIRE_EQUAL(expected, meetup.monteenth());
}

BOOST_AUTO_TEST_CASE(tuesteenth_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.tuesteenth());
}

BOOST_AUTO_TEST_CASE(tuesteenth_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 16};
    BOOST_REQUIRE_EQUAL(expected, meetup.tuesteenth());
}

BOOST_AUTO_TEST_CASE(tuesteenth_of_August_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 13};
    BOOST_REQUIRE_EQUAL(expected, meetup.tuesteenth());
}

BOOST_AUTO_TEST_CASE(wednesteenth_of_January_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 16};
    BOOST_REQUIRE_EQUAL(expected, meetup.wednesteenth());
}

BOOST_AUTO_TEST_CASE(wednesteenth_of_February_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 13};
    BOOST_REQUIRE_EQUAL(expected, meetup.wednesteenth());
}

BOOST_AUTO_TEST_CASE(wednesteenth_of_June_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.wednesteenth());
}

BOOST_AUTO_TEST_CASE(thursteenth_of_May_2013)
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 16};
    BOOST_REQUIRE_EQUAL(expected, meetup.thursteenth());
}

BOOST_AUTO_TEST_CASE(thursteenth_of_June_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 13};
    BOOST_REQUIRE_EQUAL(expected, meetup.thursteenth());
}

BOOST_AUTO_TEST_CASE(thursteenth_of_September_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.thursteenth());
}

BOOST_AUTO_TEST_CASE(friteenth_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.friteenth());
}

BOOST_AUTO_TEST_CASE(friteenth_of_Aug_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 16};
    BOOST_REQUIRE_EQUAL(expected, meetup.friteenth());
}

BOOST_AUTO_TEST_CASE(friteenth_of_September_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 13};
    BOOST_REQUIRE_EQUAL(expected, meetup.friteenth());
}

BOOST_AUTO_TEST_CASE(saturteenth_of_February_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 16};
    BOOST_REQUIRE_EQUAL(expected, meetup.saturteenth());
}

BOOST_AUTO_TEST_CASE(saturteenth_of_October_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.saturteenth());
}

BOOST_AUTO_TEST_CASE(sunteenth_of_May_2013)
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.sunteenth());
}

BOOST_AUTO_TEST_CASE(sunteenth_of_June_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 16};
    BOOST_REQUIRE_EQUAL(expected, meetup.sunteenth());
}

BOOST_AUTO_TEST_CASE(sunteenth_of_October_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 13};
    BOOST_REQUIRE_EQUAL(expected, meetup.sunteenth());
}

BOOST_AUTO_TEST_CASE(first_Monday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 4};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_monday());
}

BOOST_AUTO_TEST_CASE(first_Monday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 1};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_monday());
}

BOOST_AUTO_TEST_CASE(first_Tuesday_of_May_2013)
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 7};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_tuesday());
}

BOOST_AUTO_TEST_CASE(first_Tuesday_of_June_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 4};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_tuesday());
}

BOOST_AUTO_TEST_CASE(first_Wednesday_of_July_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 3};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_wednesday());
}

BOOST_AUTO_TEST_CASE(first_Wednesday_of_August_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 7};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_wednesday());
}

BOOST_AUTO_TEST_CASE(first_Thursday_of_September_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 5};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_thursday());
}

BOOST_AUTO_TEST_CASE(first_Thursday_of_October_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 3};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_thursday());
}

BOOST_AUTO_TEST_CASE(first_Friday_of_November_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 1};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_friday());
}

BOOST_AUTO_TEST_CASE(first_Friday_of_December_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 6};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_friday());
}

BOOST_AUTO_TEST_CASE(first_Saturday_of_January_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 5};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_saturday());
}

BOOST_AUTO_TEST_CASE(first_Saturday_of_February_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 2};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_saturday());
}

BOOST_AUTO_TEST_CASE(first_Sunday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 3};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_sunday());
}

BOOST_AUTO_TEST_CASE(first_Sunday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 7};
    BOOST_REQUIRE_EQUAL(expected, meetup.first_sunday());
}

BOOST_AUTO_TEST_CASE(second_Monday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 11};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_monday());
}

BOOST_AUTO_TEST_CASE(second_Monday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 8};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_monday());
}

BOOST_AUTO_TEST_CASE(second_Tuesday_of_May_2013)
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 14};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_tuesday());
}

BOOST_AUTO_TEST_CASE(second_Tuesday_of_June_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 11};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_tuesday());
}

BOOST_AUTO_TEST_CASE(second_Wednesday_of_July_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 10};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_wednesday());
}

BOOST_AUTO_TEST_CASE(second_Wednesday_of_August_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 14};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_wednesday());
}

BOOST_AUTO_TEST_CASE(second_Thursday_of_September_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 12};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_thursday());
}

BOOST_AUTO_TEST_CASE(second_Thursday_of_October_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 10};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_thursday());
}

BOOST_AUTO_TEST_CASE(second_Friday_of_November_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 8};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_friday());
}

BOOST_AUTO_TEST_CASE(second_Friday_of_December_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 13};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_friday());
}

BOOST_AUTO_TEST_CASE(second_Saturday_of_January_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 12};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_saturday());
}

BOOST_AUTO_TEST_CASE(second_Saturday_of_February_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 9};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_saturday());
}

BOOST_AUTO_TEST_CASE(second_Sunday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 10};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_sunday());
}

BOOST_AUTO_TEST_CASE(second_Sunday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 14};
    BOOST_REQUIRE_EQUAL(expected, meetup.second_sunday());
}

BOOST_AUTO_TEST_CASE(third_Monday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 18};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_monday());
}

BOOST_AUTO_TEST_CASE(third_Monday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 15};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_monday());
}

BOOST_AUTO_TEST_CASE(third_Tuesday_of_May_2013)
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 21};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_tuesday());
}

BOOST_AUTO_TEST_CASE(third_Tuesday_of_June_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 18};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_tuesday());
}

BOOST_AUTO_TEST_CASE(third_Wednesday_of_July_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 17};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_wednesday());
}

BOOST_AUTO_TEST_CASE(third_Wednesday_of_August_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 21};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_wednesday());
}

BOOST_AUTO_TEST_CASE(third_Thursday_of_September_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_thursday());
}

BOOST_AUTO_TEST_CASE(third_Thursday_of_October_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 17};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_thursday());
}

BOOST_AUTO_TEST_CASE(third_Friday_of_November_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 15};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_friday());
}

BOOST_AUTO_TEST_CASE(third_Friday_of_December_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 20};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_friday());
}

BOOST_AUTO_TEST_CASE(third_Saturday_of_January_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 19};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_saturday());
}

BOOST_AUTO_TEST_CASE(third_Saturday_of_February_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 16};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_saturday());
}

BOOST_AUTO_TEST_CASE(third_Sunday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 17};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_sunday());
}

BOOST_AUTO_TEST_CASE(third_Sunday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 21};
    BOOST_REQUIRE_EQUAL(expected, meetup.third_sunday());
}

BOOST_AUTO_TEST_CASE(fourth_Monday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 25};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_monday());
}

BOOST_AUTO_TEST_CASE(fourth_Monday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 22};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_monday());
}

BOOST_AUTO_TEST_CASE(fourth_Tuesday_of_May_2013)
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 28};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_tuesday());
}

BOOST_AUTO_TEST_CASE(fourth_Tuesday_of_June_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 25};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_tuesday());
}

BOOST_AUTO_TEST_CASE(fourth_Wednesday_of_July_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 24};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_wednesday());
}

BOOST_AUTO_TEST_CASE(fourth_Wednesday_of_August_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 28};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_wednesday());
}

BOOST_AUTO_TEST_CASE(fourth_Thursday_of_September_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 26};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_thursday());
}

BOOST_AUTO_TEST_CASE(fourth_Thursday_of_October_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 24};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_thursday());
}

BOOST_AUTO_TEST_CASE(fourth_Friday_of_November_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 22};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_friday());
}

BOOST_AUTO_TEST_CASE(fourth_Friday_of_December_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 27};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_friday());
}

BOOST_AUTO_TEST_CASE(fourth_Saturday_of_January_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 26};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_saturday());
}

BOOST_AUTO_TEST_CASE(fourth_Saturday_of_February_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 23};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_saturday());
}

BOOST_AUTO_TEST_CASE(fourth_Sunday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 24};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_sunday());
}

BOOST_AUTO_TEST_CASE(fourth_Sunday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 28};
    BOOST_REQUIRE_EQUAL(expected, meetup.fourth_sunday());
}

BOOST_AUTO_TEST_CASE(last_Monday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 25};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_monday());
}

BOOST_AUTO_TEST_CASE(last_Monday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 29};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_monday());
}

BOOST_AUTO_TEST_CASE(last_Tuesday_of_May_2013)
{
    const meetup::scheduler meetup{boost::gregorian::May, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::May, 28};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_tuesday());
}

BOOST_AUTO_TEST_CASE(last_Tuesday_of_June_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jun, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jun, 25};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_tuesday());
}

BOOST_AUTO_TEST_CASE(last_Wednesday_of_July_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jul, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jul, 31};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_wednesday());
}

BOOST_AUTO_TEST_CASE(last_Wednesday_of_August_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Aug, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Aug, 28};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_wednesday());
}

BOOST_AUTO_TEST_CASE(last_Thursday_of_September_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Sep, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Sep, 26};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_thursday());
}

BOOST_AUTO_TEST_CASE(last_Thursday_of_October_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Oct, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Oct, 31};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_thursday());
}

BOOST_AUTO_TEST_CASE(last_Friday_of_November_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Nov, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Nov, 29};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_friday());
}

BOOST_AUTO_TEST_CASE(last_Friday_of_December_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Dec, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Dec, 27};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_friday());
}

BOOST_AUTO_TEST_CASE(last_Saturday_of_January_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Jan, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Jan, 26};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_saturday());
}

BOOST_AUTO_TEST_CASE(last_Saturday_of_February_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Feb, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Feb, 23};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_saturday());
}

BOOST_AUTO_TEST_CASE(last_Sunday_of_March_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Mar, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Mar, 31};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_sunday());
}

BOOST_AUTO_TEST_CASE(last_Sunday_of_April_2013)
{
    const meetup::scheduler meetup{boost::gregorian::Apr, 2013};

    const boost::gregorian::date expected{2013, boost::gregorian::Apr, 28};
    BOOST_REQUIRE_EQUAL(expected, meetup.last_sunday());
}
#endif
