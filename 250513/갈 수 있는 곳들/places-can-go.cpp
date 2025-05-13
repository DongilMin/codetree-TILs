#include <iostream>
#include <queue>
using namespace std;

int n, k;
int a[100][100];
bool visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int aa, int b) {
    if (visited[aa][b]) return 0;
    int cnt = 1;
    queue<pair<int, int>>q;
    q.push({aa, b});
    visited[aa][b] = true;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (a[nx][ny] == 1 || visited[nx][ny]) continue;
            cnt++;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return cnt;
}
int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int r, c;
    int result = 0;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        result += bfs(r,c);
    }
    cout << result;
    return 0;
}