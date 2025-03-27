#include <iostream>
#include <queue>
using namespace std;

int n, m, t;
int board[100][100];
int grid[100][100] = {0};
queue<pair<int, int>> q;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void func(int x, int y) {
    // cout << " curr is " << x << " and " << y << '\n';
    grid[x][y]--;
    int tmp = -55;
    int nx = -1;
    int ny = -1;
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (!in_range(cx, cy)) continue;
        //cout << cx << " and " << cy << " is " << board[cx][cy] << '\n';
        if (tmp < board[cx][cy]) {
            tmp = board[cx][cy];
            nx = cx;
            ny = cy;
        }
    }
    //cout << "next is " << nx << " and " << ny << "\n";
    grid[nx][ny]++;
}

void simulate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1) q.push({i,j});
        }
    }

    while(!q.empty()) {
        func(q.front().first, q.front().second);
        q.pop();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] >= 2) grid[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int r,c;
    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        r--;
        c--;
        grid[r][c] = 1;
    }

    for (int i = 0; i < t; i++) {
        // cout << i + 1 << " index stated\n";
        simulate();
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cout << grid[i][j] << ' ';
            if (grid[i][j] == 1) cnt++;
        }
        // cout << '\n';
    }
    cout << cnt;
    return 0;
}
