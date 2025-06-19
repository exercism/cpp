#include "power_of_troy.h"

namespace troy {

void give_new_artifact(human& receiver, std::string item_name) {
    receiver.possession =
        std::make_unique<artifact>(artifact{item_name});  // Include hint!
}

void exchange_artifacts(std::unique_ptr<artifact>& item_a,
                        std::unique_ptr<artifact>& item_b) {
    std::swap(item_a, item_b);
}

void manifest_power(human& receiver, std::string power_effect) {
    receiver.own_power = std::make_shared<power>(power{power_effect});
}

void use_power(const human& caster, human& receiver) {
    receiver.influenced_by = caster.own_power;
}

int power_intensity(const human& caster) {
    return caster.own_power.use_count();
}

}  // namespace troy
