#include "book_store.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("Only_a_single_book", "[17146bd5-2e80-4557-ab4c-05632b6b0d01]") {
    REQUIRE(book_store::total({1}) == 800);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Two_of_the_same_book", "[cc2de9ac-ff2a-4efd-b7c7-bfe0f43271ce]") {
    REQUIRE(book_store::total({2, 2}) == 1600);
}

TEST_CASE("Empty_basket", "[5a86eac0-45d2-46aa-bbf0-266b94393a1a]") {
    REQUIRE(book_store::total({}) == 0);
}

TEST_CASE("Two_different_books", "[158bd19a-3db4-4468-ae85-e0638a688990]") {
    REQUIRE(book_store::total({1, 2}) == 1520);
}

TEST_CASE("Three_different_books", "[f3833f6b-9332-4a1f-ad98-6c3f8e30e163]") {
    REQUIRE(book_store::total({1, 2, 3}) == 2160);
}

TEST_CASE("Four_different_books", "[1951a1db-2fb6-4cd1-a69a-f691b6dd30a2]") {
    REQUIRE(book_store::total({1, 2, 3, 4}) == 2560);
}

TEST_CASE("Five_different_books", "[d70f6682-3019-4c3f-aede-83c6a8c647a3]") {
    REQUIRE(book_store::total({1, 2, 3, 4, 5}) == 3000);
}

TEST_CASE("Two_groups_of_four_is_cheaper_than_group_of_five_plus_group_of_three", "[78cacb57-911a-45f1-be52-2a5bd428c634]") {
    REQUIRE(book_store::total({1, 1, 2, 2, 3, 3, 4, 5}) == 5120);
}

TEST_CASE("Two_groups_of_four_is_cheaper_than_groups_of_five_and_three", "[f808b5a4-e01f-4c0d-881c-f7b90d9739da]") {
    REQUIRE(book_store::total({1, 1, 2, 3, 4, 4, 5, 5}) == 5120);
}

TEST_CASE("Group_of_four_plus_group_of_two_is_cheaper_than_two_groups_of_three", "[fe96401c-5268-4be2-9d9e-19b76478007c]") {
    REQUIRE(book_store::total({1, 1, 2, 2, 3, 4}) == 4080);
}

TEST_CASE("Two_each_of_first_four_books_and_one_copy_each_of_rest", "[68ea9b78-10ad-420e-a766-836a501d3633]") {
    REQUIRE(book_store::total({1, 1, 2, 2, 3, 3, 4, 4, 5}) == 5560);
}

TEST_CASE("Two_copies_of_each_book", "[c0a779d5-a40c-47ae-9828-a340e936b866]") {
    REQUIRE(book_store::total({1, 1, 2, 2, 3, 3, 4, 4, 5, 5}) == 6000);
}

TEST_CASE("Three_copies_of_first_book_and_two_each_of_remaining", "[18fd86fe-08f1-4b68-969b-392b8af20513]") {
    REQUIRE(book_store::total({1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 1}) == 6800);
}

TEST_CASE("Three_each_of_first_two_books_and_two_each_of_remaining_books", "[0b19a24d-e4cf-4ec8-9db2-8899a41af0da]") {
    REQUIRE(book_store::total({1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 2}) == 7520);
}

TEST_CASE("Four_groups_of_four_are_cheaper_than_two_groups_each_of_five_and_three", "[bb376344-4fb2-49ab-ab85-e38d8354a58d]") {
    REQUIRE(book_store::total({1, 1, 2, 2, 3, 3, 4, 5, 1, 1, 2, 2, 3, 3, 4, 5}) == 10240);
}

TEST_CASE("Check_that_groups_of_four_are_created_properly_even_when_there_are_more_groups_of_three_than_groups_of_five", "[5260ddde-2703-4915-b45a-e54dbbac4303]") {
    REQUIRE(book_store::total({1, 1, 1, 1, 1, 1,
                               2, 2, 2, 2, 2, 2,
                               3, 3, 3, 3, 3, 3,
                               4, 4, 5, 5}) == 14560);
}

TEST_CASE("One_group_of_one_and_four_is_cheaper_than_one_group_of_two_and_three", "[b0478278-c551-4747-b0fc-7e0be3158b1f]") {
    REQUIRE(book_store::total({1, 1, 2, 3, 4}) == 3360);
}

TEST_CASE("One_group_of_one_and_two_plus_three_groups_of_four_is_cheaper_than_one_group_of_each_size", "[cf868453-6484-4ae1-9dfc-f8ee85bbde01]") {
    REQUIRE(book_store::total({1,
                               2, 2,
                               3, 3, 3,
                               4, 4, 4, 4,
                               5, 5, 5, 5, 5}) == 10000);
}

#endif