#include "body_language.h"
#include "auntie_answers.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// Trick to let the code compile, even if the function has not been implemented:
namespace mary {
    std::string knee_scrached() __attribute__((weak));
    std::string chin_rub() __attribute__((weak));
    std::string raised_shoulder() __attribute__((weak));
}
TEST_CASE("Location signs are defined and correct") {
    REQUIRE_NOTHROW(mary::knee_scrached());
}