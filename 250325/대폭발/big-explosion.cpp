#include <iostream>
#include <queue>
using namespace std;

int n, m, r, c;
int grid[101][101] = {0};
queue<pair<pair<int, int>, int>> q;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool in_range(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= n;
}

int main() {
    cin >> n >> m >> r >> c;

    vector<pair<int, int>> v;
    v.push_back({r,c});
    grid[r][c] = 1;
    int time = 0;
    for (int i = 1; i <= m; i++) {
        for(auto c : v) {
            int x = c.first;
            int y = c.second;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j] * i;
                int ny = y + dy[j] * i;
                if(!in_range(nx, ny) || grid[nx][ny] == 1) continue;
                grid[nx][ny] = 1;
                v.push_back({nx, ny});
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(grid[i][j] == 1) cnt++;
            // cout << grid[i][j] << ' ';
        }
        // cout << '\n';
    }
    cout << cnt << '\n';
    return 0;
}
