#include "power_of_troy.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace troy;

TEST_CASE("Create a human", "[task_1]") {
    human lanfeust{};

    REQUIRE(lanfeust.possession == nullptr);
    REQUIRE(lanfeust.own_power == nullptr);
    REQUIRE(lanfeust.influenced_by == nullptr);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Give a new artifact to a human", "[task_2]") {
    human lanfeust{};
    std::string pommel{"Magohamoth Ivory Sword Pommel"};

    give_new_artifact(lanfeust, pommel);

    REQUIRE(lanfeust.possession != nullptr);
    REQUIRE(lanfeust.possession->name == pommel);
}

TEST_CASE("Exchange artifact with another human", "[task_3]") {
    human zoltan{};
    std::string worldstone_shard{"Soulstone"};
    give_new_artifact(zoltan, worldstone_shard);
    human tal_rasha{};

    exchange_artifacts(zoltan.possession, tal_rasha.possession);

    REQUIRE(zoltan.possession == nullptr);
    REQUIRE(tal_rasha.possession->name == worldstone_shard);
}

TEST_CASE("Manifest power in a human", "[task_4]") {
    human cian{};
    std::string gift_of_night{"heal"};

    manifest_power(cian, gift_of_night);

    REQUIRE(cian.own_power != nullptr);
    REQUIRE(cian.own_power->effect == gift_of_night);
}

TEST_CASE("Use power on another human", "[task_5]") {
    human cian{};
    manifest_power(cian, "heal");
    human lanfeust{};

    use_power(cian, lanfeust);

    REQUIRE(cian.influenced_by == nullptr);
    REQUIRE(lanfeust.influenced_by == cian.own_power);
}

TEST_CASE("Check power intensity of person without power", "[task_6]") {
    human cixi{};

    REQUIRE(power_intensity(cixi) == 0);
}

TEST_CASE("Check power intensity when not in use", "[task_6]") {
    human nicolede{};
    manifest_power(nicolede, "enchantment");

    REQUIRE(power_intensity(nicolede) == 1);
}

TEST_CASE("Check power intensity when used on just one person", "[task_6]") {
    human nicolede{};
    manifest_power(nicolede, "enchantment");
    human hebus{};

    use_power(nicolede, hebus);

    REQUIRE(power_intensity(nicolede) == 2);
}

TEST_CASE("Check power intensity when used on group of four", "[task_6]") {
    human sue{};
    human reed{};
    human johnny{};
    human ben{};

    human victor{};
    manifest_power(victor, "technopathic super-genius");

    use_power(victor, reed);
    use_power(victor, johnny);
    use_power(victor, ben);
    use_power(victor, sue);

    REQUIRE(power_intensity(victor) == 5);
}

TEST_CASE("Check power intensity drop after usage", "[task_6]") {
    human palpatine{};
    manifest_power(palpatine, "force torrent");

    // let's start a non-canon duel:
    // (Everything in the scope of the brackets is deleted after the brackets
    // close)
    {
        human grievous{};
        use_power(palpatine, grievous);
        REQUIRE(power_intensity(palpatine) == 2);
    }
    REQUIRE(power_intensity(palpatine) == 1);
}

#endif
