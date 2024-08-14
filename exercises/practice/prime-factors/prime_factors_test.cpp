#include "prime_factors.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("no factors", "[factors][924fc966-a8f5-4288-82f2-6b9224819ccd]") {
    const std::vector<long long> expected{};

    const std::vector<long long> actual{prime_factors::of(1)};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("prime number", "[factors][17e30670-b105-4305-af53-ddde182cb6ad]") {
    const std::vector<long long> expected{2};

    const std::vector<long long> actual{prime_factors::of(2)};

    REQUIRE(expected == actual);
}

TEST_CASE("another prime number",
          "[factors][238d57c8-4c12-42ef-af34-ae4929f94789]") {
    const std::vector<long long> expected{3};

    const std::vector<long long> actual{prime_factors::of(3)};

    REQUIRE(expected == actual);
}

TEST_CASE("square of a prime",
          "[factors][f59b8350-a180-495a-8fb1-1712fbee1158]") {
    const std::vector<long long> expected{3, 3};

    const std::vector<long long> actual{prime_factors::of(9)};

    REQUIRE(expected == actual);
}

TEST_CASE("product of first prime",
          "[factors][756949d3-3158-4e3d-91f2-c4f9f043ee70]") {
    const std::vector<long long> expected{2, 2};

    const std::vector<long long> actual{prime_factors::of(4)};

    REQUIRE(expected == actual);
}

TEST_CASE("cube of a prime",
          "[factors][bc8c113f-9580-4516-8669-c5fc29512ceb]") {
    const std::vector<long long> expected{2, 2, 2};

    const std::vector<long long> actual{prime_factors::of(8)};

    REQUIRE(expected == actual);
}

TEST_CASE("product of second prime",
          "[factors][7d6a3300-a4cb-4065-bd33-0ced1de6cb44]") {
    const std::vector<long long> expected{3, 3, 3};

    const std::vector<long long> actual{prime_factors::of(27)};

    REQUIRE(expected == actual);
}

TEST_CASE("product of third prime",
          "[factors][073ac0b2-c915-4362-929d-fc45f7b9a9e4]") {
    const std::vector<long long> expected{5, 5, 5, 5};

    const std::vector<long long> actual{prime_factors::of(625)};

    REQUIRE(expected == actual);
}

TEST_CASE("product of first and second prime",
          "[factors][6e0e4912-7fb6-47f3-a9ad-dbcd79340c75]") {
    const std::vector<long long> expected{2, 3};

    const std::vector<long long> actual{prime_factors::of(6)};

    REQUIRE(expected == actual);
}

TEST_CASE("product of primes and non-primes",
          "[factors][00485cd3-a3fe-4fbe-a64a-a4308fc1f870]") {
    const std::vector<long long> expected{2, 2, 3};

    const std::vector<long long> actual{prime_factors::of(12)};

    REQUIRE(expected == actual);
}

TEST_CASE("product of primes",
          "[factors][02251d54-3ca1-4a9b-85e1-b38f4b0ccb91]") {
    const std::vector<long long> expected{5, 17, 23, 461};

    const std::vector<long long> actual{prime_factors::of(901255)};

    REQUIRE(expected == actual);
}

TEST_CASE("factors include a large prime",
          "[factors][070cf8dc-e202-4285-aa37-8d775c9cd473]") {
    const std::vector<long long> expected{11, 9539, 894119};

    const std::vector<long long> actual{prime_factors::of(93819012551)};

    REQUIRE(expected == actual);
}

#endif
