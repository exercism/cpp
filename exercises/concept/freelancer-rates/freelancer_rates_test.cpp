#include "freelancer_rates.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("it's the hourly_rate times 8", "[task_1]") { REQUIRE(daily_rate(50) == 400.0); }

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("it always returns a float", "[task_1]") { REQUIRE(daily_rate(60) == 480.0); }

TEST_CASE("it does not round", "[task_1]") { REQUIRE(daily_rate(55.1) == 440.8); }

TEST_CASE("a discount of 10 percent leaves 90 percent of the original price", "[task_2]") {
    REQUIRE(apply_discount(140.0, 10) == 126.0);
}

TEST_CASE("it doesn't round", "[task_2]") {
    // If unsure about the syntax of this test see:
    // https://github.com/catchorg/Catch2/blob/devel/docs/comparing-floating-point-numbers.md#withinrel
    REQUIRE_THAT(apply_discount(111.11, 13.5),
                 Catch::Matchers::WithinRel(96.11015, 0.000001));
}

TEST_CASE("it's the daily_rate times 22", "[task_3]") {
    REQUIRE(monthly_rate(62, 0.0) == 10'912);
}

TEST_CASE("the result is rounded up", "[task_3]") {
    // 11_052.8
    REQUIRE(monthly_rate(62.8, 0.0) == 11'053);
    // 11_475.2
    REQUIRE(monthly_rate(65.2, 0.0) == 11'476);
}

TEST_CASE("gives a discount", "[task_3]") {
    // 11'792 - 12% * 11_792 = 10'376.96
    REQUIRE(monthly_rate(67, 12.0) == 10'377);
}

TEST_CASE("it's the budget divided by the daily rate", "[task_4]") {
    REQUIRE(days_in_budget(1'600, 50, 0.0) == 4);
}

TEST_CASE("it rounds down to next decimal place", "[task_4]") {
    //  9.97727
    REQUIRE(days_in_budget(4'390, 55, 0.0) == 9);
    // 10.18182
    REQUIRE(days_in_budget(4'480, 55, 0.0) == 10);
}

TEST_CASE("it applies the discount", "[task_4]") {
    // Without discount: 0.8
    // With discount: 1.07
    REQUIRE(days_in_budget(480, 70, 20) == 1);
}

#endif
