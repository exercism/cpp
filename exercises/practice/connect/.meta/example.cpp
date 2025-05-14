#include <queue>
#include <string>
#include <vector>

#include "connect.h"

namespace connect {

static const int dx[6] = {-1, -1, 0, 0, 1, 1};
static const int dy[6] = {0, 1, -1, 1, 0, -1};

std::string winner(const std::vector<std::string>& board) {
    int n = board.size();
    if (n == 0) return "";

    std::vector<std::vector<char>> grid(n);
    for (int i = 0; i < n; ++i) {
        for (char c : board[i]) {
            if (c != ' ') {
                grid[i].push_back(c);
            }
        }
    }
    int m = grid[0].size();

    auto bfs = [&](char player) {
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        std::queue<std::pair<int, int>> q;

        if (player == 'X') {
            for (int i = 0; i < n; ++i) {
                if (grid[i][0] == 'X') {
                    q.push({i, 0});
                    vis[i][0] = true;
                }
            }
        } else {
            for (int j = 0; j < m; ++j) {
                if (grid[0][j] == 'O') {
                    q.push({0, j});
                    vis[0][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if ((player == 'X' && y == m - 1) ||
                (player == 'O' && x == n - 1)) {
                return true;
            }
            for (int d = 0; d < 6; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
                    grid[nx][ny] == player) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    };

    if (bfs('X')) return "X";
    if (bfs('O')) return "O";
    return "";
}

}  // namespace connect
