#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int dist[100][100];
int grid[100][100];

void BFS(int a, int b) {
    queue<pair<int ,int>> q;
    q.push({a, b});
    dist[a][b] = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || !grid[nx][ny]) continue;
            if (dist[nx][ny] <= dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dist[i][j] = INT_MAX;
        }
    }
    BFS(0, 0);
    if(dist[n - 1][m - 1] == INF) cout << -1;
    else cout << dist[n - 1][m - 1];
    return 0;
}
