#include "last_will.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("Family secrets have not been altered", "[task_1]") {
    // We cannot test the existence of a namespace in the compiled
    // Code.
    // This test merely checks if the numbers in the file have
    // been changed. They have to be correct for the test to work.

    REQUIRE(zhang::bank_number_part(1) == 8541);
    REQUIRE(zhang::bank_number_part(3) == 8541 * 3 % 10'000);
    REQUIRE(khan::bank_number_part(1) == 4142);
    REQUIRE(khan::bank_number_part(3) == 4142 * 3 % 10'000);
    REQUIRE(garcia::bank_number_part(1) == 4023);
    REQUIRE(garcia::bank_number_part(3) == 4023 * 3 % 10'000);

    REQUIRE(zhang::red::code_fragment() == 512);
    REQUIRE(khan::red::code_fragment() == 148);
    REQUIRE(garcia::red::code_fragment() == 118);

    REQUIRE(zhang::blue::code_fragment() == 677);
    REQUIRE(khan::blue::code_fragment() == 875);
    REQUIRE(garcia::blue::code_fragment() == 923);
}

TEST_CASE("Account number assembly function exists in correct namespace",
          "[task_2]") {
    REQUIRE_NOTHROW(estate_executor::assemble_account_number(0));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Account number assembly works correctly", "[task_2]") {
    int account_with_secret_1{16706};
    int account_with_secret_23{14238};

    REQUIRE(estate_executor::assemble_account_number(1) ==
            account_with_secret_1);
    REQUIRE(estate_executor::assemble_account_number(23) ==
            account_with_secret_23);
}

TEST_CASE("Code fragment number assembly function exists in correct namespace",
          "[task_3]") {
    REQUIRE_NOTHROW(estate_executor::assemble_code());
}

TEST_CASE("Code fragments fit correctly", "[task_3]") {
    int final_code{1925550};

    REQUIRE(estate_executor::assemble_code() == final_code);
}

#endif
