#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <string>
#include <vector>

namespace protein_translation
{
   std::vector<std::string> protein_translation(std::string rna);
   bool isProtein(std::vector<std::string> arg, std::string rna);
}
#endif
