#include <ctype.h>
#include <set>
#include <utility>
#include "isogram.h"

using std::string;

namespace isogram {
 
bool is_isogram(string const input_str)
{
    std::set<char> chars;
    std::pair<std::set<char>::iterator, bool> ret;
    
    for (char const ch : input_str)
    {
        if (isalnum(ch))
        {
            ret = chars.insert(tolower(ch));
            if (ret.second == false)
            {
                return false;
            }
        }
    }
    
    return true;
}
    
}
