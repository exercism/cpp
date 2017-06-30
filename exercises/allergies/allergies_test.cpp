#include "allergies.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <string>
#include <unordered_set>

BOOST_AUTO_TEST_CASE(no_allergies_means_not_allergic)
{
    allergies::allergy_test score(0);
    
    BOOST_REQUIRE_EQUAL(false, score.is_allergic_to("peanuts"));
    BOOST_REQUIRE_EQUAL(false, score.is_allergic_to("cats"));
    BOOST_REQUIRE_EQUAL(false, score.is_allergic_to("strawberries"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(allergic_to_eggs)
{
    allergies::allergy_test score(1);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("eggs"));
}

BOOST_AUTO_TEST_CASE(allergic_to_peanuts)
{
    allergies::allergy_test score(2);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("peanuts"));
}

BOOST_AUTO_TEST_CASE(allergic_to_shellfish)
{
    allergies::allergy_test score(4);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("shellfish"));
}

BOOST_AUTO_TEST_CASE(allergic_to_strawberries)
{
    allergies::allergy_test score(8);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("strawberries"));
}

BOOST_AUTO_TEST_CASE(allergic_to_tomatoes)
{
    allergies::allergy_test score(16);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("tomatoes"));
}

BOOST_AUTO_TEST_CASE(allergic_to_chocolate)
{
    allergies::allergy_test score(32);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("chocolate"));
}

BOOST_AUTO_TEST_CASE(allergic_to_pollen)
{
    allergies::allergy_test score(64);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("pollen"));
}

BOOST_AUTO_TEST_CASE(allergic_to_cats)
{
    allergies::allergy_test score(128);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("cats"));
}

BOOST_AUTO_TEST_CASE(allergic_to_eggs_and_other_stuff)
{
    allergies::allergy_test score(5);
   
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("eggs"));
    BOOST_REQUIRE_EQUAL(true, score.is_allergic_to("shellfish"));
    BOOST_REQUIRE_EQUAL(false, score.is_allergic_to("peanuts"));
}

BOOST_AUTO_TEST_CASE(allergic_to_nothing)
{
    allergies::allergy_test score(0);
    const std::unordered_set<std::string> no_allergies;

    BOOST_TEST(no_allergies == score.get_allergies());
}

BOOST_AUTO_TEST_CASE(allergic_to_only_peanuts)
{
    allergies::allergy_test score(2);
    const std::unordered_set<std::string> only_peanuts = {"peanuts"};

    BOOST_TEST(only_peanuts == score.get_allergies());
}

BOOST_AUTO_TEST_CASE(allergic_to_only_strawberries)
{
    allergies::allergy_test score(8);
    const std::unordered_set<std::string> only_strawberries = {"strawberries"};

    BOOST_TEST(only_strawberries == score.get_allergies());
}

BOOST_AUTO_TEST_CASE(allergic_to_eggs_and_peanuts)
{
    allergies::allergy_test score(3);
    const std::unordered_set<std::string> eggs_peanuts = {"eggs", "peanuts"};

    BOOST_TEST(eggs_peanuts == score.get_allergies());
}

BOOST_AUTO_TEST_CASE(allergic_to_more_than_eggs_but_not_peanuts)
{
    allergies::allergy_test score(5);
    const std::unordered_set<std::string> eggs_shellfish = {"eggs", "shellfish"};

    BOOST_TEST(eggs_shellfish == score.get_allergies());
}

BOOST_AUTO_TEST_CASE(allergic_to_lots_of_stuff)
{
    allergies::allergy_test score(248);
    const std::unordered_set<std::string> lots_of_stuff = {"strawberries", "tomatoes", "chocolate", "pollen", "cats"};

    BOOST_TEST(lots_of_stuff == score.get_allergies());
}

BOOST_AUTO_TEST_CASE(allergic_to_everything)
{
    allergies::allergy_test score(255);
    const std::unordered_set<std::string> everything = {"eggs", "peanuts", "shellfish", "strawberries",
                                                        "tomatoes", "chocolate", "pollen", "cats"}; 

    BOOST_TEST(everything == score.get_allergies());
}

BOOST_AUTO_TEST_CASE(ignore_non_allergen_score_parts)
{
    allergies::allergy_test score(509);
    const std::unordered_set<std::string> non_allergen = {"eggs", "shellfish", "strawberries", "tomatoes",
                                                          "chocolate", "pollen", "cats"};

    BOOST_TEST(non_allergen == score.get_allergies());
}
#endif
