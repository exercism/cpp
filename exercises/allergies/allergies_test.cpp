#include "allergies.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(has_no_allergies)
{
    allergies::allergy_test test(0);
    
    BOOST_REQUIRE_EQUAL(false, test.is_allergic_to("peanuts"));
    BOOST_REQUIRE_EQUAL(false, test.is_allergic_to("cats"));
    BOOST_REQUIRE_EQUAL(false, test.is_allergic_to("strawberries"));
}

BOOST_AUTO_TEST_CASE(allergic_to_eggs)
{
    allergies::allergy_test test(1);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("eggs"));
}

BOOST_AUTO_TEST_CASE(allergic_to_peanuts)
{
    allergies::allergy_test test(2);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("peanuts"));
}

BOOST_AUTO_TEST_CASE(allergic_to_shellfish)
{
    allergies::allergy_test test(4);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("shellfish"));
}

BOOST_AUTO_TEST_CASE(allergic_to_strawberries)
{
    allergies::allergy_test test(8);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("strawberries"));
}

BOOST_AUTO_TEST_CASE(allergic_to_tomatoes)
{
    allergies::allergy_test test(16);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("tomatoes"));
}

BOOST_AUTO_TEST_CASE(allergic_to_chocolate)
{
    allergies::allergy_test test(32);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("chocolate"));
}

BOOST_AUTO_TEST_CASE(allergic_to_pollen)
{
    allergies::allergy_test test(64);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("pollen"));
}

BOOST_AUTO_TEST_CASE(allergic_to_cats)
{
    allergies::allergy_test test(128);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("cats"));
}

BOOST_AUTO_TEST_CASE(allergic_to_eggs_and_other_stuff)
{
    allergies::allergy_test test(5);
   
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("eggs"));
    BOOST_REQUIRE_EQUAL(true, test.is_allergic_to("shellfish"));
    BOOST_REQUIRE_EQUAL(false, test.is_allergic_to("peanuts"));
}


#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
