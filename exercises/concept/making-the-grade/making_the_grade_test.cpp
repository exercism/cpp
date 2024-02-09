#include "making_the_grade.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("Check correct mark conversion (empty)", "[task_1]") {
    vector<double> input{};
    vector<int> expected{};
    vector<int> actual = round_down_scores(input);

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Check correct mark conversion (all < 0.5)", "[task_1]") {
    vector<double> input{5.2, 77.1, 91.0};
    vector<int> expected{5, 77, 91};
    vector<int> actual = round_down_scores(input);

    REQUIRE(expected == actual);
}

TEST_CASE("Check correct mark conversion (all mixed)", "[task_1]") {
    vector<double> input{5.2, 77.1, 91.0, 42.9, 11.6544};
    vector<int> expected{5, 77, 91, 42, 11};
    vector<int> actual = round_down_scores(input);

    REQUIRE(expected == actual);
}

TEST_CASE("Count failed students (none failed)", "[task_2]") {
    vector<int> input{89, 85, 42, 57, 90, 100, 95, 48, 70, 96};
    int expected{0};
    int actual = count_failed_students(input);

    REQUIRE(expected == actual);
}

TEST_CASE("Count failed students (some failed)", "[task_2]") {
    vector<int> input{40, 40, 35, 70, 30, 41, 90};
    int expected{4};
    int actual = count_failed_students(input);

    REQUIRE(expected == actual);
}

TEST_CASE("Test threshold (empty)", "[task_3]") {
    vector<int> input{};
    int threshold{98};
    vector<int> expected{};
    vector<int> actual = above_threshold(input, threshold);

    REQUIRE(expected == actual);
}

TEST_CASE("Test threshold (some above threshold)", "[task_3]") {
    vector<int> input{88, 29, 91, 64, 78, 43, 41, 77, 36, 50};
    int threshold{80};
    vector<int> expected{88, 91};
    vector<int> actual = above_threshold(input, threshold);

    REQUIRE(expected == actual);
}

TEST_CASE("Test threshold (none above threshold)", "[task_3]") {
    vector<int> input{88, 29, 91, 64, 78, 43, 41, 77, 36, 50};
    int threshold{99};
    vector<int> expected{};
    vector<int> actual = above_threshold(input, threshold);

    REQUIRE(expected == actual);
}

TEST_CASE("Test threshold (some on threshold)", "[task_3]") {
    vector<int> input{88, 29, 91, 64, 78, 43, 41, 77, 80, 80};
    int threshold{80};
    vector<int> expected{88, 91, 80, 80};
    vector<int> actual = above_threshold(input, threshold);

    REQUIRE(expected == actual);
}

TEST_CASE("Test letter grades: 100", "[task_4]") {
    int input{100};
    array<int, 4> expected{41, 56, 71, 86};
    array<int, 4> actual = letter_grades(input);

    REQUIRE(expected == actual);
}
TEST_CASE("Test letter grades: 97", "[task_4]") {
    int input{97};
    array<int, 4> expected{41, 55, 69, 83};
    array<int, 4> actual = letter_grades(input);

    REQUIRE(expected == actual);
}
TEST_CASE("Test letter grades: 81", "[task_4]") {
    int input{81};
    array<int, 4> expected{41, 51, 61, 71};
    array<int, 4> actual = letter_grades(input);

    REQUIRE(expected == actual);
}

TEST_CASE("Rank one student", "[task_5]") {
    vector<int> grades{82};
    vector<string> names{"Betty"};
    vector<string> expected{"1. Betty: 82"};
    vector<string> actual = student_ranking(grades, names);

    REQUIRE(expected == actual);
}

TEST_CASE("Rank several student", "[task_5]") {
    vector<int> grades{100, 98, 92, 86, 70, 68, 67, 60};
    vector<string> names{"Rui", "Betty", "Joci", "Yoshi", "Kora", "Bern", "Jan", "Rose"};
    vector<string> expected{"1. Rui: 100", "2. Betty: 98", "3. Joci: 92", "4. Yoshi: 86",
                 "5. Kora: 70", "6. Bern: 68", "7. Jan: 67", "8. Rose: 60"};
    vector<string> actual = student_ranking(grades, names);

    REQUIRE(expected == actual);
}

TEST_CASE("No perfect score", "[task_6]") {
    vector<int> grades{11, 34, 92, 23, 70, 76, 67, 60};
    vector<string> names{"Rui", "Betty", "Joci", "Yoshi", "Kora", "Bern", "Jan", "Rose"};
    string expected{""};
    string actual = perfect_score(grades, names);

    REQUIRE(expected == actual);
}

TEST_CASE("One perfect score", "[task_6]") {
    vector<int> grades{11, 34, 92, 23, 70, 76, 67, 100};
    vector<string> names{"Rui", "Betty", "Joci", "Yoshi", "Kora", "Bern", "Jan", "Rose"};
    string expected{"Rose"};
    string actual = perfect_score(grades, names);

    REQUIRE(expected == actual);
}

TEST_CASE("Several perfect scores", "[task_6]") {
    vector<int> grades{11, 100, 92, 23, 70, 100, 67, 100};
    vector<string> names{"Rui", "Betty", "Joci", "Yoshi", "Kora", "Bern", "Jan", "Rose"};
    string expected{"Betty"};
    string actual = perfect_score(grades, names);

    REQUIRE(expected == actual);
}

#endif
