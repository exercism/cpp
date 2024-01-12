#include "minesweeper.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

/*
 The expected outputs are represented as arrays of strings to   
 improve readability in this JSON file.                         
 Your track may choose whether to present the input as a single 
 string (concatenating all the lines) or as the list.           
*/

TEST_CASE("no rows", "[0c5ec4bd-dea7-4138-8651-1203e1cb9f44]") {
	const std::vector<std::string> expected{};
	REQUIRE(expected == minesweeper::annotate({}));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("no columns", "[650ac4c0-ad6b-4b41-acde-e4ea5852c3b8]") {
	const std::vector<std::string> expected{""};
	REQUIRE(expected == minesweeper::annotate({""}));
}

TEST_CASE("no mines", "[6fbf8f6d-a03b-42c9-9a58-b489e9235478]") {
	const std::vector<std::string> expected{"   ", "   ", "   "};
	REQUIRE(expected == minesweeper::annotate({"   ", "   ", "   "}));
}

TEST_CASE("minefield with only mines", "[61aff1c4-fb31-4078-acad-cd5f1e635655]") {
	const std::vector<std::string> expected{"***", "***", "***"};
	REQUIRE(expected == minesweeper::annotate({"***", "***", "***"}));
}

TEST_CASE("mine surrounded by spaces", "[84167147-c504-4896-85d7-246b01dea7c5]") {
	const std::vector<std::string> expected{"111", "1*1", "111"};
	REQUIRE(expected == minesweeper::annotate({"   ", " * ", "   "}));
}

TEST_CASE("space surrounded by mines", "[cb878f35-43e3-4c9d-93d9-139012cccc4a]") {
	const std::vector<std::string> expected{"***", "*8*", "***"};
	REQUIRE(expected == minesweeper::annotate({"***", "* *", "***"}));
}

TEST_CASE("horizontal line", "[7037f483-ddb4-4b35-b005-0d0f4ef4606f]") {
	const std::vector<std::string> expected{"1*2*1"};
	REQUIRE(expected == minesweeper::annotate({" * * "}));
}

TEST_CASE("horizontal line, mines at edges", "[e359820f-bb8b-4eda-8762-47b64dba30a6]") {
	const std::vector<std::string> expected{"*1 1*"};
	REQUIRE(expected == minesweeper::annotate({"*   *"}));
}

TEST_CASE("vertical line", "[c5198b50-804f-47e9-ae02-c3b42f7ce3ab]") {
	const std::vector<std::string> expected{"1", "*", "2", "*", "1"};
	REQUIRE(expected == minesweeper::annotate({" ", "*", " ", "*", " "}));
}

TEST_CASE("vertical line, mines at edges", "[0c79a64d-703d-4660-9e90-5adfa5408939]") {
	const std::vector<std::string> expected{"*", "1", " ", "1", "*"};
	REQUIRE(expected == minesweeper::annotate({"*", " ", " ", " ", "*"}));
}

TEST_CASE("cross", "[4b098563-b7f3-401c-97c6-79dd1b708f34]") {
	const std::vector<std::string> expected{" 2*2 ", "25*52", "*****", "25*52", " 2*2 "};
	REQUIRE(expected == minesweeper::annotate({"  *  ", "  *  ", "*****", "  *  ", "  *  "}));
}

TEST_CASE("large minefield", "[04a260f1-b40a-4e89-839e-8dd8525abe0e]") {
	const std::vector<std::string> expected{"1*22*1", "12*322", " 123*2", "112*4*", "1*22*2", "111111"};
	REQUIRE(expected == minesweeper::annotate({" *  * ", "  *   ", "    * ", "   * *", " *  * ", "      "}));
}

#endif
