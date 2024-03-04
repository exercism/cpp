#include "lasagna_master.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace lasagna_master;

// As long as we have catch2 v2 and v3 in parallel, we can't use either
//  of their comparison marcors for floating point comparisons.
#define REQUIRE_VECTOR_APROX_EQUAL(vec1, vec2, margin)  \
    REQUIRE(vec1.size() == vec2.size());                \
    for (size_t i = 0; i < vec1.size(); i++) {          \
        REQUIRE( vec1.at(i) - vec2.at(i) < margin);     \
    } 

TEST_CASE("preparationTime: Preparation time for many layers with custom average time", "[task_1]") {
    std::vector<std::string> layers{
        "sauce",
        "noodles",
        "béchamel",
        "meat",
        "mozzarella",
        "noodles",
        "ricotta",
        "eggplant",
        "béchamel",
        "noodles",
        "sauce",
        "mozzarella",
    };
    int time{1};
    int expected{12};
    REQUIRE(preparationTime(layers, time) == expected);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("preparationTime: Preparation time for few layers", "[task_1]") {
    std::vector<std::string> layers{
        "sauce",
        "noodles",
    };
    int time{3};
    int expected{6};
    REQUIRE(preparationTime(layers, time) == expected);
}

TEST_CASE("preparationTime: Preparation time for default case", "[task_1]") {
    std::vector<std::string> layers{
        "sauce",
        "noodles",
    };
    int expected{4};
    REQUIRE(preparationTime(layers) == expected);
}

TEST_CASE("quantities: few layers", "[task_2]") {
    std::vector<std::string> layers {"noodles", "sauce", "noodles"};
    int expNoodles{100};
    double expSauce{0.2};
    amount amount = quantities(layers);
    REQUIRE(amount.sauce == expSauce);
    REQUIRE(amount.noodles == expNoodles);
}

TEST_CASE("quantities: many layers", "[task_2]") {
    std::vector<std::string> layers{
        "sauce",
        "noodles",
        "béchamel",
        "meat",
        "mozzarella",
        "noodles",
        "ricotta",
        "eggplant",
        "béchamel",
        "noodles",
        "sauce",
        "mozzarella"};
    int expNoodles{150};
    double expSauce{0.4};
    amount amount = quantities(layers);
    REQUIRE(amount.sauce == expSauce);
    REQUIRE(amount.noodles == expNoodles);
}

TEST_CASE("quantities: no noodles", "[task_2]") {
    std::vector<std::string> layers{
        "sauce",
        "meat",
        "mozzarella",
        "sauce",
        "mozzarella"};
    int expNoodles{0};
    double expSauce{0.4};
    amount amount = quantities(layers);
    REQUIRE(amount.sauce == expSauce);
    REQUIRE(amount.noodles == expNoodles);
}

TEST_CASE("quantities: no sauce", "[task_2]") {
    std::vector<std::string> layers{
        "noodles",
        "meat",
        "mozzarella",
        "noodles",
        "mozzarella"};
    int expNoodles{100};
    double expSauce{0.0};
    amount amount = quantities(layers);
    REQUIRE(amount.sauce == expSauce);
    REQUIRE(amount.noodles == expNoodles);
}

TEST_CASE("Adds secret vector ingredient", "[task_3]") {
    const std::vector<std::string> friendsList{"sauce", "noodles", "béchamel", "marjoram"};
    std::vector<std::string> myList{"sauce", "noodles", "meat", "tomatoes", "?"};
    std::vector<std::string> expected{"sauce", "noodles", "meat", "tomatoes", "marjoram"};
    addSecretIngredient(myList, friendsList);
    REQUIRE(myList == expected);
}

TEST_CASE("scaledQuantities: scales up correctly", "[task_4]") {
    const std::vector<double> input{0.5, 250, 150, 3, 0.5};
    int portions{6};
    std::vector<double> expected{1.5, 750, 450, 9, 1.5};
    std::vector<double> scaled{scaledQuantities(input, portions)};
    REQUIRE_VECTOR_APROX_EQUAL(expected, scaled, 0.0001)
}

TEST_CASE("scaledQuantities: scales up correctly (2)", "[task_4]") {
    const std::vector<double> input{0.6, 300, 1, 0.5, 50, 0.1, 100};
    int portions{3};
    std::vector<double> expected{0.9, 450, 1.5, 0.75, 75, 0.15, 150};
    std::vector<double> scaled{scaledQuantities(input, portions)};
    REQUIRE_VECTOR_APROX_EQUAL(expected, scaled, 0.0001)
}

TEST_CASE("scaledQuantities: scales down correctly", "[task_4]") {
    const std::vector<double> input{0.5, 250, 150, 3, 0.5};
    int portions{1};
    std::vector<double> expected{0.25, 125, 75, 1.5, 0.25};
    std::vector<double> scaled{scaledQuantities(input, portions)};
    REQUIRE_VECTOR_APROX_EQUAL(expected, scaled, 0.0001)
}

TEST_CASE("scaledQuantities: empty recipe", "[task_4]") {
    const std::vector<double> input{};  
    int portions{100};
    std::vector<double> expected{};
    std::vector<double> scaled{scaledQuantities(input, portions)};
    REQUIRE_VECTOR_APROX_EQUAL(expected, scaled, 0.0001)
}

TEST_CASE("Adds secret string ingredient", "[task_5]") {
    const std::string auntiesSecret{"mirkwood mushrooms"};
    std::vector<std::string> myList{"sauce", "noodles", "meat", "tomatoes", "?"};
    std::vector<std::string> expected{"sauce", "noodles", "meat", "tomatoes", "mirkwood mushrooms"};
    addSecretIngredient(myList, auntiesSecret);
    REQUIRE(myList == expected);
}

#endif
