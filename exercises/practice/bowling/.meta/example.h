#pragma once
#include <vector>

namespace bowling {

class Game {
   public:
    Game();
    void roll(int pins);
    int score();

   private:
    std::vector<int> rolls;

    bool isValidRollSequence(const std::vector<int>& rolls) const;
    bool isCompleteGame(const std::vector<int>& rolls) const;
};

}  // namespace bowling