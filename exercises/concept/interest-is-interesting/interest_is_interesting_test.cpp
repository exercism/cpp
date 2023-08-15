#include "interest_is_interesting.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("Minimal first interest rate", "[task_1]") {
    double balance{0};
    double want{0.5};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Tiny first interest rate", "[task_1]") {
    double balance{0.000001};
    double want{0.5};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Maximum first interest rate", "[task_1]") {
    double balance{999.9999};
    double want{0.5};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Minimal second interest rate", "[task_1]") {
    double balance{1000.0};
    double want{1.621};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Tiny second interest rate", "[task_1]") {
    double balance{1000.0001};
    double want{1.621};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Maximum second interest rate", "[task_1]") {
    double balance{4999.9990};
    double want{1.621};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Minimal third interest rate", "[task_1]") {
    double balance{5000.0000};
    double want{2.475};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Tiny third interest rate", "[task_1]") {
    double balance{5000.0001};
    double want{2.475};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Large third interest rate", "[task_1]") {
    double balance{5639998.742909};
    double want{2.475};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Rate on minimal negative balance", "[task_1]") {
    double balance{-0.000001};
    double want{3.213};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Rate on small negative balance", "[task_1]") {
    double balance{-0.123};
    double want{3.213};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Rate on regular negative balance", "[task_1]") {
    double balance{-300.0};
    double want{3.213};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Rate on large negative balance", "[task_1]") {
    double balance{-152964.231};
    double want{3.213};
    REQUIRE_THAT(interest_rate(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Interest on negative balance", "[task_2]") {
    double balance{-10000.0};
    double want{-321.3};
    REQUIRE_THAT(yearly_interest(balance), Catch::Matchers::WithinRel(want, 0.000001));
}
TEST_CASE("Interest on small balance", "[task_2]") {
    double balance{555.43};
    double want{2.77715};
    REQUIRE_THAT(yearly_interest(balance), Catch::Matchers::WithinRel(want, 0.000001));
}
TEST_CASE("Interest on medium balance", "[task_2]") {
    double balance{4999.99};
    double want{81.0498379};
    REQUIRE_THAT(yearly_interest(balance), Catch::Matchers::WithinRel(want, 0.000001));
}
TEST_CASE("Interest on large balance", "[task_2]") {
    double balance{34600.80};
    double want{856.3698};
    REQUIRE_THAT(yearly_interest(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Annual balance update for empty start balance", "[task_3]") {
    double balance{0.0};
    double want{0.0000};
    REQUIRE_THAT(annual_balance_update(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Annual balance update for small positive start balance", "[task_3]") {
    double balance{0.000001};
    double want{0.000001005};
    REQUIRE_THAT(annual_balance_update(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Annual balance update for average positive start balance", "[task_3]") {
    double balance{1000.0};
    double want{1016.210000};
    REQUIRE_THAT(annual_balance_update(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Annual balance update for large positive start balance", "[task_3]") {
    double balance{1000.2001};
    double want{1016.413343621};
    REQUIRE_THAT(annual_balance_update(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Annual balance update for huge positive start balance", "[task_3]") {
    double balance{898124017.826243404425};
    double want{920352587.2674429417};
    REQUIRE_THAT(annual_balance_update(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Annual balance update for small negative start balance", "[task_3]") {
    double balance{-0.123};
    double want{-0.12695199};
    REQUIRE_THAT(annual_balance_update(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Annual balance update for large negative start balance", "[task_3]") {
    double balance{-152964.231};
    double want{-157878.97174203};
    REQUIRE_THAT(annual_balance_update(balance), Catch::Matchers::WithinRel(want, 0.000001));
}

TEST_CASE("Years before desired balance for small start balance", "[task_4]") {
    double balance{100.0};
    double target_balance{125.80};
    int want{47};
    REQUIRE(years_until_desired_balance(balance, target_balance) == want);
}
TEST_CASE("Years before desired balance for average start balance", "[task_4]") {
    double balance{1000.0};
    double target_balance{1100.0};
    int want{6};
    REQUIRE(years_until_desired_balance(balance, target_balance) == want);
}
TEST_CASE("Years before desired balance for large start balance", "[task_4]") {
    double balance{8080.80};
    double target_balance{9090.90};
    int want{5};
    REQUIRE(years_until_desired_balance(balance, target_balance) == want);
}
TEST_CASE("Years before large difference between start and target balance", "[task_4]") {
    double balance{2345.67};
    double target_balance{12345.6789};
    int want{85};
    REQUIRE(years_until_desired_balance(balance, target_balance) == want);
}
TEST_CASE("Balance is already above target", "[task_4]") {
    double balance{2345.67};
    double target_balance{2345.0};
    int want{0};
    REQUIRE(years_until_desired_balance(balance, target_balance) == want);
}
TEST_CASE("Balance is exactly same as target", "[task_4]") {
    double balance{2345.0};
    double target_balance{2345.0};
    int want{0};
    REQUIRE(years_until_desired_balance(balance, target_balance) == want);
}
TEST_CASE("Result balance would be exactly same as target", "[task_4]") {
    double balance{1000.0};
    double target_balance{1032.6827641};
    int want{2};
    REQUIRE(years_until_desired_balance(balance, target_balance) == want);
}

#endif
