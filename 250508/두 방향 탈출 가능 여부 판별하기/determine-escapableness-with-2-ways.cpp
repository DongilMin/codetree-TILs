#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool visited[101][101];
int dx[4] = {1, 0};
int dy[4] = {0, 1};
int grid[101][101];
queue<pair<int, int>> q;

int BFS() {
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        if (x == n && y == m) return 1;

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (!grid[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    visited[1][1] = true;
    q.push({1,1});
    cout << BFS();

    return 0;
}
