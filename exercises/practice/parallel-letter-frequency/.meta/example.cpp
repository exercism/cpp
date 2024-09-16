#include "parallel_letter_frequency.h"

#include <algorithm>
#include <cctype>

// Apple Clang does not support C++17 parallel algorithms.
#ifdef __apple_build_version__
#define PAR_UNSEQ
#else
#include <execution>
#define PAR_UNSEQ std::execution::par_unseq,
#endif

namespace parallel_letter_frequency {

namespace {

[[nodiscard]] std::unordered_map<char, size_t> frequency(
    std::string_view const text) {
    std::unordered_map<char, size_t> freq;
    for (unsigned char c : text) {
        if (std::isalpha(c)) {
            freq[std::tolower(c)] += 1;
        }
    }
    return freq;
}

}  // namespace

std::unordered_map<char, size_t> frequency(
    std::vector<std::string_view> const& texts) {
    std::vector<std::unordered_map<char, size_t>> freqs(texts.size());
    // determine frequencies of texts in parallel
    std::transform(PAR_UNSEQ texts.cbegin(), texts.cend(), freqs.begin(),
                   [](auto text) { return frequency(text); });

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
