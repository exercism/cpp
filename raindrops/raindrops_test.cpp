#include "raindrops.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(one_yields_itself)
{
    BOOST_REQUIRE_EQUAL("1", raindrops::convert(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(three_yields_pling)
{
    BOOST_REQUIRE_EQUAL("Pling", raindrops::convert(3));
}

BOOST_AUTO_TEST_CASE(five_yields_plang)
{
    BOOST_REQUIRE_EQUAL("Plang", raindrops::convert(5));
}

BOOST_AUTO_TEST_CASE(seven_yields_plong)
{
    BOOST_REQUIRE_EQUAL("Plong", raindrops::convert(7));
}

BOOST_AUTO_TEST_CASE(six_yields_pling)
{
    BOOST_REQUIRE_EQUAL("Pling", raindrops::convert(6));
}

BOOST_AUTO_TEST_CASE(nine_yields_pling)
{
    BOOST_REQUIRE_EQUAL("Pling", raindrops::convert(9));
}

BOOST_AUTO_TEST_CASE(ten_yields_plang)
{
    BOOST_REQUIRE_EQUAL("Plang", raindrops::convert(10));
}

BOOST_AUTO_TEST_CASE(fourteen_yields_plong)
{
    BOOST_REQUIRE_EQUAL("Plong", raindrops::convert(14));
}

BOOST_AUTO_TEST_CASE(fifteen_yields_plingplang)
{
    BOOST_REQUIRE_EQUAL("PlingPlang", raindrops::convert(15));
}

BOOST_AUTO_TEST_CASE(twenty_one_yields_plingplong)
{
    BOOST_REQUIRE_EQUAL("PlingPlong", raindrops::convert(21));
}

BOOST_AUTO_TEST_CASE(twenty_five_yields_plang)
{
    BOOST_REQUIRE_EQUAL("Plang", raindrops::convert(25));
}

BOOST_AUTO_TEST_CASE(thirty_five_yields_plangplong)
{
    BOOST_REQUIRE_EQUAL("PlangPlong", raindrops::convert(35));
}

BOOST_AUTO_TEST_CASE(forty_nine_yields_plong)
{
    BOOST_REQUIRE_EQUAL("Plong", raindrops::convert(49));
}

BOOST_AUTO_TEST_CASE(fifty_two_yields_itself)
{
    BOOST_REQUIRE_EQUAL("52", raindrops::convert(52));
}

BOOST_AUTO_TEST_CASE(one_hundred_five_yields_plingplangplong)
{
    BOOST_REQUIRE_EQUAL("PlingPlangPlong", raindrops::convert(105));
}

BOOST_AUTO_TEST_CASE(big_prime_yields_itself)
{
    BOOST_REQUIRE_EQUAL("12121", raindrops::convert(12121));
}
#endif
