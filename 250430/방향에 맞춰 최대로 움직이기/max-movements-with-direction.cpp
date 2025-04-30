#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int num[5][5];
int d[5][5];
int r, c;
int dir[9][2] = { {0, 0}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                {1, 0}, {1, -1}, {0, -1}, {-1, -1}}; 

int result = 0;
void func(int x, int y, int cnt) {

    bool find = 0;
    for (int i = 1; i <= n; i++) {
        int nx = x + dir[d[x][y]][0] * i;
        int ny = y + dir[d[x][y]][1] * i;
        if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (num[x][y] < num[nx][ny]) {
            find = 1;
            func(nx, ny, cnt + 1);
        }
    }

    if (!find) {
        result = max(result, cnt);
        return;
    }
}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> num[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> d[i][j];


    cin >> r >> c;
    func(r,c,0);
    cout << result;

    // Please write your code here.

    return 0;
}
