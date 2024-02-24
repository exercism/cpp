#include "parallel_letter_frequency.h"

#include <algorithm>
#include <cctype>
#include <execution>

namespace parallel_letter_frequency {

namespace {

[[nodiscard]] std::unordered_map<char, size_t> frequency(
    std::string_view const text) {
    std::unordered_map<char, size_t> freq;
    for (unsigned char c : text) freq[std::tolower(c)] += 1;
    return freq;
}

}  // namespace

std::unordered_map<char, size_t> frequency(
    std::vector<std::string_view> const& texts) {
    std::vector<std::unordered_map<char, size_t>> freqs(texts.size());
    // determine frequencies of texts in parallel
    std::transform(std::execution::par_unseq, texts.cbegin(), texts.cend(),
                   freqs.begin(), [](auto text) { return frequency(text); });

    // combine individual frequencies (this happens sequentially)
    std::unordered_map<char, size_t> totals{};
    for (auto const& single_text_freqs : freqs) {
        for (auto const [c, count] : single_text_freqs) {
            totals[c] += count;
        }
    }

    return totals;
}

}  // namespace parallel_letter_frequency
