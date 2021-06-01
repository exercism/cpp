#include "etl.h"
#include <map>
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("transforms_one_value")
{
    const std::map<int, std::vector<char>> old{{1, {'A'}}};

    const auto actual = etl::transform(old);

    const std::map<char, int> expected{{'a', 1}};
    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("transforms_more_values")
{
    const std::map<int, std::vector<char>> old{{1, {'A', 'E', 'I', 'O', 'U'}}};

    const auto actual = etl::transform(old);

    const std::map<char, int> expected{{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
    REQUIRE(expected == actual);
}

TEST_CASE("transforms_more_keys")
{
    const std::map<int, std::vector<char>> old{{1, {'A', 'E'}}, {2, {'D', 'G'}}};

    const auto actual = etl::transform(old);

    const std::map<char, int> expected{{'a', 1}, {'e', 1}, {'d', 2}, {'g', 2}};
    REQUIRE(expected == actual);
}

TEST_CASE("transforms_a_full_dataset")
{
    const std::map<int, std::vector<char>> old{
        {1, {'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'}},
        {2, {'D', 'G'}},
        {3, {'B', 'C', 'M', 'P'}},
        {4, {'F', 'H', 'V', 'W', 'Y'}},
        {5, {'K'}},
        {8, {'J', 'X'}},
        {10, {'Q', 'Z'}}
    };

    const auto actual = etl::transform(old);

    const std::map<char, int> expected{
        {'a', 1}, {'b', 3},  {'c', 3}, {'d', 2}, {'e', 1},
        {'f', 4}, {'g', 2},  {'h', 4}, {'i', 1}, {'j', 8},
        {'k', 5}, {'l', 1},  {'m', 3}, {'n', 1}, {'o', 1},
        {'p', 3}, {'q', 10}, {'r', 1}, {'s', 1}, {'t', 1},
        {'u', 1}, {'v', 4},  {'w', 4}, {'x', 8}, {'y', 4},
        {'z', 10}
    };
    REQUIRE(expected == actual);
}
#endif
