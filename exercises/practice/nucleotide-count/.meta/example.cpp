#include <stdexcept>

#include "nucleotide_count.h"

namespace nucleotide_count {

std::map<char, int> count(std::string_view dna) {
    std::map<char, int> counter{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    for (auto nucleotide : dna) {
        auto it = counter.find(nucleotide);
        if (it == counter.end()) {
            throw std::invalid_argument("Unknown nucleotide");
        }
        ++(it->second);
    }
    return counter;
}

}  // namespace nucleotide_count
