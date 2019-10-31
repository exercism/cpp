#include "change.h"
#include "test/catch.hpp"

TEST_CASE("no_coin_change")
{
    const vector<int> input_vector = {1, 5, 10, 25, 100};
    const vector<int> actual = change::get_change(0, input_vector);
    
    const vector<int> expected = {};

    REQUIRE(expected.size() == actual.size());

    bool no_change = true;

    if (expected.size() != 0)
        no_change = false;

    REQUIRE(no_change == true);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("single_coin_change")
{
    const vector<int> input_vector = {1, 5, 10, 25, 100};
    const vector<int> actual = change::get_change(25, input_vector);
    
    const vector<int> expected = {25};

    REQUIRE(expected.size() == actual.size());
    REQUIRE(expected[0] == actual[0]);
}

TEST_CASE("multiple_coin_change")
{
    const vector<int> input_vector = {1, 5, 10, 25, 100};
    const vector<int> actual = change::get_change(15, input_vector);
    
    const vector<int> expected = {5, 10};

    REQUIRE(expected.size() == actual.size());

    bool same_change = true;

    for (size_t i = 0; i < actual.size()) {
        if (expected[i] != actual[i])
            same_change = false;
    }

    REQUIRE(same_change == true);
}

TEST_CASE("change_with_Lilliputian_Coins")
{
    const vector<int> input_vector = {1, 4, 15, 20, 50};
    const vector<int> actual = change::get_change(23, input_vector);
    
    const vector<int> expected = {4, 4, 15};

    REQUIRE(expected.size() == actual.size());

    bool same_change = true;

    for (size_t i = 0; i < actual.size()) {
        if (expected[i] != actual[i])
            same_change = false;
    }

    REQUIRE(same_change == true);
}

TEST_CASE("change_with_lower_Elobian_Coins")
{
    const vector<int> input_vector = {1, 5, 10, 21, 25};
    const vector<int> actual = change::get_change(63, input_vector);
    
    const vector<int> expected = {21, 21, 21};

    REQUIRE(expected.size() == actual.size());

    bool same_change = true;

    for (size_t i = 0; i < actual.size()) {
        if (expected[i] != actual[i])
            same_change = false;
    }

    REQUIRE(same_change == true);
}

TEST_CASE("large_target_values")
{
    const vector<int> input_vector = {1, 2, 5, 10,, 20, 50, 100};
    const vector<int> actual = change::get_change(999, input_vector);
    
    const vector<int> expected = {2, 2, 5, 20, 20, 50, 100, 100, 100, 100, 100, 100
                                 100, 100, 100};

    REQUIRE(expected.size() == actual.size());

    bool same_change = true;

    for (size_t i = 0; i < actual.size()) {
        if (expected[i] != actual[i])
            same_change = false;
    }

    REQUIRE(same_change == true);
}

TEST_CASE("possible_change_without_unit_coins_available")
{
    const vector<int> input_vector = {2, 5, 10, 20, 50};
    const vector<int> actual = change::get_change(21, input_vector);
    
    const vector<int> expected = {2, 2, 2, 5, 10};

    REQUIRE(expected.size() == actual.size());

    bool same_change = true;

    for (size_t i = 0; i < actual.size()) {
        if (expected[i] != actual[i])
            same_change = false;
    }

    REQUIRE(same_change == true);
}

TEST_CASE("another_possible_change_without_unit_coins_available")
{
    const vector<int> input_vector = {4, 5};
    const vector<int> actual = change::get_change(27, input_vector);
    
    const vector<int> expected = {4, 4, 4, 5, 5, 5};

    REQUIRE(expected.size() == actual.size());

    bool same_change = true;

    for (size_t i = 0; i < actual.size()) {
        if (expected[i] != actual[i])
            same_change = false;
    }

    REQUIRE(same_change == true);
}

#endif
