#include "allergies.h"
#include <stdexcept>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(has_no_allergies)
{
    const allergies::allergy_test test(0);
    
    BOOST_REQUIRE_EQUAL(False, test.is_allergic_to("Peanuts"));
    BOOST_REQUIRE_EQUAL(False, test.is_allergic_to("Cats"));
    BOOST_REQUIRE_EQUAL(False, test.is_allergic_to("Strawberries"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(allergic_to_eggs)
{
   const allergies::allergy_test test(1);
   
   BOOST_REQUIRE_EQUAL(True, test.is_allergic_to("Strawberries"));
}
#endif
