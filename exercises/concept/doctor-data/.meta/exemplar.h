#pragma once

#include <string>

namespace star_map {
enum class System {
    EpsilonEridani,
    Sol,
    Omicron2Eridani,
    DeltaEridani,
    AlphaCentauri,
    BetaHydri
};
}
namespace heaven {
class Vessel {
   public:
    Vessel(std::string name, int generation,
           star_map::System current_system = star_map::System::Sol);
    void make_buster();
    bool shoot_buster();
    Vessel replicate(std::string name);

    std::string name{};
    int generation{};
    star_map::System current_system{};
    int busters{};
};

std::string get_older_bob(Vessel& vessel1, Vessel& vessel2);
bool in_the_same_system(Vessel& vessel1, Vessel& vessel2);

}  // namespace heaven
