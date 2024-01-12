#include "resistor_color_duo.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE("Brown and black", "[ce11995a-5b93-4950-a5e9-93423693b2fc]") {
	REQUIRE(10 == resistor_color_duo::value({"brown", "black"}));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Blue and grey", "[7bf82f7a-af23-48ba-a97d-38d59406a920]") {
	REQUIRE(68 == resistor_color_duo::value({"blue", "grey"}));
}

TEST_CASE("Yellow and violet", "[f1886361-fdfd-4693-acf8-46726fe24e0c]") {
	REQUIRE(47 == resistor_color_duo::value({"yellow", "violet"}));
}

TEST_CASE("White and red", "[b7a6cbd2-ae3c-470a-93eb-56670b305640]") {
	REQUIRE(92 == resistor_color_duo::value({"white", "red"}));
}

TEST_CASE("Orange and orange", "[77a8293d-2a83-4016-b1af-991acc12b9fe]") {
	REQUIRE(33 == resistor_color_duo::value({"orange", "orange"}));
}

TEST_CASE("Ignore additional colors", "[0c4fb44f-db7c-4d03-afa8-054350f156a8]") {
	REQUIRE(51 == resistor_color_duo::value({"green", "brown", "orange"}));
}

TEST_CASE("Black and brown, one-digit", "[4a8ceec5-0ab4-4904-88a4-daf953a5e818]") {
	REQUIRE(1 == resistor_color_duo::value({"black", "brown"}));
}

#endif
