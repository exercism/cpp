#include "resistor_color.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE("Black", "[49eb31c5-10a8-4180-9f7f-fea632ab87ef]") {
	REQUIRE(0 == resistor_color::color_code("black"));
}

TEST_CASE("White", "[0a4df94b-92da-4579-a907-65040ce0b3fc]") {
	REQUIRE(9 == resistor_color::color_code("white"));
}

TEST_CASE("Orange", "[5f81608d-f36f-4190-8084-f45116b6f380]") {
	REQUIRE(3 == resistor_color::color_code("orange"));
}


TEST_CASE("Colors", "[581d68fa-f968-4be2-9f9d-880f2fb73cf7]") {
	std::vector<std::string> expected{"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
	REQUIRE(expected == resistor_color::colors());
}
#if defined(EXERCISM_RUN_ALL_TESTS)

#endif
