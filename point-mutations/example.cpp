#include "point_mutations.h"
#include <algorithm>

using namespace std;

namespace mutations
{

dna_sequence::dna_sequence(string const& sequence)
    : sequence_(sequence)
{
}

int dna_sequence::hamming_distance(string const& other_sequence) const
{
    if (other_sequence.length() < sequence_.length()) {
        return dna_sequence(other_sequence).hamming_distance(sequence_);
    }
    int count = 0;
    for (auto p = mismatch(sequence_.begin(), sequence_.end(), other_sequence.begin());
            p.first != sequence_.end();
            p = mismatch(p.first, sequence_.end(), p.second)) {
        ++p.first;
        ++p.second;
        ++count;
    }
    return count;
}

}
