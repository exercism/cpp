#include "grade_school.h"
#include <map>
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("Roster is empty when no student is added", "[a3f0fb58-f240-4723-8ddc-e644666b85cc]") {
    const grade_school::school school_;
    REQUIRE(school_.roster().empty());
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Add a student", "[9337267f-7793-4b90-9b4a-8e3978408824]") {
    grade_school::school school_;
    school_.add("Aimee", 2);
    REQUIRE(school_.roster() == map<int, vector<string>>{{2, {"Aimee"}}});
}

TEST_CASE("Student is added to the roster", "[6d0a30e4-1b4e-472e-8e20-c41702125667]") {
    grade_school::school school_;
    school_.add("Aimee", 2);
    REQUIRE(school_.grade(2) == vector<string>{"Aimee"});
}

TEST_CASE("Adding multiple students in the same grade in the roster", "[73c3ca75-0c16-40d7-82f5-ed8fe17a8e4a]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);
    REQUIRE(school_.grade(2) == vector<string>{"Blair", "James", "Paul"});
}

TEST_CASE("Multiple students in the same grade are added to the roster", "[233be705-dd58-4968-889d-fb3c7954c9cc]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);
    REQUIRE(school_.roster() == map<int, vector<string>>{{2, {"Blair", "James", "Paul"}}});
}

TEST_CASE("Cannot add student to same grade in the roster more than once", "[87c871c1-6bde-4413-9c44-73d59a259d83]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);
    REQUIRE(school_.grade(2) == vector<string>{"Blair", "James", "Paul"});
}

TEST_CASE("Student not added to same grade in the roster more than once", "[d7982c4f-1602-49f6-a651-620f2614243a]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);
    REQUIRE(school_.roster() == map<int, vector<string>>{{2, {"Blair", "James", "Paul"}}});
}

TEST_CASE("Adding students in multiple grades", "[e70d5d8f-43a9-41fd-94a4-1ea0fa338056]") {
    grade_school::school school_;
    school_.add("Chelsea", 3);
    school_.add("Logan", 7);
    REQUIRE(school_.roster() == map<int, vector<string>>{{3, {"Chelsea"}}, {7, {"Logan"}}});
}

TEST_CASE("Students in multiple grades are added to the roster", "[75a51579-d1d7-407c-a2f8-2166e984e8ab]") {
    grade_school::school school_;
    school_.add("Chelsea", 3);
    school_.add("Logan", 7);
    REQUIRE(school_.roster() == map<int, vector<string>>{{3, {"Chelsea"}}, {7, {"Logan"}}});
}

TEST_CASE("Cannot add same student to multiple grades in the roster", "[7df542f1-57ce-433c-b249-ff77028ec479]") {
    grade_school::school school_;
    school_.add("Aimee", 2);
    school_.add("Aimee", 3);
    REQUIRE(school_.roster() == map<int, vector<string>>{{2, {"Aimee"}}});
}

TEST_CASE("Student not added to multiple grades in the roster", "[c7ec1c5e-9ab7-4d3b-be5c-29f2f7a237c5]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 3);
    school_.add("Paul", 3);
    REQUIRE(school_.roster() == map<int, vector<string>>{{2, {"Blair", "James"}}, {3, {"Paul"}}});
}

TEST_CASE("Students are sorted by grades in the roster", "[d9af4f19-1ba1-48e7-94d0-dabda4e5aba6]") {
    grade_school::school school_;
    school_.add("Anna", 1);
    school_.add("Jim", 3);
    school_.add("Peter", 2);
    REQUIRE(school_.roster() == map<int, vector<string>>{
        {1, {"Anna"}},
        {2, {"Peter"}},
        {3, {"Jim"}}
    });
}

TEST_CASE("Students are sorted by name in the roster", "[d9fb5bea-f5aa-4524-9d61-c158d8906807]") {
    grade_school::school school_;
    school_.add("Zoe", 2);
    school_.add("Peter", 2);
    school_.add("Alex", 2);
    REQUIRE(school_.roster() == map<int, vector<string>>{{2, {"Alex", "Peter", "Zoe"}}});
}

TEST_CASE("Students are sorted by grades and then by name in the roster", "[180a8ff9-5b94-43fc-9db1-d46b4a8c93b6]") {
    grade_school::school school_;
    school_.add("Jim", 3);
    school_.add("Peter", 2);
    school_.add("Anna", 1);
    school_.add("Barb", 1);
    school_.add("Zoe", 2);
    school_.add("Alex", 2);
    school_.add("Charlie", 1);
    REQUIRE(school_.roster() == map<int, vector<string>>{
        {1, {"Anna", "Barb", "Charlie"}},
        {2, {"Alex", "Peter", "Zoe"}},
        {3, {"Jim"}}
    });
}

TEST_CASE("Grade is empty if no students in the roster", "[5e67aa3c-a3c6-4407-a183-d8fe59cd1630]") {
    const grade_school::school school_;
    REQUIRE(school_.grade(1).empty());
}

TEST_CASE("Grade is empty if no students in that grade", "[1e0cf06b-26e0-4526-af2d-a2e2df6a51d6]") {
    grade_school::school school_;
    school_.add("Peter", 2);
    school_.add("Zoe", 2);
    school_.add("Alex", 2);
    school_.add("Jim", 3);
    REQUIRE(school_.grade(1).empty());
}

TEST_CASE("Student not added to same grade more than once", "[2bfc697c-adf2-4b65-8d0f-c46e085f796e]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);
    REQUIRE(school_.grade(2) == vector<string>{"Blair", "James", "Paul"});
}

TEST_CASE("Student not added to multiple grades", "[66c8e141-68ab-4a04-a15a-c28bc07fe6b9]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 3);
    school_.add("Paul", 3);
    REQUIRE(school_.grade(2) == vector<string>{"Blair", "James"});
}

TEST_CASE("Student not added to other grade for multiple grades", "[c9c1fc2f-42e0-4d2c-b361-99271f03eda7]") {
    grade_school::school school_;
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("James", 3);
    school_.add("Paul", 3);
    REQUIRE(school_.grade(3) == vector<string>{"Paul"});
}

TEST_CASE("Students are sorted by name in a grade", "[1bfbcef1-e4a3-49e8-8d22-f6f9f386187e]") {
    grade_school::school school_;
    school_.add("Franklin", 5);
    school_.add("Bradley", 5);
    school_.add("Jeff", 1);
    REQUIRE(school_.grade(5) == vector<string>{"Bradley", "Franklin"});
}

#endif
