#include "prime_factors.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(_1_yields_empty)
{
    const std::vector<int> expected{};

    const std::vector<int> actual{prime_factors::of(1)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(_2_yields_2)
{
    const std::vector<int> expected{2};

    const std::vector<int> actual{prime_factors::of(2)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(_3_yields_3)
{
    const std::vector<int> expected{3};

    const std::vector<int> actual{prime_factors::of(3)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(_4_yields_2_2)
{
    const std::vector<int> expected{2, 2};

    const std::vector<int> actual{prime_factors::of(4)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(_6_yields_2_3)
{
    const std::vector<int> expected{2, 3};

    const std::vector<int> actual{prime_factors::of(6)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(_8_yields_2_2_2)
{
    const std::vector<int> expected{2, 2, 2};

    const std::vector<int> actual{prime_factors::of(8)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(_9_yields_3_3)
{
    const std::vector<int> expected{3, 3};

    const std::vector<int> actual{prime_factors::of(9)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(_27_yields_3_3_3)
{
    const std::vector<int> expected{3, 3, 3};

    const std::vector<int> actual{prime_factors::of(27)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(_625_yields_5_5_5_5)
{
    const std::vector<int> expected{5, 5, 5, 5};

    const std::vector<int> actual{prime_factors::of(625)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(_901255_yields_5_17_23_461)
{
    const std::vector<int> expected{5, 17, 23, 461};

    const std::vector<int> actual{prime_factors::of(901255)};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}
#endif
