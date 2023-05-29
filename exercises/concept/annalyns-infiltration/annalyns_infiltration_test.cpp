#include "annalyns_infiltration.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("Fast Attack: Knight is awake") {
    bool knight_is_awake{true};
    REQUIRE_FALSE(can_fast_attack(knight_is_awake));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Fast Attack: Knight is sleeping") {
    bool knight_is_awake{false};
    REQUIRE(can_fast_attack(knight_is_awake));
}
TEST_CASE("Can spy: All characters are sleeping") {
    bool knight_is_awake{false};
    bool archer_is_awake{false};
    bool prisoner_is_wake{false};
    REQUIRE_FALSE(can_spy(knight_is_awake, archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can spy: Knight is awake, archer and prisoner are sleeping") {
    bool knight_is_awake{true};
    bool archer_is_awake{false};
    bool prisoner_is_wake{false};
    REQUIRE(can_spy(knight_is_awake, archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can spy: Knight and archer are awake, prisoner is sleeping") {
    bool knight_is_awake{true};
    bool archer_is_awake{true};
    bool prisoner_is_wake{false};
    REQUIRE(can_spy(knight_is_awake, archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can spy: Knight and prisoner are awake, archer is sleeping") {
    bool knight_is_awake{true};
    bool archer_is_awake{false};
    bool prisoner_is_wake{true};
    REQUIRE(can_spy(knight_is_awake, archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can spy: Archer is awake, knight and prisoner are sleeping") {
    bool knight_is_awake{false};
    bool archer_is_awake{true};
    bool prisoner_is_wake{false};
    REQUIRE(can_spy(knight_is_awake, archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can spy: Archer and prisoner are awake, knight is sleeping") {
    bool knight_is_awake{false};
    bool archer_is_awake{true};
    bool prisoner_is_wake{true};
    REQUIRE(can_spy(knight_is_awake, archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can spy: Prisoner is awake,  knight and archer are sleeping") {
    bool knight_is_awake{false};
    bool archer_is_awake{false};
    bool prisoner_is_wake{true};
    REQUIRE(can_spy(knight_is_awake, archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can spy: All characters are awake") {
    bool knight_is_awake{true};
    bool archer_is_awake{true};
    bool prisoner_is_wake{true};
    REQUIRE(can_spy(knight_is_awake, archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can signal prisoner: All characters are sleeping") {
    bool archer_is_awake{false};
    bool prisoner_is_wake{false};
    REQUIRE_FALSE(can_signal_prisoner(archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can signal prisoner: Archer is sleeping,  prisoner is awake") {
    bool archer_is_awake{false};
    bool prisoner_is_wake{true};
    REQUIRE(can_signal_prisoner(archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can signal prisoner: Archer is awake,  prisoner is sleeping") {
    bool archer_is_awake{true};
    bool prisoner_is_wake{false};
    REQUIRE_FALSE(can_signal_prisoner(archer_is_awake, prisoner_is_wake));
}
TEST_CASE("Can signal prisoner:  All characters are awake") {
    bool archer_is_awake{true};
    bool prisoner_is_wake{true};
    REQUIRE_FALSE(can_signal_prisoner(archer_is_awake, prisoner_is_wake));
}
TEST_CASE(
    "Can free prisoner: All characters are sleeping. Dog is not present.") {
    bool knight_is_awake{false};
    bool archer_is_awake{false};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{false};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE("Can free prisoner: All characters are sleeping. Dog is present.") {
    bool knight_is_awake{false};
    bool archer_is_awake{false};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{true};
    REQUIRE(can_free_prisoner(knight_is_awake, archer_is_awake,
                              prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight and archer are sleeping. Prisoner is awake. Dog "
    "is not present.") {
    bool knight_is_awake{false};
    bool archer_is_awake{false};
    bool prisoner_is_wake{true};
    bool pet_dog_is_present{false};
    REQUIRE(can_free_prisoner(knight_is_awake, archer_is_awake,
                              prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight and archer are sleeping. Prisoner is awake. Dog "
    "is present.") {
    bool knight_is_awake{false};
    bool archer_is_awake{false};
    bool prisoner_is_wake{true};
    bool pet_dog_is_present{true};
    REQUIRE(can_free_prisoner(knight_is_awake, archer_is_awake,
                              prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight is sleeping. Archer is awake. Prisoner is "
    "sleeping. Dog is not "
    "present.") {
    bool knight_is_awake{false};
    bool archer_is_awake{true};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{false};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight is sleeping. Archer is awake. Prisoner is "
    "sleeping. Dog is "
    "present.") {
    bool knight_is_awake{false};
    bool archer_is_awake{true};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{true};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight is sleeping. Archer is awake. Prisoner is "
    "awake. Dog is not "
    "present.") {
    bool knight_is_awake{false};
    bool archer_is_awake{true};
    bool prisoner_is_wake{true};
    bool pet_dog_is_present{false};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight is sleeping. Archer is awake. Prisoner is "
    "awake. Dog is present.") {
    bool knight_is_awake{false};
    bool archer_is_awake{true};
    bool prisoner_is_wake{true};
    bool pet_dog_is_present{true};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight is awake. Archer is sleeping. Prisoner is "
    "sleeping. Dog is not "
    "present.") {
    bool knight_is_awake{true};
    bool archer_is_awake{false};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{false};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight is awake. Archer is sleeping. Prisoner is "
    "sleeping. Dog is "
    "present.") {
    bool knight_is_awake{true};
    bool archer_is_awake{false};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{true};
    REQUIRE(can_free_prisoner(knight_is_awake, archer_is_awake,
                              prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight is awake. Archer is sleeping. Prisoner is "
    "awake. Dog is not "
    "present") {
    bool knight_is_awake{true};
    bool archer_is_awake{false};
    bool prisoner_is_wake{true};
    bool pet_dog_is_present{false};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight is awake. Archer is sleeping. Prisoner is "
    "awake. Dog is present") {
    bool knight_is_awake{true};
    bool archer_is_awake{false};
    bool prisoner_is_wake{true};
    bool pet_dog_is_present{true};
    REQUIRE(can_free_prisoner(knight_is_awake, archer_is_awake,
                              prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight and archer are awake. Prisoner is sleeping. Dog "
    "is present") {
    bool knight_is_awake{true};
    bool archer_is_awake{true};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{true};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight and archer are awake. Prisoner is awake. Dog is "
    "not present") {
    bool knight_is_awake{true};
    bool archer_is_awake{true};
    bool prisoner_is_wake{true};
    bool pet_dog_is_present{false};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight and archer are awake. Prisoner is awake. Dog is "
    "present") {
    bool knight_is_awake{true};
    bool archer_is_awake{true};
    bool prisoner_is_wake{true};
    bool pet_dog_is_present{true};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE(
    "Can free prisoner: Knight and archer are awake. Prisoner is sleeping. Dog "
    "is not present") {
    bool knight_is_awake{true};
    bool archer_is_awake{true};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{false};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}
TEST_CASE("Can free prisoner: Everyone is sleeping. Dog is not present") {
    bool knight_is_awake{false};
    bool archer_is_awake{false};
    bool prisoner_is_wake{false};
    bool pet_dog_is_present{false};
    REQUIRE_FALSE(can_free_prisoner(knight_is_awake, archer_is_awake,
                                    prisoner_is_wake, pet_dog_is_present));
}

#endif
