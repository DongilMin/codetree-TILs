#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int dist[100][100];
int grid[100][100];

int BFS(int a, int b, int des_a, int des_b) {
    queue<pair<int ,int>> q;
    q.push({a, b});
    dist[a][b] = 0;

    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        if (x == des_a && y == des_b) return dist[x][y];
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dist[nx][ny] <= dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}
int main() {
    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    cout << BFS(--r1, --c1, --r2, --c2);
    return 0;
}
