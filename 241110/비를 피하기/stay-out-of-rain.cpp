#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// 방향 벡터 (상, 하, 좌, 우)
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// BFS를 사용하여 비를 피할 수 있는 공간까지의 최소 거리 계산
vector<vector<int>> bfs(const vector<vector<int>>& grid, const vector<pair<int, int>>& shelters) {
    int n = grid.size();
    vector<vector<int>> distance(n, vector<int>(n, -1)); // 거리 배열

    queue<tuple<int, int, int>> q; // (행, 열, 거리)

    // 비를 피할 수 있는 공간에서 BFS 시작
    for (const auto& shelter : shelters) {
        q.push({shelter.first, shelter.second, 0});
        distance[shelter.first][shelter.second] = 0; // 초기 거리 0
    }

    while (!q.empty()) {
        auto [r, c, dist] = q.front();
        q.pop();

        for (const auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            // 유효한 범위인지 확인 및 벽이 아닌지 확인
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] != 1) {
                // 아직 방문하지 않았거나 더 짧은 거리 발견
                if (distance[nr][nc] == -1) {
                    distance[nr][nc] = dist + 1; // 거리 증가
                    q.push({nr, nc, dist + 1});
                }
            }
        }
    }

    return distance;
}

int main() {
    int n, h, m;
    cin >> n >> h >> m;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<pair<int, int>> people; // 사람의 위치
    vector<pair<int, int>> shelters; // 비를 피할 수 있는 공간

    // 격자 입력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                people.push_back({i, j}); // 사람 위치 저장
            }
            else if (grid[i][j] == 3) {
                shelters.push_back({i, j}); // 비를 피할 수 있는 공간 저장
            }
        }
    }

    // 비를 피할 수 있는 공간에서 BFS 실행하여 거리 계산
    vector<vector<int>> shelterDistance = bfs(grid, shelters);

    // 결과 출력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                cout << shelterDistance[i][j] << " "; // 각 사람의 거리 출력
            } else {
                cout << "0 "; // 이동 가능한 공간은 0으로 출력
            }
        }
        cout << endl;
    }

    return 0;
}