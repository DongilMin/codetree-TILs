#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

bool in_range (int x,int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void func(int num) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == num) {
                int max_val = 0;
                int nx = 0;
                int ny = 0;
                for (int k = 0; k < 8; k++) {
                    int cx = i + dx[k];
                    int cy = j + dy[k];
                    if (!in_range(cx,cy)) continue;
                    if (grid[cx][cy] > max_val) {
                        max_val = grid[cx][cy];
                        nx = cx;
                        ny = cy;
                    }
                }
                int tmp = grid[i][j];
                grid[i][j] = max_val;
                grid[nx][ny] = tmp;
                return;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int j = 0; j < m; j++)
        for (int i = 1; i <= n*n; i++) func(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
