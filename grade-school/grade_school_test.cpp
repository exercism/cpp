#include "grade_school.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

namespace boost
{

// teach Boost.Test how to print std::vector
template <typename T>
inline wrap_stringstream&
operator<<(wrap_stringstream& wrapped, std::vector<T> const& item)
{
    wrapped << '[';
    bool first = true;
    for (auto const& element : item) {
        wrapped << (!first ? "," : "") << element;
        first = false;
    }
    return wrapped << ']';
}

// teach Boost.Test how to print std::pair
template <typename K, typename V>
inline wrap_stringstream&
operator<<(wrap_stringstream& wrapped, std::pair<const K, V> const& item)
{
    return wrapped << '<' << item.first << ',' << item.second << '>';
}

}

#define REQUIRE_EQUAL_CONTAINERS(left_, right_) \
    BOOST_REQUIRE_EQUAL_COLLECTIONS(left_.begin(), left_.end(), right_.begin(), right_.end())

using namespace std;

struct school_fixture
{
    grade_school::school school_;
};

BOOST_FIXTURE_TEST_SUITE(school_suite, school_fixture);

BOOST_AUTO_TEST_CASE(a_new_school_has_an_empty_roster)
{
    BOOST_REQUIRE(school_.roster().empty());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(adding_a_student_adds_them_to_the_roster_for_the_given_grade)
{
    school_.add("Aimee", 2);

    const auto actual = school_.roster();

    const map<int, vector<string>> expected{{2, {"Aimee"}}};
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(adding_more_students_to_the_same_grade_adds_them_to_the_roster)
{
    school_.add("Blair", 2);
    school_.add("James", 2);
    school_.add("Paul", 2);

    const auto actual = school_.roster();

    const map<int, vector<string>> expected{{2, {"Blair", "James", "Paul"}}};
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(adding_students_to_different_grades_adds_them_to_the_roster)
{
    school_.add("Chelsea", 3);
    school_.add("Logan", 7);

    const auto actual = school_.roster();

    const map<int, vector<string>> expected{{3, {"Chelsea"}}, {7, {"Logan"}}};
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(grade_returns_the_students_in_that_grade_in_alphabetical_order)
{
    school_.add("Franklin", 5);
    school_.add("Bradley", 5);
    school_.add("Jeff", 1);

    const auto actual = school_.grade(5);

    const vector<string> expected{"Bradley", "Franklin"};
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}

BOOST_AUTO_TEST_CASE(grade_returns_an_empty_array_if_there_are_no_students_in_that_grade)
{
    const auto actual = school_.grade(1);

    BOOST_REQUIRE(actual.empty());
}

BOOST_AUTO_TEST_CASE(the_student_names_in_each_grade_in_the_roster_are_sorted)
{
    school_.add("Jennifer", 4);
    school_.add("Kareem", 6);
    school_.add("Christopher", 4);
    school_.add("Kyle", 3);

    const auto actual = school_.roster();

    const map<int, vector<string>> expected{
            {3, {"Kyle"}},
            {4, {"Christopher", "Jennifer"}},
            {6, {"Kareem"}}
        };
    REQUIRE_EQUAL_CONTAINERS(expected, actual);
}
#endif

BOOST_AUTO_TEST_SUITE_END();
