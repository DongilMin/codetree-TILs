#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, k;
int grid[100][100];

int r1, c1, r2, c2;
vector<pair<int ,int>> rocks;
int result = INT_MAX;

int bfs() {
    int dist[100][100];
    for (int i = 0; i < n; i++) 
        for(int j = 0; j < n; j ++)
            dist[i][j] = INT_MAX;

    queue<pair<int, int>> q;
    q.push({r1, c1});
    dist[r1][c1] = 0;

    while (!q.empty()){
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        auto curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();
        if (x == r2 && y == c2) return dist[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] == 1) continue;
            if (dist[nx][ny] <= dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return INT_MAX;
}
void back_tracking(int cnt, int idx) {
    if (cnt == k) {
        int time = bfs();
        result = min(result, time);
        return;
    }
    if (idx == rocks.size()) return;

    int x = rocks[idx].first;
    int y = rocks[idx].second;

    grid[x][y] = 0;
    back_tracking(cnt + 1, idx + 1);
    grid[x][y] = 1;

    back_tracking(cnt, idx + 1);

}
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) rocks.push_back({i, j});
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;
    back_tracking(0 ,0);
    if (result == INT_MAX) cout << -1;
    else cout << result;

    return 0;
}
