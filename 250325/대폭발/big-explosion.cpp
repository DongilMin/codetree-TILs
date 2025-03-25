#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m, r, c;
int grid[101][101] = {0};
queue<pair<pair<int, int>, int>> q;
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};

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
            for (int j = 0; j < 5; j++) {
                int nx = x + dx[j] * pow(2,i-1);
                int ny = y + dy[j] * pow(2,i-1);
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
        }
    }
    cout << cnt << '\n';
    return 0;
}
