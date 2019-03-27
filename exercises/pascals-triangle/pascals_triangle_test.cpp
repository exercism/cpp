#include "pascals_triangle.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(zero_rows)
{
    const std::vector<std::vector<int>> expected;

    const std::vector<std::vector<int>> actual{pascals_triangle::generate_rows(0)};

    BOOST_TEST(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(single_row)
{
    const std::vector<std::vector<int>> expected{
      {1}
    };

    const std::vector<std::vector<int>> actual{pascals_triangle::generate_rows(1)};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(two_rows)
{
    const std::vector<std::vector<int>> expected{
      {1}, 
      {1, 1}
    };

    const std::vector<std::vector<int>> actual{pascals_triangle::generate_rows(2)};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(three_rows)
{
    const std::vector<std::vector<int>> expected{
      {1}, 
      {1, 1}, 
      {1, 2, 1}
    };

    const std::vector<std::vector<int>> actual{pascals_triangle::generate_rows(3)};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(four_rows)
{
    const std::vector<std::vector<int>> expected{
      {1},
      {1, 1},
      {1, 2, 1},
      {1, 3, 3, 1}
    };

    const std::vector<std::vector<int>> actual{pascals_triangle::generate_rows(4)};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(five_rows)
{
    const std::vector<std::vector<int>> expected{
      {1},
      {1, 1},
      {1, 2, 1},
      {1, 3, 3, 1}, 
      {1, 4, 6, 4, 1}
    };

    const std::vector<std::vector<int>> actual{pascals_triangle::generate_rows(5)};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(six_rows)
{
    const std::vector<std::vector<int>> expected{
      {1},
      {1, 1},
      {1, 2, 1},
      {1, 3, 3, 1}, 
      {1, 4, 6, 4, 1},
      {1, 5, 10, 10, 5, 1}
    };

    const std::vector<std::vector<int>> actual{pascals_triangle::generate_rows(6)};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(ten_rows)
{
    const std::vector<std::vector<int>> expected{
      {1},
      {1, 1},
      {1, 2, 1},
      {1, 3, 3, 1},
      {1, 4, 6, 4, 1},
      {1, 5, 10, 10, 5, 1},
      {1, 6, 15, 20, 15, 6, 1}, 
      {1, 7, 21, 35, 35, 21, 7, 1}, 
      {1, 8, 28, 56, 70, 56, 28, 8, 1}, 
      {1, 9, 36, 84, 126, 126, 84, 36, 9, 1}
    };

    const std::vector<std::vector<int>> actual{pascals_triangle::generate_rows(10)};

    BOOST_TEST(expected == actual);
}

#endif
