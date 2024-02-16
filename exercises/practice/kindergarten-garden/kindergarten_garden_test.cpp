#include "kindergarten_garden.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// improves error messages with triangle flavor enum text instead of integers:
CATCH_REGISTER_ENUM(kindergarten_garden::Plants,
        kindergarten_garden::Plants::clover,
        kindergarten_garden::Plants::grass,
        kindergarten_garden::Plants::violets,
        kindergarten_garden::Plants::radishes)

TEST_CASE("garden with single student", "[1fc316ed-17ab-4fba-88ef-3ae78296b692]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::radishes, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::grass, kindergarten_garden::Plants::grass};
  REQUIRE(kindergarten_garden::plants("RC\nGG", "Alice") == expected);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("different garden with single student", "[acd19dc1-2200-4317-bc2a-08f021276b40]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::violets, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::radishes, kindergarten_garden::Plants::clover};
  REQUIRE(kindergarten_garden::plants("VC\nRC", "Alice") == expected);
}

TEST_CASE("garden with two students", "[c376fcc8-349c-446c-94b0-903947315757]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::clover, kindergarten_garden::Plants::grass, kindergarten_garden::Plants::radishes, kindergarten_garden::Plants::clover};
  REQUIRE(kindergarten_garden::plants("VVCG\nVVRC", "Bob") == expected);
}

TEST_CASE("second student's garden", "[2d620f45-9617-4924-9d27-751c80d17db9]") {
    std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::clover, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::clover};
    REQUIRE(kindergarten_garden::plants("VVCCGG\nVVCCGG", "Bob") == expected);
}

TEST_CASE("third student's garden", "[57712331-4896-4364-89f8-576421d69c44]") {
    std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::grass, kindergarten_garden::Plants::grass, kindergarten_garden::Plants::grass, kindergarten_garden::Plants::grass};
    REQUIRE(kindergarten_garden::plants("VVCCGG\nVVCCGG", "Charlie") == expected);
}

TEST_CASE("for Alice, first student's garden", "[149b4290-58e1-40f2-8ae4-8b87c46e765b]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::violets, kindergarten_garden::Plants::radishes, kindergarten_garden::Plants::violets, kindergarten_garden::Plants::radishes};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Alice") == expected);
}

TEST_CASE("for Bob, second student's garden", "[ba25dbbc-10bd-4a37-b18e-f89ecd098a5e]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::clover, kindergarten_garden::Plants::grass, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::clover};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Bob") == expected);
}

TEST_CASE("for Charlie", "[566b621b-f18e-4c5f-873e-be30544b838c]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::violets, kindergarten_garden::Plants::violets, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::grass};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Charlie") == expected);
}

TEST_CASE("for David", "[3ad3df57-dd98-46fc-9269-1877abf612aa]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::radishes, kindergarten_garden::Plants::violets, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::radishes};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "David") == expected);
}

TEST_CASE("for Eve", "[0f0a55d1-9710-46ed-a0eb-399ba8c72db2]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::clover, kindergarten_garden::Plants::grass, kindergarten_garden::Plants::radishes, kindergarten_garden::Plants::grass};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Eve") == expected);
}

TEST_CASE("for Fred", "[a7e80c90-b140-4ea1-aee3-f4625365c9a4]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::grass, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::violets, kindergarten_garden::Plants::clover};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Fred") == expected);
}

TEST_CASE("for Ginny", "[9d94b273-2933-471b-86e8-dba68694c615]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::clover, kindergarten_garden::Plants::grass, kindergarten_garden::Plants::grass, kindergarten_garden::Plants::clover};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Ginny") == expected);
}

TEST_CASE("for Harriet", "[f55bc6c2-ade8-4844-87c4-87196f1b7258]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::violets, kindergarten_garden::Plants::radishes, kindergarten_garden::Plants::radishes, kindergarten_garden::Plants::violets};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Harriet") == expected);
}

TEST_CASE("for Ileana", "[759070a3-1bb1-4dd4-be2c-7cce1d7679ae]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::grass, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::violets, kindergarten_garden::Plants::clover};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Ileana") == expected);
}

TEST_CASE("for Joseph", "[78578123-2755-4d4a-9c7d-e985b8dda1c6]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::violets, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::violets, kindergarten_garden::Plants::grass};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Joseph") == expected);
}

TEST_CASE("for Kincaid, second to last student's garden", "[6bb66df7-f433-41ab-aec2-3ead6e99f65b]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::grass, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::grass};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Kincaid") == expected);
}

TEST_CASE("for Larry, last student's garden", "[d7edec11-6488-418a-94e6-ed509e0fa7eb]") {
  std::array<kindergarten_garden::Plants, 4> expected{kindergarten_garden::Plants::grass, kindergarten_garden::Plants::violets, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::violets};
  REQUIRE(kindergarten_garden::plants("VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Larry") == expected);
}

#endif
