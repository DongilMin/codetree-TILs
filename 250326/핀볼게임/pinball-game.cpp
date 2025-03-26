#include <iostream>

using namespace std;

#define TOP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int n;
int grid[100][100];

bool in_range(int x,int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int rotate(int wall, int dir) {
    if (dir == DOWN){
        if(wall==1) return LEFT; // '/'
        return RIGHT; // '\'
    }
    else if (dir == LEFT){
        if(wall==1) return DOWN; // '/'
        return TOP; // '\'
    }
    else if (dir == TOP){
        if(wall==1) return RIGHT; // '/'
        return LEFT; // '\'
    }
    else if (dir == RIGHT){
        if(wall==1) return TOP; // '/'
        return DOWN; // '\'
    }
    else {
        return -1;
    }
}

int simulate(int x,int y, int dir) {
    int cnt = 1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cx = x;
    int cy = y;
    if (grid[cx][cy] != 0) dir = rotate(grid[cx][cy],dir);

    while (in_range(cx, cy)) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        if (grid[nx][ny] == 0) {
            cx = nx;
            cy = ny;
        }
        else {
            cx = nx;
            cy = ny;
            dir = rotate(grid[cx][cy], dir);
        }
        cnt++;
    }
    return cnt;
}

int func() {
    int result = 0;

    for (int i = 0; i < n; i ++) result = max(result, simulate(0, i, DOWN));
    for (int i = 0; i < n; i ++) result = max(result, simulate(i, n - 1, LEFT));
    for (int i = 0; i < n; i ++) result = max(result, simulate(n - 1, i, TOP));
    for (int i = 0; i < n; i ++) result = max(result, simulate(i, 0, RIGHT));

    return result;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];


    cout << func() << '\n';

    return 0;
}
