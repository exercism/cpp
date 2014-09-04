#include "word_count.h"
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/tokenizer.hpp>

using namespace std;

namespace word_count
{

map<string, int> words(string const& text)
{
    map<string, int> counts;
    for (auto const& word : boost::tokenizer<>(text)) {
        counts[boost::to_lower_copy(word)]++;
    }
    return counts;
}

}
