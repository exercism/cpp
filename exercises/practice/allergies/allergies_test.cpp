#include "allergies.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("testing for eggs allergy -> not allergic to anything", "[17fc7296-2440-4ac4-ad7b-d07c321bc5a0]") {
	REQUIRE(false == allergies::allergy_test(0).is_allergic_to("eggs"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("testing for eggs allergy -> allergic only to eggs", "[07ced27b-1da5-4c2e-8ae2-cb2791437546]") {
	REQUIRE(true == allergies::allergy_test(1).is_allergic_to("eggs"));
}

TEST_CASE("testing for eggs allergy -> allergic to eggs and something else", "[5035b954-b6fa-4b9b-a487-dae69d8c5f96]") {
	REQUIRE(true == allergies::allergy_test(3).is_allergic_to("eggs"));
}

TEST_CASE("testing for eggs allergy -> allergic to something, but not eggs", "[64a6a83a-5723-4b5b-a896-663307403310]") {
	REQUIRE(false == allergies::allergy_test(2).is_allergic_to("eggs"));
}

TEST_CASE("testing for eggs allergy -> allergic to everything", "[90c8f484-456b-41c4-82ba-2d08d93231c6]") {
	REQUIRE(true == allergies::allergy_test(255).is_allergic_to("eggs"));
}

TEST_CASE("testing for peanuts allergy -> not allergic to anything", "[d266a59a-fccc-413b-ac53-d57cb1f0db9d]") {
	REQUIRE(false == allergies::allergy_test(0).is_allergic_to("peanuts"));
}

TEST_CASE("testing for peanuts allergy -> allergic only to peanuts", "[ea210a98-860d-46b2-a5bf-50d8995b3f2a]") {
	REQUIRE(true == allergies::allergy_test(2).is_allergic_to("peanuts"));
}

TEST_CASE("testing for peanuts allergy -> allergic to peanuts and something else", "[eac69ae9-8d14-4291-ac4b-7fd2c73d3a5b]") {
	REQUIRE(true == allergies::allergy_test(7).is_allergic_to("peanuts"));
}

TEST_CASE("testing for peanuts allergy -> allergic to something, but not peanuts", "[9152058c-ce39-4b16-9b1d-283ec6d25085]") {
	REQUIRE(false == allergies::allergy_test(5).is_allergic_to("peanuts"));
}

TEST_CASE("testing for peanuts allergy -> allergic to everything", "[d2d71fd8-63d5-40f9-a627-fbdaf88caeab]") {
	REQUIRE(true == allergies::allergy_test(255).is_allergic_to("peanuts"));
}

TEST_CASE("testing for shellfish allergy -> not allergic to anything", "[b948b0a1-cbf7-4b28-a244-73ff56687c80]") {
	REQUIRE(false == allergies::allergy_test(0).is_allergic_to("shellfish"));
}

TEST_CASE("testing for shellfish allergy -> allergic only to shellfish", "[9ce9a6f3-53e9-4923-85e0-73019047c567]") {
	REQUIRE(true == allergies::allergy_test(4).is_allergic_to("shellfish"));
}

TEST_CASE("testing for shellfish allergy -> allergic to shellfish and something else", "[b272fca5-57ba-4b00-bd0c-43a737ab2131]") {
	REQUIRE(true == allergies::allergy_test(14).is_allergic_to("shellfish"));
}

TEST_CASE("testing for shellfish allergy -> allergic to something, but not shellfish", "[21ef8e17-c227-494e-8e78-470a1c59c3d8]") {
	REQUIRE(false == allergies::allergy_test(10).is_allergic_to("shellfish"));
}

TEST_CASE("testing for shellfish allergy -> allergic to everything", "[cc789c19-2b5e-4c67-b146-625dc8cfa34e]") {
	REQUIRE(true == allergies::allergy_test(255).is_allergic_to("shellfish"));
}

TEST_CASE("testing for strawberries allergy -> not allergic to anything", "[651bde0a-2a74-46c4-ab55-02a0906ca2f5]") {
	REQUIRE(false == allergies::allergy_test(0).is_allergic_to("strawberries"));
}

TEST_CASE("testing for strawberries allergy -> allergic only to strawberries", "[b649a750-9703-4f5f-b7f7-91da2c160ece]") {
	REQUIRE(true == allergies::allergy_test(8).is_allergic_to("strawberries"));
}

TEST_CASE("testing for strawberries allergy -> allergic to strawberries and something else", "[50f5f8f3-3bac-47e6-8dba-2d94470a4bc6]") {
	REQUIRE(true == allergies::allergy_test(28).is_allergic_to("strawberries"));
}

TEST_CASE("testing for strawberries allergy -> allergic to something, but not strawberries", "[23dd6952-88c9-48d7-a7d5-5d0343deb18d]") {
	REQUIRE(false == allergies::allergy_test(20).is_allergic_to("strawberries"));
}

TEST_CASE("testing for strawberries allergy -> allergic to everything", "[74afaae2-13b6-43a2-837a-286cd42e7d7e]") {
	REQUIRE(true == allergies::allergy_test(255).is_allergic_to("strawberries"));
}

TEST_CASE("testing for tomatoes allergy -> not allergic to anything", "[c49a91ef-6252-415e-907e-a9d26ef61723]") {
	REQUIRE(false == allergies::allergy_test(0).is_allergic_to("tomatoes"));
}

TEST_CASE("testing for tomatoes allergy -> allergic only to tomatoes", "[b69c5131-b7d0-41ad-a32c-e1b2cc632df8]") {
	REQUIRE(true == allergies::allergy_test(16).is_allergic_to("tomatoes"));
}

TEST_CASE("testing for tomatoes allergy -> allergic to tomatoes and something else", "[1ca50eb1-f042-4ccf-9050-341521b929ec]") {
	REQUIRE(true == allergies::allergy_test(56).is_allergic_to("tomatoes"));
}

TEST_CASE("testing for tomatoes allergy -> allergic to something, but not tomatoes", "[e9846baa-456b-4eff-8025-034b9f77bd8e]") {
	REQUIRE(false == allergies::allergy_test(40).is_allergic_to("tomatoes"));
}

TEST_CASE("testing for tomatoes allergy -> allergic to everything", "[b2414f01-f3ad-4965-8391-e65f54dad35f]") {
	REQUIRE(true == allergies::allergy_test(255).is_allergic_to("tomatoes"));
}

TEST_CASE("testing for chocolate allergy -> not allergic to anything", "[978467ab-bda4-49f7-b004-1d011ead947c]") {
	REQUIRE(false == allergies::allergy_test(0).is_allergic_to("chocolate"));
}

TEST_CASE("testing for chocolate allergy -> allergic only to chocolate", "[59cf4e49-06ea-4139-a2c1-d7aad28f8cbc]") {
	REQUIRE(true == allergies::allergy_test(32).is_allergic_to("chocolate"));
}

TEST_CASE("testing for chocolate allergy -> allergic to chocolate and something else", "[b0a7c07b-2db7-4f73-a180-565e07040ef1]") {
	REQUIRE(true == allergies::allergy_test(112).is_allergic_to("chocolate"));
}

TEST_CASE("testing for chocolate allergy -> allergic to something, but not chocolate", "[f5506893-f1ae-482a-b516-7532ba5ca9d2]") {
	REQUIRE(false == allergies::allergy_test(80).is_allergic_to("chocolate"));
}

TEST_CASE("testing for chocolate allergy -> allergic to everything", "[02debb3d-d7e2-4376-a26b-3c974b6595c6]") {
	REQUIRE(true == allergies::allergy_test(255).is_allergic_to("chocolate"));
}

TEST_CASE("testing for pollen allergy -> not allergic to anything", "[17f4a42b-c91e-41b8-8a76-4797886c2d96]") {
	REQUIRE(false == allergies::allergy_test(0).is_allergic_to("pollen"));
}

TEST_CASE("testing for pollen allergy -> allergic only to pollen", "[7696eba7-1837-4488-882a-14b7b4e3e399]") {
	REQUIRE(true == allergies::allergy_test(64).is_allergic_to("pollen"));
}

TEST_CASE("testing for pollen allergy -> allergic to pollen and something else", "[9a49aec5-fa1f-405d-889e-4dfc420db2b6]") {
	REQUIRE(true == allergies::allergy_test(224).is_allergic_to("pollen"));
}

TEST_CASE("testing for pollen allergy -> allergic to something, but not pollen", "[3cb8e79f-d108-4712-b620-aa146b1954a9]") {
	REQUIRE(false == allergies::allergy_test(160).is_allergic_to("pollen"));
}

TEST_CASE("testing for pollen allergy -> allergic to everything", "[1dc3fe57-7c68-4043-9d51-5457128744b2]") {
	REQUIRE(true == allergies::allergy_test(255).is_allergic_to("pollen"));
}

TEST_CASE("testing for cats allergy -> not allergic to anything", "[d3f523d6-3d50-419b-a222-d4dfd62ce314]") {
	REQUIRE(false == allergies::allergy_test(0).is_allergic_to("cats"));
}

TEST_CASE("testing for cats allergy -> allergic only to cats", "[eba541c3-c886-42d3-baef-c048cb7fcd8f]") {
	REQUIRE(true == allergies::allergy_test(128).is_allergic_to("cats"));
}

TEST_CASE("testing for cats allergy -> allergic to cats and something else", "[ba718376-26e0-40b7-bbbe-060287637ea5]") {
	REQUIRE(true == allergies::allergy_test(192).is_allergic_to("cats"));
}

TEST_CASE("testing for cats allergy -> allergic to something, but not cats", "[3c6dbf4a-5277-436f-8b88-15a206f2d6c4]") {
	REQUIRE(false == allergies::allergy_test(64).is_allergic_to("cats"));
}

TEST_CASE("testing for cats allergy -> allergic to everything", "[1faabb05-2b98-4995-9046-d83e4a48a7c1]") {
	REQUIRE(true == allergies::allergy_test(255).is_allergic_to("cats"));
}

TEST_CASE("list when: -> no allergies", "[f9c1b8e7-7dc5-4887-aa93-cebdcc29dd8f]") {
	std::unordered_set<std::string> expected ={};
	REQUIRE(expected == allergies::allergy_test(0).get_allergies());
}

TEST_CASE("list when: -> just eggs", "[9e1a4364-09a6-4d94-990f-541a94a4c1e8]") {
	std::unordered_set<std::string> expected ={"eggs"};
	REQUIRE(expected == allergies::allergy_test(1).get_allergies());
}

TEST_CASE("list when: -> just peanuts", "[8851c973-805e-4283-9e01-d0c0da0e4695]") {
	std::unordered_set<std::string> expected ={"peanuts"};
	REQUIRE(expected == allergies::allergy_test(2).get_allergies());
}

TEST_CASE("list when: -> just strawberries", "[2c8943cb-005e-435f-ae11-3e8fb558ea98]") {
	std::unordered_set<std::string> expected ={"strawberries"};
	REQUIRE(expected == allergies::allergy_test(8).get_allergies());
}

TEST_CASE("list when: -> eggs and peanuts", "[6fa95d26-044c-48a9-8a7b-9ee46ec32c5c]") {
	std::unordered_set<std::string> expected ={"eggs", "peanuts"};
	REQUIRE(expected == allergies::allergy_test(3).get_allergies());
}

TEST_CASE("list when: -> more than eggs but not peanuts", "[19890e22-f63f-4c5c-a9fb-fb6eacddfe8e]") {
	std::unordered_set<std::string> expected ={"eggs", "shellfish"};
	REQUIRE(expected == allergies::allergy_test(5).get_allergies());
}

TEST_CASE("list when: -> lots of stuff", "[4b68f470-067c-44e4-889f-c9fe28917d2f]") {
	std::unordered_set<std::string> expected ={"strawberries", "tomatoes", "chocolate", "pollen", "cats"};
	REQUIRE(expected == allergies::allergy_test(248).get_allergies());
}

TEST_CASE("list when: -> everything", "[0881b7c5-9efa-4530-91bd-68370d054bc7]") {
	std::unordered_set<std::string> expected ={"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};
	REQUIRE(expected == allergies::allergy_test(255).get_allergies());
}

TEST_CASE("list when: -> no allergen score parts", "[12ce86de-b347-42a0-ab7c-2e0570f0c65b]") {
	std::unordered_set<std::string> expected ={"eggs", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};
	REQUIRE(expected == allergies::allergy_test(509).get_allergies());
}

TEST_CASE("list when: -> no allergen score parts without highest valid score", "[93c2df3e-4f55-4fed-8116-7513092819cd]") {
	std::unordered_set<std::string> expected ={"eggs"};
	REQUIRE(expected == allergies::allergy_test(257).get_allergies());
}

#endif
