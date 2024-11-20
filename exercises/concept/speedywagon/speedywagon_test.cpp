#include "speedywagon.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("connection_check: test for nullptr", "[task_1]") {
    speedywagon::pillar_men_sensor* nothing_connected{nullptr};
    REQUIRE_FALSE(speedywagon::connection_check(nothing_connected));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("connection_check: test for connected sensor", "[task_1]") {
    speedywagon::pillar_men_sensor active_sensor{42, "colloseum", {}};
    REQUIRE(speedywagon::connection_check(&active_sensor));
}

TEST_CASE("activity_counter: sum for three nullptr", "[task_2]") {
    speedywagon::pillar_men_sensor rome[3]{};
    REQUIRE(speedywagon::activity_counter(&rome[0], 3) == 0);
}

TEST_CASE("activity_counter: sum for two with real data", "[task_2]") {
    speedywagon::pillar_men_sensor rome[2]{{4900, "kars", {}},
                                           {4102, "wham", {}}};
    REQUIRE(speedywagon::activity_counter(&rome[0], 2) == 9002);
}

TEST_CASE("activity_counter: sum for a nullptr", "[task_2]") {
    speedywagon::pillar_men_sensor rome[2]{{4900, "kars", {}},
                                           {4102, "wham", {}}};
    REQUIRE(speedywagon::activity_counter(nullptr, 0) == 0);
}

TEST_CASE("alarm_control: works correctly for pointer", "[task_3]") {
    speedywagon::pillar_men_sensor* kars_in_space{nullptr};
    REQUIRE_FALSE(speedywagon::alarm_control(kars_in_space));
}

TEST_CASE("alarm_control: works correctly for nullptr", "[task_3]") {
    speedywagon::pillar_men_sensor santana{0, "Mexico", {1981, 1987}};
    REQUIRE_FALSE(speedywagon::alarm_control(&santana));
    santana.activity = 9002;
    REQUIRE(speedywagon::alarm_control(&santana));
}

TEST_CASE("uv_alarm: works correctly for nullptr", "[task_4]") {
    speedywagon::pillar_men_sensor* wham{nullptr};
    REQUIRE_FALSE(speedywagon::uv_alarm(wham));
}

TEST_CASE("uv_alarm: works correctly with mock data", "[task_4]") {
    speedywagon::pillar_men_sensor wham{0, "Rome", {1, 605, 313, 4000}};
    REQUIRE(speedywagon::uv_alarm(&wham));
    wham.activity = 9001;
    REQUIRE_FALSE(speedywagon::uv_alarm(&wham));
}

#endif
