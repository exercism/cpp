#include "diamond.h"

namespace diamond {
    std::vector<std::string> rows(char middle_letter) {
        if (middle_letter == 'A') return {"A"};
        std::vector<std::string> diamond;
        for(char c{'A'}; c <= middle_letter; ++c) {
            int outer_spacing = middle_letter - c;
            std::string row{};
            row.append(std::string(outer_spacing, ' '));
            row += c;
            int inner_spacing = (c - 'A') * 2 - 1;
            if (inner_spacing > 0) {
                row.append(std::string(inner_spacing, ' '));
                row += c;
            }
            row.append(std::string(outer_spacing, ' '));
            diamond.emplace_back(row);
        }
        for(int i{middle_letter - 'A' - 1}; i >= 0; --i) {
            diamond.emplace_back(diamond.at(i));
        }
        return diamond;
    }
}  // namespace diamond
