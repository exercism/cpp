#pragma once

#include <array>
#include <vector>

using namespace std;

namespace arcade {

class HighScores {
   private:
    vector<int> scores;

   public:
    HighScores(vector<int> scores) : scores(scores){};

    vector<int> list_scores();

    int latest_score();

    int personal_best();

    vector<int> top_three();
};

}  // namespace arcade
