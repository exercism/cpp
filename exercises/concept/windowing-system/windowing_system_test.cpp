#include "windowing_system.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

#include <type_traits>

TEST_CASE("size: applies default values", "[task_1]") {
    windowing_system::size aSize{};
    REQUIRE(aSize.width == 80);
    REQUIRE(aSize.height == 60);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("size: provides a resize method", "[task_1]") {
    windowing_system::size aSize{110, 220};
    aSize.resize(120, 330);
    REQUIRE(aSize.width == 120);
    REQUIRE(aSize.height == 330);
}

TEST_CASE("position: allows to create a new instance", "[task_2]") {
    windowing_system::position aPosition{10, 20};
    REQUIRE(aPosition.x == 10);
    REQUIRE(aPosition.y == 20);
}

TEST_CASE("position: applies default values", "[task_2]") {
    windowing_system::position aPosition{};
    REQUIRE(aPosition.x == 0);
    REQUIRE(aPosition.y == 0);
}

TEST_CASE("position: provides a move method", "[task_2]") {
    windowing_system::position aPosition{10, 20};
    aPosition.move(30, 40);
    REQUIRE(aPosition.x == 30);
    REQUIRE(aPosition.y == 40);
}

TEST_CASE("programWindow: allows to create a new instance", "[task_3]") {
    windowing_system::programWindow window{};

    REQUIRE(std::is_same<decltype(window.windowSize), windowing_system::size*>::value);
    REQUIRE(std::is_same<decltype(window.windowPosition), windowing_system::position*>::value);

    REQUIRE(window.screenSize->width == 800);
    REQUIRE(window.screenSize->height == 600);
    REQUIRE(window.windowSize->width == 80);
    REQUIRE(window.windowSize->height == 60);
    REQUIRE(window.windowPosition->x == 0);
    REQUIRE(window.windowPosition->y == 0);
}

TEST_CASE("programWindow: provides a resize method", "[task_4]") {
    windowing_system::programWindow programWindow{};
    windowing_system::size newSize{300, 200};
    programWindow.resize(&newSize);

    REQUIRE(programWindow.windowSize->width == 300);
    REQUIRE(programWindow.windowSize->height == 200);
}

TEST_CASE("programWindow: does not resize below 1", "[task_4]") {
    windowing_system::programWindow programWindow{};
    windowing_system::size newSize{0, -10};
    programWindow.resize(&newSize);

    REQUIRE(programWindow.windowSize->width == 1);
    REQUIRE(programWindow.windowSize->height == 1);
}

TEST_CASE("programWindow: provides a move method", "[task_5]") {
    windowing_system::programWindow programWindow{};
    windowing_system::position newPosition{525, 450};
    programWindow.move(&newPosition);

    REQUIRE(programWindow.windowPosition->x == 525);
    REQUIRE(programWindow.windowPosition->y == 450);
}

TEST_CASE("programWindow: move respects the lower bound for the position", "[task_5]") {
    windowing_system::programWindow programWindow{};
    windowing_system::position newPosition{-20, -10};
    programWindow.move(&newPosition);

    REQUIRE(programWindow.windowPosition->x == 0);
    REQUIRE(programWindow.windowPosition->y == 0);
}

TEST_CASE("programWindow: move respects limits due to screen and window size", "[task_5]") {
    windowing_system::programWindow programWindow{};
    windowing_system::size newSize{100, 100};
    programWindow.resize(&newSize);
    windowing_system::position newPosition{750, 650};
    programWindow.move(&newPosition);

    REQUIRE(programWindow.windowPosition->x == 700);
    REQUIRE(programWindow.windowPosition->y == 500);
}

TEST_CASE("programWindow: resize respects limits due to position and screen size", "[task_5]") {
    windowing_system::programWindow programWindow{};
    windowing_system::position newPosition{710, 525};
    programWindow.move(&newPosition);
    windowing_system::size newSize{1000, 1000};
    programWindow.resize(&newSize);

    REQUIRE(programWindow.windowSize->width == 90);
    REQUIRE(programWindow.windowSize->height == 75);
}

TEST_CASE("changeWindow: resizes the window", "[task_6]") {
    windowing_system::programWindow programWindow{};
    changeWindow(&programWindow);

    REQUIRE(programWindow.windowSize->width == 400);
    REQUIRE(programWindow.windowSize->height == 300);
}

TEST_CASE("changeWindow: moves the window", "[task_6]") {
    windowing_system::programWindow programWindow{};
    changeWindow(&programWindow);

    REQUIRE(programWindow.windowPosition->x == 100);
    REQUIRE(programWindow.windowPosition->y == 150);
}

#endif
