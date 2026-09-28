#include "flower_field.h"
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

TEST_CASE("no rows", "[237ff487-467a-47e1-9b01-8a891844f86c]") {
    const std::vector<std::string> expected{};
    REQUIRE(expected == flower_field::annotate({}));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("no columns", "[4b4134ec-e20f-439c-a295-664c38950ba1]") {
    const std::vector<std::string> expected{""};
    REQUIRE(expected == flower_field::annotate({""}));
}

TEST_CASE("no flowers", "[d774d054-bbad-4867-88ae-069cbd1c4f92]") {
    const std::vector<std::string> expected{"   ", "   ", "   "};
    REQUIRE(expected == flower_field::annotate({"   ", "   ", "   "}));
}

TEST_CASE("garden full of flowers", "[225176a0-725e-43cd-aa13-9dced501f16e]") {
    const std::vector<std::string> expected{"***", "***", "***"};
    REQUIRE(expected == flower_field::annotate({"***", "***", "***"}));
}

TEST_CASE("flower surrounded by spaces",
          "[3f345495-f1a5-4132-8411-74bd7ca08c49]") {
    const std::vector<std::string> expected{"111", "1*1", "111"};
    REQUIRE(expected == flower_field::annotate({"   ", " * ", "   "}));
}

TEST_CASE("space surrounded by flowers",
          "[6cb04070-4199-4ef7-a6fa-92f68c660fca]") {
    const std::vector<std::string> expected{"***", "*8*", "***"};
    REQUIRE(expected == flower_field::annotate({"***", "* *", "***"}));
}

TEST_CASE("horizontal line", "[272d2306-9f62-44fe-8ab5-6b0f43a26338]") {
    const std::vector<std::string> expected{"1*2*1"};
    REQUIRE(expected == flower_field::annotate({" * * "}));
}

TEST_CASE("horizontal line, flowers at edges",
          "[c6f0a4b2-58d0-4bf6-ad8d-ccf4144f1f8e]") {
    const std::vector<std::string> expected{"*1 1*"};
    REQUIRE(expected == flower_field::annotate({"*   *"}));
}

TEST_CASE("vertical line", "[a54e84b7-3b25-44a8-b8cf-1753c8bb4cf5]") {
    const std::vector<std::string> expected{"1", "*", "2", "*", "1"};
    REQUIRE(expected == flower_field::annotate({" ", "*", " ", "*", " "}));
}

TEST_CASE("vertical line, flowers at edges",
          "[b40f42f5-dec5-4abc-b167-3f08195189c1]") {
    const std::vector<std::string> expected{"*", "1", " ", "1", "*"};
    REQUIRE(expected == flower_field::annotate({"*", " ", " ", " ", "*"}));
}

TEST_CASE("cross", "[58674965-7b42-4818-b930-0215062d543c]") {
    const std::vector<std::string> expected{" 2*2 ", "25*52", "*****", "25*52",
                                            " 2*2 "};
    REQUIRE(expected == flower_field::annotate(
                            {"  *  ", "  *  ", "*****", "  *  ", "  *  "}));
}

TEST_CASE("large garden", "[dd9d4ca8-9e68-4f78-a677-a2a70fd7a7b8]") {
    const std::vector<std::string> expected{"1*22*1", "12*322", " 123*2",
                                            "112*4*", "1*22*2", "111111"};
    REQUIRE(expected == flower_field::annotate({" *  * ", "  *   ", "    * ",
                                                "   * *", " *  * ", "      "}));
}

#endif
