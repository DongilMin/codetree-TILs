#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, di;

void shift(int r,int c, int m1, int m2, int m3, int m4, int di) {
    if (di == 0){
        int temp = grid[r][c];
        int x = r;
        int y = c;

        for (int i = 0; i < m4; i++){
            grid[x][y] = grid[x - 1][y - 1];
            x--;
            y--;
        }
 
        for (int i = 0; i < m3; i++){
            grid[x][y] = grid[x - 1][y + 1];
            x--;
            y++;
        }
 
        for (int i = 0; i < m2; i++){
            grid[x][y] = grid[x + 1][y + 1];
            x++;
            y++;
        }

        for (int i = 0; i < m1; i++){
            grid[x][y] = grid[x + 1][y - 1];
            x++;
            y--;
        }
        grid[x-1][y+1] = temp;
    }
    else {
        int temp = grid[r - m1][c + m1];
        int x = r - m1;
        int y = c + m1;
        //cout << "x :" << x << " y : " << y <<" val :" << temp << '\n';
    for (int i = 0; i < m4; i++){
            grid[x][y] = grid[x - 1][y - 1];
            x--;
            y--;
        }
 
        for (int i = 0; i < m3; i++){
            grid[x][y] = grid[x + 1][y - 1];
            x++;
            y--;
        }
 
        for (int i = 0; i < m2; i++){
            grid[x][y] = grid[x + 1][y + 1];
            x++;
            y++;
        }

        for (int i = 0; i < m1; i++){
            grid[x][y] = grid[x - 1][y + 1];
            x--;
            y++;
        }
        grid[r - m1 + 1][c + m1 -1] = temp;
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
