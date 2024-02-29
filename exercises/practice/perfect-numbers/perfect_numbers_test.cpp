#include "perfect_numbers.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// improves error messages with enum text instead of integers:
CATCH_REGISTER_ENUM(perfect_numbers::classification,
        perfect_numbers::classification::perfect,
        perfect_numbers::classification::abundant,
        perfect_numbers::classification::deficient)

TEST_CASE("Smallest perfect number is classified correctly", "[163e8e86-7bfd-4ee2-bd68-d083dc3381a3]") {
	REQUIRE(perfect_numbers::classification::perfect == perfect_numbers::classify(6));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Medium perfect number is classified correctly", "[169a7854-0431-4ae0-9815-c3b6d967436d]") {
	REQUIRE(perfect_numbers::classification::perfect == perfect_numbers::classify(28));
}

TEST_CASE("Large perfect number is classified correctly", "[ee3627c4-7b36-4245-ba7c-8727d585f402]") {
	REQUIRE(perfect_numbers::classification::perfect == perfect_numbers::classify(33550336));
}

TEST_CASE("Smallest abundant number is classified correctly", "[80ef7cf8-9ea8-49b9-8b2d-d9cb3db3ed7e]") {
	REQUIRE(perfect_numbers::classification::abundant == perfect_numbers::classify(12));
}

TEST_CASE("Medium abundant number is classified correctly", "[3e300e0d-1a12-4f11-8c48-d1027165ab60]") {
	REQUIRE(perfect_numbers::classification::abundant == perfect_numbers::classify(30));
}

TEST_CASE("Large abundant number is classified correctly", "[ec7792e6-8786-449c-b005-ce6dd89a772b]") {
	REQUIRE(perfect_numbers::classification::abundant == perfect_numbers::classify(33550335));
}

TEST_CASE("Smallest prime deficient number is classified correctly", "[e610fdc7-2b6e-43c3-a51c-b70fb37413ba]") {
	REQUIRE(perfect_numbers::classification::deficient == perfect_numbers::classify(2));
}

TEST_CASE("Smallest non-prime deficient number is classified correctly", "[0beb7f66-753a-443f-8075-ad7fbd9018f3]") {
	REQUIRE(perfect_numbers::classification::deficient == perfect_numbers::classify(4));
}

TEST_CASE("Medium deficient number is classified correctly", "[1c802e45-b4c6-4962-93d7-1cad245821ef]") {
	REQUIRE(perfect_numbers::classification::deficient == perfect_numbers::classify(32));
}

TEST_CASE("Large deficient number is classified correctly", "[47dd569f-9e5a-4a11-9a47-a4e91c8c28aa]") {
	REQUIRE(perfect_numbers::classification::deficient == perfect_numbers::classify(33550337));
}

TEST_CASE("Edge case (no factors other than itself) is classified correctly", "[a696dec8-6147-4d68-afad-d38de5476a56]") {
	REQUIRE(perfect_numbers::classification::deficient == perfect_numbers::classify(1));
}

TEST_CASE("Zero is rejected (as it is not a positive integer)", "[72445cee-660c-4d75-8506-6c40089dc302]") {
	REQUIRE_THROWS_AS(perfect_numbers::classify(0),std::domain_error);
}

TEST_CASE("Negative integer is rejected (as it is not a positive integer)", "[2d72ce2c-6802-49ac-8ece-c790ba3dae13]") {
	REQUIRE_THROWS_AS(perfect_numbers::classify(-1),std::domain_error);
}

#endif
