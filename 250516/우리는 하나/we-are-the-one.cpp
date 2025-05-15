#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, k, u, d;
int grid[8][8];
int result = 0;
vector<pair<int, int>> city;
vector<int>selected;
int BFS() {
    queue<pair<int ,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (auto k : selected) {
        q.push({city[k].first, city[k].second});
        visited[city[k].first][city[k].second] = true;
    }
    int cnt = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool test = 0;
    if (selected.size() == 1 && selected[0] == 1) test = 1;
    while(!q.empty()) {
        auto curr = q.front();
        cnt++;
        q.pop();
        int x = curr.first;
        int y = curr.second;
        // if (test) cout << x << " and " << y << '\n';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            int h = abs(grid[nx][ny] - grid[x][y]);
            if (u <= h && h <= d) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}

void bt(int cnt, int idx) {
    if (cnt == k) {
        int cities = BFS();
        result = max(result, cities);
        return;
    }
    if (idx == city.size()) return;

    selected.push_back(idx);
    bt(cnt + 1, idx + 1);
    selected.pop_back();

    bt(cnt, idx + 1);
}
int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            city.push_back({i, j});
        }
    }
    bt(0,0);
    cout << result;
    return 0;
}
