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


void BFS(int a, int b) {
    queue<pair<int, int>> q;
    visited[a][b] = true;
    q.push({a, b});
    int cnt = 0;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (!grid[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    peoples.push_back(cnt);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    int num_of_town = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] && !visited[i][j]) {
                num_of_town++;
                BFS(i, j);
            }
        }
    }
    cout << num_of_town << '\n';
    sort(peoples.begin(), peoples.end());
    for (int num : peoples) cout << num << '\n';
    return 0;
}
