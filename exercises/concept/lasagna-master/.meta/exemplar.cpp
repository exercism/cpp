#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(const std::vector<std::string>& layers, int prepTime) {
    return layers.size() * prepTime;
}

amount quantities(const std::vector<std::string>& layers) {
    amount result{};
    for (auto layer : layers) {
        if (layer == "sauce") {
            result.sauce += 0.2;
        } else if (layer == "noodles") {
            result.noodles += 50;
        }
    }
    return result;
}

void addSecretIngredient(std::vector<std::string>& myList,
                         const std::vector<std::string>& friendsList) {
    myList.back() = friendsList.back();
}

void addSecretIngredient(std::vector<std::string>& myList,
                         const std::string& secretIngredient) {
    myList.back() = secretIngredient;
}

std::vector<double> scaleRecipe(const std::vector<double>& quantities,
                                int portions) {
    std::vector<double> result(quantities);
    for (auto& quantity : result) {
        quantity *= portions / 2.0;
    }
    return result;
}

}  // namespace lasagna_master
