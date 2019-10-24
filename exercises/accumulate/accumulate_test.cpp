#include "accumulate.h"
#include "test/catch.hpp"
#include <vector>

using namespace std;

TEST_CASE("basic_square")
{   vector<int> input = {1,2,3,4,5};
    std::string operation = "square";
    vector<int> output;
    const string actual = accumulate::accumulate(input, operation, output);

    const string expected{{1,4,9,16,25}};

    REQUIRE(expected == actual);
}

TEST_CASE("basic_cube")
{   vector<int> input = {1,2,3,4,5};
    std::string operation = "cube";
    vector<int> output;
    const string actual = accumulate::accumulate(input, operation, output);

    const string expected{{1,8,27,64,125}};

    REQUIRE(expected == actual);
}

TEST_CASE("basic_square_root")
{   vector<int> input = {1,4,9,16,25};
    std::string operation = "square root";
    vector<int> output;
    const string actual = accumulate::accumulate(input, operation, output);

    const string expected{{1,2,3,4,5}};

    REQUIRE(expected == actual);
}

TEST_CASE("basic_factorial")
{   vector<int> input = {1,2,3,4,5};
    std::string operation = "factorial";
    vector<int> output;
    const string actual = accumulate::accumulate(input, operation, output);

    const string expected{{1,2,6,24,120}};

    REQUIRE(expected == actual);
}
/*
#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("lowercase_words")
{
    const string actual = acronym::acronym("Ruby on Rails");

    const string expected{"ROR"};

    REQUIRE(expected == actual);
}

TEST_CASE("punctuation")
{
    const string actual = acronym::acronym("First In, First Out");

    const string expected{"FIFO"};

    REQUIRE(expected == actual);
}

TEST_CASE("all_caps_words")
{
    const string actual = acronym::acronym("PHP: Hypertext Preprocessor");

    const string expected{"PHP"};

    REQUIRE(expected == actual);
}

TEST_CASE("non_acronym_all_caps_word")
{
    const string actual = acronym::acronym("GNU Image Manipulation Program");

    const string expected{"GIMP"};

    REQUIRE(expected == actual);
}

TEST_CASE("hyphenated")
{
    const string actual = acronym::acronym("Complementary metal-oxide semiconductor");

    const string expected{"CMOS"};

    REQUIRE(expected == actual);
}

#endif
*/