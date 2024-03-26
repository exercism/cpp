#include <algorithm>
#include <string>
#include <vector>

#include "secret_handshake.h"

using namespace std;

vector<string> secret_handshake::commands(int value) {
    vector<string> answer;
    if (value & (1 << 0)) answer.push_back("wink");
    if (value & (1 << 1)) answer.push_back("double blink");
    if (value & (1 << 2)) answer.push_back("close your eyes");
    if (value & (1 << 3)) answer.push_back("jump");
    if (value & (1 << 4)) reverse(answer.begin(), answer.end());
    return answer;
}
