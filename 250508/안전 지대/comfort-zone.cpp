#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int grid[101][101];

void reset() {
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }
}

void BFS(int a, int b, int k) {
    queue<pair<int, int>> q;
    visited[a][b] = true;
    q.push({a, b});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (grid[nx][ny] <= k || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    pair<int, int> result = {1, 0};
    for (int k = 1; k <= 100; k++) {
        reset();
        int num_of_town = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!visited[i][j] && grid[i][j] > k) {
                    num_of_town++;
                    BFS(i, j, k);
                }
            }
        }
        if (result.second < num_of_town) result = {k, num_of_town};
    }
    cout << result.first << ' ' << result.second;
}
