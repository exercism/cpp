#pragma once

#include <array>
#include <vector>

namespace arcade {

class HighScores {
   private:
    std::vector<int> scores;

   public:
    HighScores(std::vector<int> scores) : scores(scores){};

    std::vector<int> list_scores();

    int latest_score();

    int personal_best();

    std::vector<int> top_three();
};

}  // namespace arcade
