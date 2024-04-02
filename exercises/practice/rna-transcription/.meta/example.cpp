#include <algorithm>
#include <iterator>

#include "rna_transcription.h"

using namespace std;

namespace rna_transcription {

char to_rna(const char nucleotide) {
    const string dna_nucleotides("CGAT");
    const string rna_nucleotides("GCUA");
    const auto pos = dna_nucleotides.find(nucleotide);
    if (pos != string::npos) {
        return rna_nucleotides[pos];
    }
    return 0;
}

string to_rna(string const& sequence) {
    string transcription;
    transform(sequence.begin(), sequence.end(), back_inserter(transcription),
              [](char c) { return to_rna(c); });
    return transcription;
}

}  // namespace rna_transcription
