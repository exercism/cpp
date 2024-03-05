#include "linked_list.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

/*
`delete`cannot be used as a name in C++ as it is reserved.
This track implements `erase` instead.
The tests have been renamed accordingly.
*/

TEST_CASE("pop gets element from the list", "[7f7e3987-b954-41b8-8084-99beca08752c]") {
    linked_list::List<int> llist{};
    llist.push(7);
    REQUIRE(7 == llist.pop());
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("push/pop respectively add/remove at the end of the list", "[c3f67e5d-cfa2-4c3e-a18f-7ce999c3c885]") {
    linked_list::List<int> llist{};
    llist.push(11);
    llist.push(13);
    REQUIRE(13 == llist.pop());
    REQUIRE(11 == llist.pop());
}

TEST_CASE("shift gets an element from the list", "[00ea24ce-4f5c-4432-abb4-cc6e85462657]") {
    linked_list::List<int> llist{};
    llist.push(17);
    REQUIRE(17 == llist.shift());
}

TEST_CASE("shift gets first element from the list", "[37962ee0-3324-4a29-b588-5a4c861e6564]") {
    linked_list::List<int> llist{};
    llist.push(23);
    llist.push(5);
    REQUIRE(23 == llist.shift());
    REQUIRE(5 == llist.shift());
}

TEST_CASE("unshift adds element at start of the list", "[30a3586b-e9dc-43fb-9a73-2770cec2c718]") {
    linked_list::List<int> llist{};
    llist.unshift(23);
    llist.unshift(5);
    REQUIRE(5 == llist.shift());
    REQUIRE(23 == llist.shift());
}

TEST_CASE("pop, push, shift, and unshift can be used in any order", "[042f71e4-a8a7-4cf0-8953-7e4f3a21c42d]") {
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

TEST_CASE("count an empty list", "[88f65c0c-4532-4093-8295-2384fb2f37df]") {
    linked_list::List<int> llist{};
    REQUIRE(0 == llist.count());
}

TEST_CASE("count a list with items", "[fc055689-5cbe-4cd9-b994-02e2abbb40a5]") {
    linked_list::List<int> llist{};
    llist.push(37);
    llist.push(1);
    REQUIRE(2 == llist.count());
}

TEST_CASE("count is correct after mutation", "[8272cef5-130d-40ea-b7f6-5ffd0790d650]") {
    linked_list::List<int> llist{};
    llist.push(31);
    REQUIRE(1 == llist.count());
    llist.unshift(43);
    REQUIRE(2 == llist.count());
    llist.shift();
    REQUIRE(1 == llist.count());
    llist.pop();
    REQUIRE(0 == llist.count());
}

TEST_CASE("popping to empty doesn't break the list", "[229b8f7a-bd8a-4798-b64f-0dc0bb356d95]") {
    linked_list::List<int> llist{};
    llist.push(41);
    llist.push(59);
    llist.pop();
    llist.pop();
    llist.push(47);
    REQUIRE(1 == llist.count());
    REQUIRE(47 == llist.pop());
}

TEST_CASE("shifting to empty doesn't break the list", "[4e1948b4-514e-424b-a3cf-a1ebbfa2d1ad]") {
    linked_list::List<int> llist{};
    llist.push(41);
    llist.push(59);
    llist.shift();
    llist.shift();
    llist.push(47);
    REQUIRE(1 == llist.count());
    REQUIRE(47 == llist.shift());
}

TEST_CASE("erases the only element", "[e8f7c600-d597-4f79-949d-8ad8bae895a6]") {
    linked_list::List<int> llist{};
    llist.push(61);
    llist.erase(61);
    REQUIRE(0 == llist.count());
}

TEST_CASE("erases the element with the specified value from the list", "[fd65e422-51f3-45c0-9fd0-c33da638f89b]") {
    linked_list::List<int> llist{};
    llist.push(71);
    llist.push(83);
    llist.push(79);
    llist.erase(83);
    REQUIRE(2 == llist.count());
    REQUIRE(79 == llist.pop());
    REQUIRE(71 == llist.shift());
}

TEST_CASE("erases the element with the specified value from the list, re-assigns tail", "[59db191a-b17f-4ab7-9c5c-60711ec1d013]") {
	linked_list::List<int> llist{};
    llist.push(71);
    llist.push(83);
    llist.push(79);
    llist.erase(83);
    REQUIRE(2 == llist.count());
    REQUIRE(79 == llist.pop());
    REQUIRE(71 == llist.pop());
}

TEST_CASE("erases the element with the specified value from the list, re-assigns head", "[58242222-5d39-415b-951d-8128247f8993]") {
	linked_list::List<int> llist{};
    llist.push(71);
    llist.push(83);
    llist.push(79);
    llist.erase(83);
    REQUIRE(2 == llist.count());
    REQUIRE(71 == llist.shift());
    REQUIRE(79 == llist.shift());
}

TEST_CASE("erases the first of two elements", "[ee3729ee-3405-4bd2-9bad-de0d4aa5d647]") {
	linked_list::List<int> llist{};
    llist.push(97);
    llist.push(101);
    llist.erase(97);
    REQUIRE(1 == llist.count());
    REQUIRE(101 == llist.pop());
}

TEST_CASE("erases the second of two elements", "[47e3b3b4-b82c-4c23-8c1a-ceb9b17cb9fb]") {
	linked_list::List<int> llist{};
    llist.push(97);
    llist.push(101);
    llist.erase(101);
    REQUIRE(1 == llist.count());
    REQUIRE(97 == llist.pop());
}

TEST_CASE("erase does not modify the list if the element is not found", "[7b420958-f285-4922-b8f9-10d9dcab5179]") {
	linked_list::List<int> llist{};
    llist.push(89);
    llist.erase(103);
    REQUIRE(1 == llist.count());
}

TEST_CASE("erases only the first occurrence", "[7e04828f-6082-44e3-a059-201c63252a76]") {
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

#endif
