#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n, h, m;
int dist[100][100] = {0};
int grid[100][100];
vector<pair<int ,int>> v;

void BFS(int a, int b) {
    int board[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = INT_MAX;

    queue<pair<int ,int>> q;
    q.push({a, b});
    board[a][b] = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        // cout << x << " and " << y << '\n';
        if (grid[x][y] == 3) {
            dist[a][b] = board[x][y];
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n  || grid[nx][ny] == 1) continue;
            if (board[nx][ny] <= board[x][y] + 1) continue;
            // cout << "board " << nx << " and " << ny << " is a " << board[x][y] + 1 << '\n';
            board[nx][ny] = board[x][y] + 1;
            q.push({nx, ny});
        }
    }

    dist[a][b] = -1;
    return;
}
int main() {
    cin >> n >> h >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                v.push_back({i, j});
            }
        }
    }
    
    for(auto k : v) BFS(k.first, k.second);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
