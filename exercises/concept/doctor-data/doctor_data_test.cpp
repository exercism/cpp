#include "doctor_data.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("Create different probes", "[task_1]") {
    heaven::Vessel bob{"Robert Johansson", 1};
    heaven::Vessel will{"Riker", 2, star_map::System::BetaHydri};
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Create drone from replication", "[task_1]") {
    heaven::Vessel bob{"Robert Johansson", 1};
    heaven::Vessel bob5 = bob.replicate("Mario");
    REQUIRE(bob5.current_system == star_map::System::Sol);
    REQUIRE(bob5.generation == 2);
}

TEST_CASE("Check buster mechanics", "[task_3]") {
    heaven::Vessel bob6{"Homer", 3, star_map::System::EpsilonEridani};
    REQUIRE(bob6.busters == 0);
    bob6.make_buster();
    REQUIRE(bob6.busters == 1);
    bool success = bob6.shoot_buster();
    REQUIRE(success);
    REQUIRE(bob6.busters == 0);
    success = bob6.shoot_buster();
    REQUIRE_FALSE(success);
}

TEST_CASE("Check non-class functions", "[task_4]") {
    heaven::Vessel bob1{"Bob", 1, star_map::System::AlphaCentauri};
    heaven::Vessel marv{"Marvin", 2, star_map::System::DeltaEridani};
    heaven::Vessel milo{"Milo", 3, star_map::System::DeltaEridani};
    heaven::Vessel howie{"Howard", 4, star_map::System::Omicron2Eridani};

    REQUIRE("Bob" == heaven::get_older_bob(bob1, marv));
    REQUIRE(heaven::in_the_same_system(marv, milo));
    REQUIRE_FALSE(heaven::in_the_same_system(marv, howie));
}

#endif
