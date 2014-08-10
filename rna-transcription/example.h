#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

#include <string>

namespace transcription
{

extern char to_rna(char nucleotide);
extern std::string to_rna(std::string const& nucleotide);

}

#endif
