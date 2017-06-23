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
#if defined(EXERCISM_RUN_ALL_TESTS)
#endif
