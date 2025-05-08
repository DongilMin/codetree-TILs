#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int grid[101][101];
vector<int>peoples;


int BFS(int a, int b) {
    queue<pair<int, int>> q;
    visited[a][b] = true;
    q.push({a, b});
    int cnt = 0;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        cnt++;
        int x = curr.first;
        int y = curr.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (grid[x][y] != grid[nx][ny] ||visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return cnt;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    int removed_blocks = 0;
    int max_blocks = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                int blocks = BFS(i, j);
                max_blocks = max(max_blocks, blocks);
                if (blocks >= 4) { 
                    removed_blocks++;
                }
            }
        }
    }
    cout << removed_blocks << ' ' << max_blocks;
    return 0;
}
