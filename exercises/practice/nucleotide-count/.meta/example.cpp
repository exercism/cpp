#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count
{

counter::counter(std::string const& sequence)
    : counts_({ {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0} })
{
    for (auto nucleotide : sequence) {
        auto it = counts_.find(nucleotide);
        if (it == counts_.end()) {
            throw std::invalid_argument("Unknown nucleotide");
        }
        ++(it->second);
    }
}

}
