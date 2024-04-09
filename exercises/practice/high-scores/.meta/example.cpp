#include <algorithm>

#include "high_scores.h"

namespace arcade {

std::vector<int> HighScores::list_scores() { return scores; }

int HighScores::latest_score() { return scores.back(); }

int HighScores::personal_best() {
    return *max_element(scores.begin(), scores.end());
}

std::vector<int> HighScores::top_three() {
    std::vector<int> sorted_scores{scores};
    std::sort(sorted_scores.begin(), sorted_scores.end(), std::greater<int>());
    size_t limit{3};
    if (scores.size() < limit) limit = scores.size();
    return {begin(sorted_scores), begin(sorted_scores) + limit};
    ;
}

}  // namespace arcade
