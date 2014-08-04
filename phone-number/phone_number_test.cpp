#include "phone_number.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(cleans_parens_dashes_and_spaces_from_the_number)
{
    const phone_number phone("(123) 456-7890");

    BOOST_REQUIRE_EQUAL("1234567890", phone.number());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(cleans_numbers_with_dots)
{
    const phone_number phone("123.456.7890");

    BOOST_REQUIRE_EQUAL("1234567890", phone.number());
}

BOOST_AUTO_TEST_CASE(valid_when_11_digits_and_first_digit_is_1)
{
    const phone_number phone("11234567890");

    BOOST_REQUIRE_EQUAL("1234567890", phone.number());
}

BOOST_AUTO_TEST_CASE(invalid_when_11_digits)
{
    const phone_number phone("21234567890");

    BOOST_REQUIRE_EQUAL("0000000000", phone.number());
}

BOOST_AUTO_TEST_CASE(invalid_when_9_digits)
{
    const phone_number phone("123456789");

    BOOST_REQUIRE_EQUAL("0000000000", phone.number());
}

BOOST_AUTO_TEST_CASE(has_an_area_code)
{
    const phone_number phone("1234567890");

    BOOST_REQUIRE_EQUAL("123", phone.area_code());
}

BOOST_AUTO_TEST_CASE(formats_a_number)
{
    const phone_number phone("1234567890");

    BOOST_REQUIRE_EQUAL("(123) 456-7890", std::string(phone));
}
#endif
