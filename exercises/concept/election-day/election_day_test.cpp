#include "election_day.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace election;

TEST_CASE("Votes are returned correctly for 0 votes", "[task_1]") {
    ElectionResult result{};
    int expected{0};
    REQUIRE(vote_count(result) == expected);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Votes are returned correctly for 211 votes", "[task_1]") {
    ElectionResult result{"Nadir", 211};
    int expected{211};
    REQUIRE(vote_count(result) == expected);
}

TEST_CASE("Votes are incremented correctly for new votes", "[task_2]") {
    ElectionResult result{};
    int expected{23};
    increment_vote_count(result, 23);
    REQUIRE(result.votes == expected);
}

TEST_CASE("Votes are incremented correctly for existing votes", "[task_2]") {
    ElectionResult result{"Saoirse", 94};
    int expected{1994};
    increment_vote_count(result, 1900);
    REQUIRE(result.votes == expected);
}

TEST_CASE("Votes can be decremented", "[task_2]") {
    ElectionResult result{"Lance", 7};
    int expected{0};
    increment_vote_count(result, -7);
    REQUIRE(result.votes == expected);
}

TEST_CASE("Presidency, one candidate", "[task_3]") {
    ElectionResult option1{"Coriolanus Snow", 13};
    std::vector<ElectionResult> final_count{option1};

    ElectionResult& result = determine_result(final_count);
    std::string expected{"President Coriolanus Snow"};

    REQUIRE(result.name == expected);
}

TEST_CASE("Presidency, two candidates", "[task_3]") {
    ElectionResult option1{"Megatron", 4};
    ElectionResult option2{"Optimus Prime", 76};
    std::vector<ElectionResult> final_count{option1, option2};

    ElectionResult& result = determine_result(final_count);
    std::string expected{"President Optimus Prime"};

    REQUIRE(result.name == expected);
}


TEST_CASE("Presidency, several candidates", "[task_3]") {
    ElectionResult option1{"David", 11};
    ElectionResult option2{"Shaw", 12};
    ElectionResult option3{"Ripley", 79};
    ElectionResult option4{"Call", 8};
    std::vector<ElectionResult> final_count{option1, option2, option3, option4};

    ElectionResult& result = determine_result(final_count);
    std::string expected{"President Ripley"};

    REQUIRE(result.name == expected);
}

TEST_CASE("Presidency, votes and other results do not change", "[task_3]") {
    ElectionResult option1{"Tammy Metzler", 0};
    ElectionResult option2{"Tracy Flick", 257};
    ElectionResult option3{"Paul Metzler", 256};
    std::vector<ElectionResult> final_count{option1, option2, option3};

    determine_result(final_count);

    REQUIRE(final_count.size() == 3);
    REQUIRE(final_count[0].name == "Tammy Metzler");
    REQUIRE(final_count[0].votes == 0);
    REQUIRE(final_count[1].name == "President Tracy Flick");
    REQUIRE(final_count[1].votes == 257);
    REQUIRE(final_count[2].name == "Paul Metzler");
    REQUIRE(final_count[2].votes == 256);
}

#endif
