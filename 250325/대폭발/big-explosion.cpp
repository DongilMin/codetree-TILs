#include <iostream>
#include <cmath>
#include <queue>
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

    q.push({{r,c},1});

    int time = 0;

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int t = curr.second;
        int cx = curr.first.first;
        int cy = curr.first.second;
        grid[cx][cy] = 1;

        for (int i = 0; i < 5; i++) {
            int nx = cx + dx[i] * pow(2, t - 1);
            int ny = cy + dy[i] * pow(2, t - 1);
            if(!in_range(nx, ny) || t == m + 1) continue;
            q.push({{nx,ny}, t + 1});
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
             if(grid[i][j] == 1) cnt++;
            //cout << grid[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << cnt << '\n';
    return 0;
}
