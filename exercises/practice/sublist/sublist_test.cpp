#include "sublist.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


/*
Lists are ordered and sequential.
https://en.wikipedia.org/wiki/List_%28abstract_data_type%29

Depending on your language, there may need to be some translation
to go from the JSON array to the list representation.
The expectation can be used to generate an expected value
based on your implementation (such as a constant 'EQUAL', 'SUBLIST', etc.).

If appropriate for your track, you'll need to ensure that no pair of expected values are equal.
Otherwise, an implementation that always returns a constant value may falsely pass the tests.
See https://github.com/exercism/xpython/issues/342
*/

CATCH_REGISTER_ENUM(sublist::List_comparison,
        sublist::List_comparison::equal,
        sublist::List_comparison::sublist,
        sublist::List_comparison::superlist,
        sublist::List_comparison::unequal)

TEST_CASE("empty lists", "[97319c93-ebc5-47ab-a022-02a1980e1d29]") {
	sublist::List_comparison expected = sublist::List_comparison::equal;
	REQUIRE(expected == sublist::sublist({}, {}));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("empty list within non empty list", "[de27dbd4-df52-46fe-a336-30be58457382]") {
	sublist::List_comparison expected = sublist::List_comparison::sublist;
	REQUIRE(expected == sublist::sublist({}, {1, 2, 3}));
}

TEST_CASE("non empty list contains empty list", "[5487cfd1-bc7d-429f-ac6f-1177b857d4fb]") {
	sublist::List_comparison expected = sublist::List_comparison::superlist;
	REQUIRE(expected == sublist::sublist({1, 2, 3}, {}));
}

TEST_CASE("list equals itself", "[1f390b47-f6b2-4a93-bc23-858ba5dda9a6]") {
	sublist::List_comparison expected = sublist::List_comparison::equal;
	REQUIRE(expected == sublist::sublist({1, 2, 3}, {1, 2, 3}));
}

TEST_CASE("different lists", "[7ed2bfb2-922b-4363-ae75-f3a05e8274f5]") {
	sublist::List_comparison expected = sublist::List_comparison::unequal;
	REQUIRE(expected == sublist::sublist({1, 2, 3}, {2, 3, 4}));
}

TEST_CASE("false start", "[3b8a2568-6144-4f06-b0a1-9d266b365341]") {
	sublist::List_comparison expected = sublist::List_comparison::sublist;
	REQUIRE(expected == sublist::sublist({1, 2, 5}, {0, 1, 2, 3, 1, 2, 5, 6}));
}

TEST_CASE("consecutive", "[dc39ed58-6311-4814-be30-05a64bc8d9b1]") {
	sublist::List_comparison expected = sublist::List_comparison::sublist;
	REQUIRE(expected == sublist::sublist({1, 1, 2}, {0, 1, 1, 1, 2, 1, 2}));
}

TEST_CASE("sublist at start", "[d1270dab-a1ce-41aa-b29d-b3257241ac26]") {
	sublist::List_comparison expected = sublist::List_comparison::sublist;
	REQUIRE(expected == sublist::sublist({0, 1, 2}, {0, 1, 2, 3, 4, 5}));
}

TEST_CASE("sublist in middle", "[81f3d3f7-4f25-4ada-bcdc-897c403de1b6]") {
	sublist::List_comparison expected = sublist::List_comparison::sublist;
	REQUIRE(expected == sublist::sublist({2, 3, 4}, {0, 1, 2, 3, 4, 5}));
}

TEST_CASE("sublist at end", "[43bcae1e-a9cf-470e-923e-0946e04d8fdd]") {
	sublist::List_comparison expected = sublist::List_comparison::sublist;
	REQUIRE(expected == sublist::sublist({3, 4, 5}, {0, 1, 2, 3, 4, 5}));
}

TEST_CASE("at start of superlist", "[76cf99ed-0ff0-4b00-94af-4dfb43fe5caa]") {
	sublist::List_comparison expected = sublist::List_comparison::superlist;
	REQUIRE(expected == sublist::sublist({0, 1, 2, 3, 4, 5}, {0, 1, 2}));
}

TEST_CASE("in middle of superlist", "[b83989ec-8bdf-4655-95aa-9f38f3e357fd]") {
	sublist::List_comparison expected = sublist::List_comparison::superlist;
	REQUIRE(expected == sublist::sublist({0, 1, 2, 3, 4, 5}, {2, 3}));
}

TEST_CASE("at end of superlist", "[26f9f7c3-6cf6-4610-984a-662f71f8689b]") {
	sublist::List_comparison expected = sublist::List_comparison::superlist;
	REQUIRE(expected == sublist::sublist({0, 1, 2, 3, 4, 5}, {3, 4, 5}));
}

TEST_CASE("first list missing element from second list", "[0a6db763-3588-416a-8f47-76b1cedde31e]") {
	sublist::List_comparison expected = sublist::List_comparison::unequal;
	REQUIRE(expected == sublist::sublist({1, 3}, {1, 2, 3}));
}

TEST_CASE("second list missing element from first list", "[83ffe6d8-a445-4a3c-8795-1e51a95e65c3]") {
	sublist::List_comparison expected = sublist::List_comparison::unequal;
	REQUIRE(expected == sublist::sublist({1, 2, 3}, {1, 3}));
}

TEST_CASE("first list missing additional digits from second list", "[7bc76cb8-5003-49ca-bc47-cdfbe6c2bb89]") {
	sublist::List_comparison expected = sublist::List_comparison::unequal;
	REQUIRE(expected == sublist::sublist({1, 2}, {1, 22}));
}

TEST_CASE("order matters to a list", "[0d7ee7c1-0347-45c8-9ef5-b88db152b30b]") {
	sublist::List_comparison expected = sublist::List_comparison::unequal;
	REQUIRE(expected == sublist::sublist({1, 2, 3}, {3, 2, 1}));
}

TEST_CASE("same digits but different numbers", "[5f47ce86-944e-40f9-9f31-6368aad70aa6]") {
	sublist::List_comparison expected = sublist::List_comparison::unequal;
	REQUIRE(expected == sublist::sublist({1, 0, 1}, {10, 1}));
}

#endif
