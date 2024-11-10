#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n, k, m;
vector<vector<int>> grid;
vector<pair<int, int>> stones; // 돌의 위치
vector<pair<int, int>> startPoints; // 시작점
vector<int> directions = {0, 1, 0, -1, 0}; // 상하좌우 이동

// BFS를 통해 도달 가능한 칸의 수 계산
int bfs(vector<vector<int>> &tempGrid) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    
    for (auto &start : startPoints) {
        q.push(start);
        visited[start.first][start.second] = true;
    }

    int reachableCount = 0;
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        reachableCount++;

        for (int i = 0; i < 4; ++i) {
            int nr = r + directions[i];
            int nc = c + directions[i + 1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && tempGrid[nr][nc] == 0) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    
    return reachableCount;
}

// 조합을 통해 돌을 제거하고 최대 도달 가능한 칸 수를 계산
int getMaxReachable() {
    int maxReachable = 0;
    vector<bool> removeMask(stones.size(), false);
    
    // m개의 돌을 제거하기 위한 조합 생성
    for (int i = 0; i < m; ++i) {
        removeMask[i] = true;
    }

    do {
        vector<vector<int>> tempGrid = grid;

        // 선택된 돌 제거
        for (int i = 0; i < stones.size(); ++i) {
            if (removeMask[i]) {
                int r = stones[i].first;
                int c = stones[i].second;
                tempGrid[r][c] = 0; // 돌 제거
            }
        }

        // BFS로 도달 가능한 칸 수 계산
        maxReachable = max(maxReachable, bfs(tempGrid));

    } while (prev_permutation(removeMask.begin(), removeMask.end()));
    
    return maxReachable;
}

int main() {
    cin >> n >> k >> m;
    grid.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                stones.push_back({i, j}); // 돌의 위치 저장
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        startPoints.push_back({r - 1, c - 1}); // 0-indexed로 변환
    }

    int result = getMaxReachable();
    cout << result << endl;

    return 0;
}