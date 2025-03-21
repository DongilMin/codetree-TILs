#include <iostream>
#include <queue>
using namespace std;

int n;
int r, c;
int a[100][100];
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

bool in_range(int x,int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    cin >> n >> r >> c;
    r--;
    c--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool is_completed = 0;
    int next_x;
    int next_y;
    queue<pair<int,int>> q;
    q.push({r,c});

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        int curr = a[cx][cy];
        q.pop(); 

        cout << curr << " ";

        int max_val = curr;
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if (in_range(nx, ny) && a[nx][ny] > max_val) {
                max_val = a[nx][ny];
                next_x = nx;
                next_y = ny;
                q.push({next_x, next_y});
                break;
            }
        }

    }


    return 0;
}
