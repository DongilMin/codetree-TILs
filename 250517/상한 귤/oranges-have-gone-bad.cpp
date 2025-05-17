#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int n, k;
int grid[100][100];
int dist[100][100];
vector<pair<int, int>> mandarins;
queue<pair<int, int>> q;

void bfs() {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (!grid[nx][ny]) continue;
            if (dist[nx][ny] != -1 && dist[x][y] + 1 >= dist[nx][ny]) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1 && grid[i][j] == 1) cout << "-2" << " ";
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
