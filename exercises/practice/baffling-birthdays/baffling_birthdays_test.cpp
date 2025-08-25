#include "baffling_birthdays.h"

#include <boost/date_time/gregorian/gregorian.hpp>
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace baffling_birthdays;
using boost::gregorian::date;

TEST_CASE("one_birthdate", "[716dcc2b-8fe4-4fc9-8c48-cbe70d8e6b67]") {
    std::vector<date> dates{date(2000, 1, 1)};
    REQUIRE_FALSE(shared_birthday(dates));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("two_birthdates_with_same_year_month_and_day",
          "[f7b3eb26-bcfc-4e1e-a2de-af07afc33f45]") {
    std::vector<date> dates{date(2000, 1, 1), date(2000, 1, 1)};
    REQUIRE(shared_birthday(dates));
}

TEST_CASE("two_birthdates_with_same_year_and_month_but_different_day",
          "[7193409a-6e16-4bcb-b4cc-9ffe55f79b25]") {
    std::vector<date> dates{date(2012, 5, 9), date(2012, 5, 17)};
    REQUIRE_FALSE(shared_birthday(dates));
}

TEST_CASE("two_birthdates_with_same_month_and_day_but_different_year",
          "[d04db648-121b-4b72-93e8-d7d2dced4495]") {
    std::vector<date> dates{date(1999, 10, 23), date(1988, 10, 23)};
    REQUIRE(shared_birthday(dates));
}

TEST_CASE("two_birthdates_with_same_year_but_different_month_and_day",
          "[3c8bd0f0-14c6-4d4c-975a-4c636bfdc233]") {
    std::vector<date> dates{date(2007, 12, 19), date(2007, 4, 27)};
    REQUIRE_FALSE(shared_birthday(dates));
}

TEST_CASE("two_birthdates_with_different_year_month_and_day",
          "[df5daba6-0879-4480-883c-e855c99cdaa3]") {
    std::vector<date> dates{date(1997, 8, 4), date(1963, 11, 23)};
    REQUIRE_FALSE(shared_birthday(dates));
}

TEST_CASE("multiple_birthdates_without_shared_birthday",
          "[0c17b220-cbb9-4bd7-872f-373044c7b406]") {
    std::vector<date> dates{date(1966, 7, 29), date(1977, 2, 12),
                            date(2001, 12, 25), date(1980, 11, 10)};
    REQUIRE_FALSE(shared_birthday(dates));
}

TEST_CASE("multiple_birthdates_with_one_shared_birthday",
          "[966d6b0b-5c0a-4b8c-bc2d-64939ada49f8]") {
    std::vector<date> dates{date(1966, 7, 29), date(1977, 2, 12),
                            date(2001, 7, 29), date(1980, 11, 10)};
    REQUIRE(shared_birthday(dates));
}

TEST_CASE("multiple_birthdates_with_more_than_one_shared_birthday",
          "[b7937d28-403b-4500-acce-4d9fe3a9620d]") {
    std::vector<date> dates{date(1966, 7, 29), date(1977, 2, 12),
                            date(2001, 12, 25), date(1980, 7, 29),
                            date(2019, 2, 12)};
    REQUIRE(shared_birthday(dates));
}

TEST_CASE("generate_requested_number_of_birthdates",
          "[70b38cea-d234-4697-b146-7d130cd4ee12]") {
    const std::size_t group_size = 10;
    auto d_dates = random_birthdates(group_size);
    REQUIRE(d_dates.size() == group_size);
}

TEST_CASE("years_are_not_leap_years",
          "[d9d5b7d3-5fea-4752-b9c1-3fcd176d1b03]") {
    const std::size_t group_size = 1000;
    auto d_dates = random_birthdates(group_size);
    for (auto const& d : d_dates) {
        REQUIRE(!(d.month().as_number() == 2 && d.day() == 29));
    }
}

TEST_CASE("months_are_random", "[d1074327-f68c-4c8a-b0ff-e3730d0f0521]") {
    const std::size_t group_size = 1000;
    auto d1 = random_birthdates(group_size);
    auto d2 = random_birthdates(group_size);
    REQUIRE(d1 != d2);
}

TEST_CASE("days_are_random", "[7df706b3-c3f5-471d-9563-23a4d0577940]") {
    const std::size_t group_size = 1000;
    auto d1 = random_birthdates(group_size);
    auto d2 = random_birthdates(group_size);
    REQUIRE(d1 != d2);
}

TEST_CASE("for_one_person", "[89a462a4-4265-4912-9506-fb027913f221]") {
    REQUIRE(estimated_probability_of_shared_birthday(1) == Approx(0.0));
}

TEST_CASE("among_ten_people", "[ec31c787-0ebb-4548-970c-5dcb4eadfb5f]") {
    REQUIRE(estimated_probability_of_shared_birthday(10) ==
            Approx(11.694818).epsilon(0.01));
}

TEST_CASE("among_twenty-three_people",
          "[b548afac-a451-46a3-9bb0-cb1f60c48e2f]") {
    REQUIRE(estimated_probability_of_shared_birthday(23) ==
            Approx(50.729723).epsilon(0.01));
}

TEST_CASE("among_seventy_people", "[e43e6b9d-d77b-4f6c-a960-0fc0129a0bc5]") {
    REQUIRE(estimated_probability_of_shared_birthday(70) ==
            Approx(99.915958).epsilon(0.01));
}

#endif