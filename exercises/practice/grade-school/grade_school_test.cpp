#include "grade_school.h"

#include <map>
#include <string>
#include <vector>
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("roster_is_empty_when_no_student_is_added",
          "[a3f0fb58-f240-4723-8ddc-e644666b85cc]") {
    const grade_school::school school_{};

    REQUIRE(school_.roster().empty());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("student_is_added_to_the_roster",
          "[6d0a30e4-1b4e-472e-8e20-c41702125667]") {
    grade_school::school school_;
    school_.add("Aimee", 2);

    const map<int, vector<string>> expected{{2, {"Aimee"}}};
    REQUIRE(expected == school_.roster());
}

TEST_CASE(
    "multiple_students_in_the_same_grade_are_added_to_the_roster",
    "[233be705-dd58-4968-889d-fb3c7954c9cc]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);

    const map<int, vector<string>> expected{{2, {"Blair", "James", "Paul"}}};
    REQUIRE(expected == school_.roster());
}

TEST_CASE(
    "student_not_added_to_same_grade_in_the_roster_more_than_once",
    "[d7982c4f-1602-49f6-a651-620f2614243a]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);

    const map<int, vector<string>> expected{{2, {"Blair", "James", "Paul"}}};
    REQUIRE(expected == school_.roster());
}

TEST_CASE("students_in_multiple_grades_are_added_to_the_roster",
          "[75a51579-d1d7-407c-a2f8-2166e984e8ab]") {
    grade_school::school school_;
    school_.add("Chelsea", 3);
    school_.add("Logan", 7);

    const map<int, vector<string>> expected{{3, {"Chelsea"}}, {7, {"Logan"}}};
    REQUIRE(expected == school_.roster());
}

TEST_CASE("student_not_added_to_multiple_grades_in_the_roster",
          "[c7ec1c5e-9ab7-4d3b-be5c-29f2f7a237c5]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 3);
    school_.add("Paul", 3);

    const map<int, vector<string>> expected{{2, {"Blair", "James"}},
                                            {3, {"Paul"}}};
    REQUIRE(expected == school_.roster());
}

TEST_CASE("students_are_sorted_by_grades_in_the_roster",
          "[d9af4f19-1ba1-48e7-94d0-dabda4e5aba6]") {
    grade_school::school school_;
    school_.add("Jim", 3);
    school_.add("Peter", 2);
    school_.add("Anna", 1);

    const map<int, vector<string>> expected{{1, {"Anna"}},
                                            {2, {"Peter"}},
                                            {3, {"Jim"}}};
    REQUIRE(expected == school_.roster());
}

TEST_CASE("students_are_sorted_by_name_in_the_roster",
          "[d9fb5bea-f5aa-4524-9d61-c158d8906807]") {
    grade_school::school school_;
    school_.add("Peter", 2);
    school_.add("Zoe", 2);
    school_.add("Alex", 2);

    const map<int, vector<string>> expected{{2, {"Alex", "Peter", "Zoe"}}};
    REQUIRE(expected == school_.roster());
}

TEST_CASE(
    "students_are_sorted_by_grades_and_then_by_name_in_the_roster",
    "[180a8ff9-5b94-43fc-9db1-d46b4a8c93b6]") {
    grade_school::school school_;
    school_.add("Peter", 2);
    school_.add("Anna", 1);
    school_.add("Barb", 1);
    school_.add("Zoe", 2);
    school_.add("Alex", 2);
    school_.add("Jim", 3);
    school_.add("Charlie", 1);

    const map<int, vector<string>> expected{{1, {"Anna", "Barb", "Charlie"}},
                                            {2, {"Alex", "Peter", "Zoe"}},
                                            {3, {"Jim"}}};
    REQUIRE(expected == school_.roster());
}

TEST_CASE("grade_is_empty_if_no_students_in_the_roster",
          "[5e67aa3c-a3c6-4407-a183-d8fe59cd1630]") {
    const grade_school::school school_{};

    REQUIRE(school_.grade(1).empty());
}

TEST_CASE("grade_is_empty_if_no_students_in_that_grade",
          "[1e0cf06b-26e0-4526-af2d-a2e2df6a51d6]") {
    grade_school::school school_;
    school_.add("Peter", 2);
    school_.add("Zoe", 2);
    school_.add("Alex", 2);
    school_.add("Jim", 3);

    const vector<string> expected{};
    REQUIRE(expected == school_.grade(1));
}

TEST_CASE("student_not_added_to_same_grade_more_than_once",
          "[2bfc697c-adf2-4b65-8d0f-c46e085f796e]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);

    const vector<string> expected{"Blair", "James", "Paul"};
    REQUIRE(expected == school_.grade(2));
}

TEST_CASE("student_not_added_to_multiple_grades",
          "[66c8e141-68ab-4a04-a15a-c28bc07fe6b9]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 3);
    school_.add("Paul", 3);

    const vector<string> expected{"Blair", "James"};
    REQUIRE(expected == school_.grade(2));
}

TEST_CASE("student_not_added_to_other_grade_for_multiple_grades",
          "[c9c1fc2f-42e0-4d2c-b361-99271f03eda7]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 3);
    school_.add("Paul", 3);

    const vector<string> expected{"Paul"};
    REQUIRE(expected == school_.grade(3));
}

TEST_CASE("students_are_sorted_by_name_in_a_grade",
          "[1bfbcef1-e4a3-49e8-8d22-f6f9f386187e]") {
    grade_school::school school_;
    school_.add("Franklin", 5);
    school_.add("Bradley", 5);
    school_.add("Jeff", 1);

    const vector<string> expected{"Bradley", "Franklin"};
    REQUIRE(expected == school_.grade(5));
}

#endif
