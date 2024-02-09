
#include "vehicle_purchase.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("need a license for a car", "[task_1]") {
    std::string kind{"car"};
    REQUIRE(vehicle_purchase::needs_license(kind));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("need a license for a truck", "[task_1]") {
    std::string kind{"truck"};
    REQUIRE(vehicle_purchase::needs_license(kind));
}
TEST_CASE("does not need a license for a bike", "[task_1]") {
    std::string kind{"bike"};
    REQUIRE_FALSE(vehicle_purchase::needs_license(kind));
}
TEST_CASE("does not need a license for a stroller", "[task_1]") {
    std::string kind{"stroller"};
    REQUIRE_FALSE(vehicle_purchase::needs_license(kind));
}
TEST_CASE("does not need a license for a e-scooter", "[task_1]") {
    std::string kind{"e-scooter"};
    REQUIRE_FALSE(vehicle_purchase::needs_license(kind));
}

TEST_CASE("chooses Bugatti over Ford", "[task_2]") {
    std::string choice1{"Bugatti Veyron"};
    std::string choice2{"Ford Pinto"};
    REQUIRE(vehicle_purchase::choose_vehicle(choice1, choice2) ==
            "Bugatti Veyron is clearly the better choice.");
}
TEST_CASE("chooses Chery over Kia", "[task_2]") {
    std::string choice1{"Kia Niro Elektro"};
    std::string choice2{"Chery EQ"};
    REQUIRE(vehicle_purchase::choose_vehicle(choice1, choice2) ==
            "Chery EQ is clearly the better choice.");
}
TEST_CASE("chooses Ford Focus over Ford Pinto", "[task_2]") {
    std::string choice1{"Ford Focus"};
    std::string choice2{"Ford Pinto"};
    REQUIRE(vehicle_purchase::choose_vehicle(choice1, choice2) ==
            "Ford Focus is clearly the better choice.");
}
TEST_CASE("chooses 2018 over 2020", "[task_2]") {
    std::string choice1{"2020 Gazelle Medeo"};
    std::string choice2{"2018 Bergamont City"};
    REQUIRE(vehicle_purchase::choose_vehicle(choice1, choice2) ==
            "2018 Bergamont City is clearly the better choice.");
}
TEST_CASE("chooses Bugatti over ford", "[task_2]") {
    std::string choice1{"Bugatti Veyron"};
    std::string choice2{"ford"};
    REQUIRE(vehicle_purchase::choose_vehicle(choice1, choice2) ==
            "Bugatti Veyron is clearly the better choice.");
}

TEST_CASE("price is reduced to 80% for age of 2", "[task_3]") {
    double original_price{40000};
    double age{2};
    double expected{32000};
    REQUIRE(vehicle_purchase::calculate_resell_price(original_price, age) ==
            expected);
}
TEST_CASE("price is reduced to 80% for age of 2.5", "[task_3]") {
    double original_price{40000};
    double age{2.5};
    double expected{32000};
    REQUIRE(vehicle_purchase::calculate_resell_price(original_price, age) ==
            expected);
}
TEST_CASE("price is reduced to 70% for age 7", "[task_3]") {
    double original_price{40000};
    double age{7};
    double expected{28000};
    REQUIRE(vehicle_purchase::calculate_resell_price(original_price, age) ==
            expected);
}
TEST_CASE("price is reduced to 50% for age 10", "[task_3]") {
    double original_price{25000};
    double age{10};
    double expected{12500};
    REQUIRE(vehicle_purchase::calculate_resell_price(original_price, age) ==
            expected);
}
TEST_CASE("price is reduced to 50% for age 11", "[task_3]") {
    double original_price{50000};
    double age{11};
    double expected{25000};
    REQUIRE(vehicle_purchase::calculate_resell_price(original_price, age) ==
            expected);
}
TEST_CASE("float price is reduced to 70% for age 8,", "[task_3]") {
    double original_price{39000.000001};
    double age{8};
    double expected{27300.0000007};
    REQUIRE_THAT(vehicle_purchase::calculate_resell_price(original_price, age), Catch::Matchers::WithinRel(expected, 0.001));
}

#endif
