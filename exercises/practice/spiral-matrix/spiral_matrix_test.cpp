#include "spiral_matrix.h"

#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

#include <cstdint>
#include <vector>

TEST_CASE("empty spiral", "[8f584201-b446-4bc9-b132-811c8edd9040]") {
    std::vector<std::vector<uint32_t>> const expected{};
    REQUIRE(expected == spiral_matrix::spiral_matrix(0));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("trivial spiral", "[e40ae5f3-e2c9-4639-8116-8a119d632ab2]") {
    std::vector<std::vector<uint32_t>> const expected = {{1}};
    REQUIRE(expected == spiral_matrix::spiral_matrix(1));
}

TEST_CASE("spiral of size 2", "[cf05e42d-eb78-4098-a36e-cdaf0991bc48]") {
    std::vector<std::vector<uint32_t>> const expected = {
        {1, 2},  //
        {4, 3}   //
    };
    REQUIRE(expected == spiral_matrix::spiral_matrix(2));
}

TEST_CASE("spiral of size 3", "[1c475667-c896-4c23-82e2-e033929de939]") {
    std::vector<std::vector<uint32_t>> expected = {
        {1, 2, 3},  //
        {8, 9, 4},  //
        {7, 6, 5}   //
    };
    REQUIRE(expected == spiral_matrix::spiral_matrix(3));
}

TEST_CASE("spiral of size 4", "[05ccbc48-d891-44f5-9137-f4ce462a759d]") {
    std::vector<std::vector<uint32_t>> const expected = {
        {1, 2, 3, 4},     //
        {12, 13, 14, 5},  //
        {11, 16, 15, 6},  //
        {10, 9, 8, 7}     //
    };
    REQUIRE(expected == spiral_matrix::spiral_matrix(4));
}

TEST_CASE("spiral of size 5", "[f4d2165b-1738-4e0c-bed0-c459045ae50d]") {
    std::vector<std::vector<uint32_t>> const expected = {
        {1, 2, 3, 4, 5},      //
        {16, 17, 18, 19, 6},  //
        {15, 24, 25, 20, 7},  //
        {14, 23, 22, 21, 8},  //
        {13, 12, 11, 10, 9}   //
    };
    REQUIRE(expected == spiral_matrix::spiral_matrix(5));
}
#endif
