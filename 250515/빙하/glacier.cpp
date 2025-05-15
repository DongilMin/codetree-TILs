#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int grid[200][200];
bool visited[200][200];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}
bool all_removed() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) return false;
        }
    }
    return true;
}

bool in_range(int i, int j) {
    return !(i < 0 || j < 0 || i >= n || j >= m);
}


int bfs(int a, int b) {
    visited[a][b] = true;
    queue<pair<int, int>> q;
    queue<pair<int, int>> targets;
    q.push({a, b});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!in_range(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == 1) targets.push({nx, ny});
            else q.push({nx, ny}); 
            visited[nx][ny] = true;
        }
    }
    int cnt = 0;

    while(!targets.empty()) {
        cnt++;
        auto curr = targets.front();
        targets.pop();
        int x = curr.first;
        int y = curr.second;
        grid[x][y] = 0;
        // cout << " row : " << curr.first << " and col : " << curr.first << " was melted\n";
    }
    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int t = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                t++;
                int melted = bfs(i, j);
                if(melted == 0) {
                    cout << --t << ' ' << cnt;
                    return 0;        
                }
                cnt = melted;
                //print();
                reset();
            }
        }
    }
    // cout << t << ' ' << cnt;
    return 0;
}
