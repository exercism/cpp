#pragma once

#include <string>

namespace rna_transcription {

char to_rna(char nucleotide);
std::string to_rna(std::string const& nucleotide);

}  // namespace rna_transcription
