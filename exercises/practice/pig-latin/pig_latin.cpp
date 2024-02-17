#include "pig_latin.h"

#include <algorithm>
#include <array>

namespace pig_latin {

namespace {

[[nodiscard]] bool startswith(std::string_view word, std::string_view begin) {
    if (word.length() < begin.length()) {
        return false;
    }
    return word.substr(0, begin.length()) == begin;
}

[[nodiscard]] std::string translate_word(std::string_view word) {
    std::string translated{word};

    constexpr std::array<std::string_view, 7> vowel_begin = {
        "a", "e", "i", "o", "u", "xr", "yt"};

    if (std::any_of(vowel_begin.begin(), vowel_begin.end(),
                    [word](auto begin) { return startswith(word, begin); })) {
        return translated + "ay";
    }

    auto rotate = [](auto const& w) { return w.substr(1) + w[0]; };

    if (translated[0] == 'y') {
        translated = rotate(translated);
    }

    constexpr std::array<std::string_view, 6> vowel_rotate = {"a", "e", "i",
                                                              "o", "u", "y"};
    while (std::none_of(
        vowel_rotate.begin(), vowel_rotate.end(),
        [&translated](auto begin) { return translated[0] == begin[0]; })) {
        translated = rotate(translated);
    }

    if (translated.back() == 'q' && translated.front() == 'u') {
        translated = rotate(translated);
    }

    return translated + "ay";
}

}  // namespace

std::string translate(std::string_view sentence) {
    std::string translated;
    while (true) {
        auto const next_space = sentence.find(' ');
        auto const word_len = next_space != std::string_view::npos
                                  ? next_space
                                  : sentence.length();
        translated.append(translate_word(sentence.substr(0, word_len)));
        if (next_space == std::string_view::npos) {
            return translated;
        }
        translated += ' ';
        sentence = sentence.substr(next_space + 1);
    }
    return translated;
}

}  // namespace pig_latin
