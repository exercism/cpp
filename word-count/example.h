#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <map>
#include <string>

namespace word_count
{

std::map<std::string, int> words(std::string const& text);

}

#endif
