#include "pig_latin.h"

namespace pig_latin {
std::string translate_word(const std::string& word) {
    for (const std::string start : {"a", "e", "i", "o", "u", "yt", "xr"}) {
        if (word.substr(0, start.size()) == start) return word + "ay";
    }
    for (const std::string start :
         {"thr", "sch", "squ", "ch", "qu", "th", "rh"}) {
        if (word.substr(0, start.size()) == start)
            return word.substr(start.size()) + start + "ay";
    }
    return word.substr(1) + word.front() + "ay";
}

std::string translate(const std::string& phrase) {
    size_t start = 0;
    std::string translation{};
    for (size_t found = phrase.find(' '); found != std::string::npos;
         found = phrase.find(' ', start)) {
        translation +=
            translate_word(phrase.substr(start, found - start)) + " ";
        start = found + 1;
    }
    if (start != phrase.size())
        translation += translate_word(phrase.substr(start));

    return translation;
}
}  // namespace pig_latin
