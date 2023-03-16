#include "linked_list.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("pop_gets_element_from_the_list")
{
    linked_list::List<int> llist{};
    llist.push(7);
    REQUIRE(7 == llist.pop());
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("push/pop_respectively_add/remove_at_the_end_of_the_list")
{
    linked_list::List<int> llist{};
    llist.push(11);
    llist.push(13);
    REQUIRE(13 == llist.pop());
    REQUIRE(11 == llist.pop());
}

TEST_CASE("shift_gets_an_element_from_the_list")
{
    linked_list::List<int> llist{};
    llist.push(17);
    REQUIRE(17 == llist.shift());
}

TEST_CASE("shift_gets_first_element_from_the_list")
{
    linked_list::List<int> llist{};
    llist.push(23);
    llist.push(5);
    REQUIRE(23 == llist.shift());
    REQUIRE(5 == llist.shift());
}

TEST_CASE("unshift_adds_element_at_start_of_the_list")
{
    linked_list::List<int> llist{};
    llist.unshift(23);
    llist.unshift(5);
    REQUIRE(5 == llist.shift());
    REQUIRE(23 == llist.shift());
}

TEST_CASE("pop,_push,_shift,_and_unshift_can_be_used_in_any_order")
{
    linked_list::List<int> llist{};
    llist.push(1);
    llist.push(2);
    REQUIRE(2 == llist.pop());
    llist.push(3);
    REQUIRE(1 == llist.shift());
    llist.unshift(4);
    llist.push(5);
    REQUIRE(4 == llist.shift());
    REQUIRE(5 == llist.pop());
    REQUIRE(3 == llist.shift());
}

TEST_CASE("size_of_an_empty_list")
{
    linked_list::List<int> llist{};
    REQUIRE(0 == llist.size());
}

TEST_CASE("size_of__a_list_with_items")
{
    linked_list::List<int> llist{};
    llist.push(37);
    llist.push(1);
    REQUIRE(2 == llist.size());
}

TEST_CASE("size_is_correct_after_mutation")
{
    linked_list::List<int> llist{};
    llist.push(31);
    REQUIRE(1 == llist.size());
    llist.unshift(43);
    REQUIRE(2 == llist.size());
    llist.shift();
    REQUIRE(1 == llist.size());
    llist.pop();
    REQUIRE(0 == llist.size());
}

TEST_CASE("popping_to_empty_doesn't_break_the_list")
{
    linked_list::List<int> llist{};
    llist.push(41);
    llist.push(59);
    llist.pop();
    llist.pop();
    llist.push(47);
    REQUIRE(1 == llist.count());
    REQUIRE(47 == llist.pop());
}

TEST_CASE("shifting_to_empty_doesn't_break_the_list")
{
    linked_list::List<int> llist{};
    llist.push(41);
    llist.push(59);
    llist.shift();
    llist.shift();
    llist.push(47);
    REQUIRE(1 == llist.count());
    REQUIRE(47 == llist.shift());
}

TEST_CASE("popping_from_empty_throws_exception")
{
    linked_list::List<int> llist{};
    REQUIRE_THROWS(llist.pop());
}

TEST_CASE("shifting_from_empty_throws_exception")
{
    linked_list::List<int> llist{};
    REQUIRE_THROWS(llist.shift());
}

TEST_CASE("erases_the_only_element")
{
    linked_list::List<int> llist{};
    llist.push(61);
    llist.erase(61);
    REQUIRE(0 == llist.count());
}

TEST_CASE("erases_the_element_with_the_specified_value_from_the_list")
{
    linked_list::List<int> llist{};
    llist.push(71);
    llist.push(83);
    llist.push(79);
    llist.erase(83);
    REQUIRE(2 == llist.count());
    REQUIRE(79 == llist.pop());
    REQUIRE(71 == llist.shift());
}

TEST_CASE("erases_the_element_with_the_specified_value_from_the_list,_re-assigns_tail")
{
    linked_list::List<int> llist{};
    llist.push(71);
    llist.push(83);
    llist.push(79);
    llist.erase(83);
    REQUIRE(2 == llist.count());
    REQUIRE(79 == llist.pop());
    REQUIRE(71 == llist.pop());
}

TEST_CASE("erases_the_element_with_the_specified_value_from_the_list,_re-assigns_head")
{
    linked_list::List<int> llist{};
    llist.push(71);
    llist.push(83);
    llist.push(79);
    llist.erase(83);
    REQUIRE(2 == llist.count());
    REQUIRE(71 == llist.shift());
    REQUIRE(79 == llist.shift());
}

TEST_CASE("erases_the_first_of_two_elements")
{
    linked_list::List<int> llist{};
    llist.push(97);
    llist.push(101);
    llist.erase(97);
    REQUIRE(1 == llist.count());
    REQUIRE(101 == llist.pop());
}

TEST_CASE("erases_the_second_of_two_elements")
{
    linked_list::List<int> llist{};
    llist.push(97);
    llist.push(101);
    llist.erase(101);
    REQUIRE(1 == llist.count());
    REQUIRE(97 == llist.pop());
}

TEST_CASE("erase_does_not_modify_the_list_if_the_element_is_not_found")
{
    linked_list::List<int> llist{};
    llist.push(89);
    llist.erase(103);
    REQUIRE(1 == llist.count());
}

TEST_CASE("erases_only_the_first_occurrence")
{
    linked_list::List<int> llist{};
    llist.push(73);
    llist.push(9);
    llist.push(9);
    llist.push(107);
    llist.erase(9);
    REQUIRE(3 == llist.count());
    REQUIRE(107 == llist.pop());
    REQUIRE(9 == llist.pop());
    REQUIRE(73 == llist.pop());
}

#endif  // EXERCISM_RUN_ALL_TESTS