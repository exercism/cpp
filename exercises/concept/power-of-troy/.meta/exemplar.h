#pragma once

#include <memory>
#include <string>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

struct human {
    std::unique_ptr<artifact> possession;
    std::shared_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;
};

void give_new_artifact(human& receiver, std::string item_name);
void exchange_artifacts(std::unique_ptr<artifact>& item_a,
                        std::unique_ptr<artifact>& item_b);
void manifest_power(human& receiver, std::string power_effect);
void use_power(const human& caster, human& receiver);
int power_intensity(const human& caster);

}  // namespace troy
