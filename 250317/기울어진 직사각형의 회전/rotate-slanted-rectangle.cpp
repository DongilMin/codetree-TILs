#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, di;
int dir[4][2] = { {-1, 1}, {-1, -1}, {1, -1}, {1, 1} };

bool in_range(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void shift(int r,int c, int m1, int m2, int m3, int m4, int di) {
    if (di == 0){
        int len[4] = {m1, m2, m3, m4};
        int temp = grid[r][c];
        int curr_r = r;
        int curr_c = c;
        for (int i = 3; i >= 0; i--) {
            for(int j = 0; j < len[i]; j++){
                grid[curr_r][curr_c] = grid[curr_r - dir[i][0]][curr_c - dir[i][1]];
                curr_r -= dir[i][0];
                curr_c -= dir[i][1];
            }
        }
        grid[r+dir[0][0]][c+dir[0][1]] = temp;
    }
    else {
        int len[4] = {m1, m2, m3, m4};
        int temp = grid[r][c];
        int curr_r = r;
        int curr_c = c;
        for (int i = 0; i < 3; i++) {
            for(int j = 0; j < len[i]; j++){
                grid[curr_r][curr_c] = grid[curr_r + dir[i][0]][curr_c + dir[i][1]];
                curr_r += dir[i][0];
                curr_c += dir[i][1];
            }
        }
        grid[r - dir[3][0]][c - dir[3][1]] = temp;
    }
}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> di;
    shift(r,c,m1,m2,m3,m4,di);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
