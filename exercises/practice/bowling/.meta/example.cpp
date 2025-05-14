#include <stdexcept>

#include "bowling.h"

namespace bowling {

Game::Game() : rolls() {}

void Game::roll(int pins) {
    if (pins < 0 || pins > 10) {
        throw std::runtime_error("Invalid roll");
    }
    if (isCompleteGame(rolls)) {
        throw std::runtime_error("Game is already over");
    }
    std::vector<int> temp = rolls;
    temp.push_back(pins);
    if (!isValidRollSequence(temp)) {
        throw std::runtime_error("Invalid roll sequence");
    }
    rolls.push_back(pins);
}

int Game::score() {
    if (!isCompleteGame(rolls)) {
        throw std::runtime_error(
            "Score cannot be taken until the end of the game");
    }
    int total = 0;
    int idx = 0;
    for (int frame = 1; frame <= 10; ++frame) {
        if (rolls[idx] == 10) {
            total += 10 + rolls[idx + 1] + rolls[idx + 2];
            idx += 1;
        } else if (rolls[idx] + rolls[idx + 1] == 10) {
            total += 10 + rolls[idx + 2];
            idx += 2;
        } else {
            total += rolls[idx] + rolls[idx + 1];
            idx += 2;
        }
    }
    return total;
}

bool Game::isValidRollSequence(const std::vector<int>& r) const {
    int idx = 0;
    for (int frame = 1; frame <= 10; ++frame) {
        if (idx >= (int)r.size()) break;
        int first = r[idx];
        if (first < 0 || first > 10) return false;
        if (frame < 10) {
            if (first == 10) {
                idx += 1;
            } else {
                if (idx + 1 >= (int)r.size()) break;
                if (r[idx + 1] < 0 || r[idx + 1] > 10) return false;
                if (first + r[idx + 1] > 10) return false;
                idx += 2;
            }
        } else {
            if (first == 10) {
                if (idx + 1 < (int)r.size()) {
                    int b1 = r[idx + 1];
                    if (b1 < 0 || b1 > 10) return false;
                    if (idx + 2 < (int)r.size()) {
                        int b2 = r[idx + 2];
                        if (b2 < 0 || b2 > 10) return false;
                        if (b1 != 10 && b1 + b2 > 10) return false;
                        idx += 3;
                    }
                }
            } else {
                if (idx + 1 >= (int)r.size()) break;
                if (first + r[idx + 1] == 10) {
                    if (idx + 2 < (int)r.size()) {
                        int b = r[idx + 2];
                        if (b < 0 || b > 10) return false;
                        idx += 3;
                    }
                } else {
                    if (first + r[idx + 1] > 10) return false;
                    idx += 2;
                }
            }
            break;
        }
    }
    return true;
}

bool Game::isCompleteGame(const std::vector<int>& r) const {
    int idx = 0;
    for (int frame = 1; frame <= 10; ++frame) {
        if (idx >= (int)r.size()) return false;
        int first = r[idx];
        if (frame < 10) {
            if (first == 10) {
                idx += 1;
            } else {
                if (idx + 1 >= (int)r.size()) return false;
                idx += 2;
            }
        } else {
            if (first == 10) {
                if (idx + 2 >= (int)r.size()) return false;
                idx += 3;
            } else {
                if (idx + 1 >= (int)r.size()) return false;
                if (first + r[idx + 1] == 10) {
                    if (idx + 2 >= (int)r.size()) return false;
                    idx += 3;
                } else {
                    idx += 2;
                }
            }
        }
    }
    return true;
}

}  // namespace bowling