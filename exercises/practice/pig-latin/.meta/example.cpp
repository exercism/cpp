#include "pig_latin.h"

namespace pig_latin {
std::string translate_word(std::string word) {
    for (std::string start : {"a", "e", "i", "o", "u", "yt", "xr"}) {
        if (word.substr(0, start.size()) == start) return word + "ay";
    }
    for (std::string start : {"thr", "sch", "squ", "ch", "qu", "th", "rh"}) {
        if (word.substr(0, start.size()) == start)
            return word.substr(start.size()) + start + "ay";
    }
    return word.substr(1) + word.front() + "ay";
}

std::string translate(std::string_view phrase) {
    size_t start = 0;
    std::string translation{};
    for (size_t found = phrase.find(' '); found != std::string::npos;
         found = phrase.find(' ', start)) {
        translation += translate_word(std::string(phrase.begin() + start,
                                                  phrase.begin() + found)) +
                       " ";
        start = found + 1;
    }
    if (start != phrase.size())
        translation +=
            translate_word(std::string(phrase.begin() + start, phrase.end()));

    return translation;
}
}  // namespace pig_latin
