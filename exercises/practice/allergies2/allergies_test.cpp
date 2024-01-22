#include "allergies.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

#include <string>
#include <unordered_set>

TEST_CASE("no_allergies_means_not_allergic")
{
    allergies::allergy_test score(0);
    
    REQUIRE(false == score.is_allergic_to("peanuts"));
    REQUIRE(false == score.is_allergic_to("cats"));
    REQUIRE(false == score.is_allergic_to("strawberries"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("allergic_to_eggs")
{
    allergies::allergy_test score(1);
   
    REQUIRE(true == score.is_allergic_to("eggs"));
}

TEST_CASE("allergic_to_peanuts")
{
    allergies::allergy_test score(2);
   
    REQUIRE(true == score.is_allergic_to("peanuts"));
}

TEST_CASE("allergic_to_shellfish")
{
    allergies::allergy_test score(4);
   
    REQUIRE(true == score.is_allergic_to("shellfish"));
}

TEST_CASE("allergic_to_strawberries")
{
    allergies::allergy_test score(8);
   
    REQUIRE(true == score.is_allergic_to("strawberries"));
}

TEST_CASE("allergic_to_tomatoes")
{
    allergies::allergy_test score(16);
   
    REQUIRE(true == score.is_allergic_to("tomatoes"));
}

TEST_CASE("allergic_to_chocolate")
{
    allergies::allergy_test score(32);
   
    REQUIRE(true == score.is_allergic_to("chocolate"));
}

TEST_CASE("allergic_to_pollen")
{
    allergies::allergy_test score(64);
   
    REQUIRE(true == score.is_allergic_to("pollen"));
}

TEST_CASE("allergic_to_cats")
{
    allergies::allergy_test score(128);
   
    REQUIRE(true == score.is_allergic_to("cats"));
}

TEST_CASE("allergic_to_eggs_and_other_stuff")
{
    allergies::allergy_test score(5);
   
    REQUIRE(true == score.is_allergic_to("eggs"));
    REQUIRE(true == score.is_allergic_to("shellfish"));
    REQUIRE(false == score.is_allergic_to("peanuts"));
}

TEST_CASE("allergic_to_nothing")
{
    allergies::allergy_test score(0);
    const std::unordered_set<std::string> no_allergies{};

    REQUIRE(no_allergies == score.get_allergies());
}

TEST_CASE("allergic_to_only_peanuts")
{
    allergies::allergy_test score(2);
    const std::unordered_set<std::string> only_peanuts = {"peanuts"};

    REQUIRE(only_peanuts == score.get_allergies());
}

TEST_CASE("allergic_to_only_strawberries")
{
    allergies::allergy_test score(8);
    const std::unordered_set<std::string> only_strawberries = {"strawberries"};

    REQUIRE(only_strawberries == score.get_allergies());
}

TEST_CASE("allergic_to_eggs_and_peanuts")
{
    allergies::allergy_test score(3);
    const std::unordered_set<std::string> eggs_peanuts = {"eggs", "peanuts"};

    REQUIRE(eggs_peanuts == score.get_allergies());
}

TEST_CASE("allergic_to_more_than_eggs_but_not_peanuts")
{
    allergies::allergy_test score(5);
    const std::unordered_set<std::string> eggs_shellfish = {"eggs", "shellfish"};

    REQUIRE(eggs_shellfish == score.get_allergies());
}

TEST_CASE("allergic_to_lots_of_stuff")
{
    allergies::allergy_test score(248);
    const std::unordered_set<std::string> lots_of_stuff = {"strawberries", "tomatoes", "chocolate", "pollen", "cats"};

    REQUIRE(lots_of_stuff == score.get_allergies());
}

TEST_CASE("allergic_to_everything")
{
    allergies::allergy_test score(255);
    const std::unordered_set<std::string> everything = {"eggs", "peanuts", "shellfish", "strawberries",
                                                        "tomatoes", "chocolate", "pollen", "cats"}; 

    REQUIRE(everything == score.get_allergies());
}

TEST_CASE("ignore_non_allergen_score_parts")
{
    allergies::allergy_test score(509);
    const std::unordered_set<std::string> non_allergen = {"eggs", "shellfish", "strawberries", "tomatoes",
                                                          "chocolate", "pollen", "cats"};

    REQUIRE(non_allergen == score.get_allergies());
}
#endif
