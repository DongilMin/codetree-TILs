#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
int ans = 0;
int grid[100][100];
vector<pair<int, int>> stoneList;
vector<pair<int, int>> startArr;
queue<pair<int, int>> q;

bool inRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool canGo(int x, int y) {
    return inRange(x, y) && grid[x][y] == 0;
}

vector<vector<bool>> preprocessing() {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (auto &[x, y] : startArr) {
        q.push({x, y});
        visited[x][y] = true;
    }
    return visited;
}

int bfs() {
    vector<vector<bool>> visited = preprocessing();
    int cnt = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (canGo(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return cnt;
}

void backTracking(int cnt, int idx) {
    if (idx == m) {
        int value = bfs();
        ans = max(ans, value);
        return;
    }

    if (cnt == stoneList.size()) return;

    int x = stoneList[cnt].first;
    int y = stoneList[cnt].second;

    grid[x][y] = 0;
    backTracking(cnt + 1, idx + 1);
    grid[x][y] = 1;

    backTracking(cnt + 1, idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                stoneList.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        startArr.push_back({x - 1, y - 1});
    }

    backTracking(0, 0);
    cout << ans << '\n';

    return 0;
}
