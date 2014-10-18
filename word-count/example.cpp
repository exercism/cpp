#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(push) 
#pragma warning(disable:4996) 
#endif 

#include "word_count.h"
#include <vector>
#include <locale>
#include <boost/algorithm/string.hpp>

using namespace std;

namespace word_count
{

map<string, int> words(string const& text)
{
    // A less than ideal solution since I can't get regex building in GCC on Travis
    std::map<std::string, int> count;
    std::string normalized = boost::to_lower_copy(text);
    for (unsigned int i = 0; i < normalized.length(); i++)
    {
        auto c = normalized[i];
        normalized[i] = (std::isalnum(c, std::locale()) || c == '\'') ? c : ' ';
    }
    std::vector<std::string> words;
    boost::split(words, normalized, boost::is_any_of("\t "));
    for (auto const& word : words)
    {
        auto const& trimmed = boost::trim_copy_if(word, boost::is_any_of("' "));
        if (!trimmed.empty())
        {
            count[trimmed]++;
        }
    }
    return count;
}

}

#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(pop) 
#endif 
