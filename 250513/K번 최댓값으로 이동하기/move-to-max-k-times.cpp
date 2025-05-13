#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// move_list: tuples of (value, row, col)
vector<tuple<int,int,int>> move_list;

// BFS to collect all reachable cells with value < cur_val
void collectMoves(int sx, int sy, int cur_val) {
    queue<pair<int,int>> q;
    visited.assign(n, vector<bool>(n, false));
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            int cell = grid[nx][ny];
            if (cell >= cur_val) continue;
            visited[nx][ny] = true;
            move_list.emplace_back(cell, nx, ny);
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    grid.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    // convert to 0-based
    r--; c--;

    int cx = r, cy = c;
    int cur_val = grid[cx][cy];

    for (int step = 0; step < k; step++) {
        move_list.clear();
        collectMoves(cx, cy, cur_val);
        if (move_list.empty()) break;
        
        // sort by value DESC, then row ASC, then col ASC
        sort(move_list.begin(), move_list.end(), [](auto &a, auto &b) {
            if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b);
        });
        auto [val, nx, ny] = move_list[0];
        cx = nx;
        cy = ny;
        cur_val = val;
    }

    // output 1-based coordinates
    cout << cx+1 << " " << cy+1;
    return 0;
}
