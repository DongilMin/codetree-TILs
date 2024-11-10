#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// 방향 벡터 (상, 하, 좌, 우)
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// BFS를 사용하여 최단 경로를 찾는 함수
int bfs(const vector<vector<int>>& grid, int n, int m) {
    queue<tuple<int, int, int>> q; // (행, 열, 거리)
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // 시작점 (0, 0)에서 BFS 시작
    q.push({0, 0, 0}); // 거리 0부터 시작
    visited[0][0] = true;

    while (!q.empty()) {
        auto [r, c, distance] = q.front();
        q.pop();

        // 도착점에 도달하면 거리 반환
        if (r == n - 1 && c == m - 1) {
            return distance; // 도착 지점까지의 거리 반환
        }

        // 인접한 칸 탐색
        for (auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            // 유효한 범위인지 확인 및 방문 여부 확인
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1) {
                visited[nr][nc] = true;
                q.push({nr, nc, distance + 1}); // 거리 증가
            }
        }
    }

    // 도착할 수 없는 경우
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    
    // 격자 입력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // BFS를 통해 최단 거리 계산
    int result = bfs(grid, n, m);
    cout << result << endl;

    return 0;
}