#include <algorithm>

#include "high_scores.h"

namespace arcade {

vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    return scores.back();
}

int HighScores::personal_best() {
    return *max_element(scores.begin(), scores.end());
}

vector<int> HighScores::top_three() {
    vector<int> sorted_scores{scores};
    sort(sorted_scores.begin(), sorted_scores.end(), greater<int>());
    size_t limit{3};
    if (scores.size() < limit) limit = scores.size();
    vector<int> top3{};
    for (size_t i{0}; i < limit; ++i) {
        top3.emplace_back(sorted_scores.at(i));
    }

    return top3;
}

}  // namespace arcade
