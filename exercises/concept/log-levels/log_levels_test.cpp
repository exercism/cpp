#include "log_levels.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("Error message", "[task_1]")
{
    const string actual = log_line::message("[ERROR]: Stack overflow");

    const string expected{"Stack overflow"};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Warning message", "[task_1]")
{
    const string actual = log_line::message("[WARNING]: Disk almost full");

    const string expected{"Disk almost full"};

    REQUIRE(actual == expected);
}

TEST_CASE("Info message", "[task_1]")
{
    const string actual = log_line::message("[INFO]: File moved");

    const string expected{"File moved"};

    REQUIRE(actual == expected);
}

TEST_CASE("Error log level", "[task_2]")
{
    const string actual = log_line::log_level("[ERROR]: Disk full");

    const string expected{"ERROR"};

    REQUIRE(actual == expected);
}

TEST_CASE("Warning log level", "[task_2]")
{
    const string actual = log_line::log_level("[WARNING]: Unsafe password");

    const string expected{"WARNING"};

    REQUIRE(actual == expected);
}

TEST_CASE("Info log level", "[task_2]")
{
    const string actual = log_line::log_level("[INFO]: Timezone changed");

    const string expected{"INFO"};

    REQUIRE(actual == expected);
}

TEST_CASE("Error reformat", "[task_3]")
{
    const string actual = log_line::reformat("[ERROR]: Segmentation fault");

    const string expected{"Segmentation fault (ERROR)"};

    REQUIRE(actual == expected);
}

TEST_CASE("Warning reformat", "[task_3]")
{
    const string actual = log_line::reformat("[WARNING]: Decreased performance");

    const string expected{"Decreased performance (WARNING)"};

    REQUIRE(actual == expected);
}

TEST_CASE("Info reformat", "[task_3]")
{
    const string actual = log_line::reformat("[INFO]: Disk defragmented");

    const string expected{"Disk defragmented (INFO)"};

    REQUIRE(actual == expected);
}
#endif
