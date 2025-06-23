#include <iostream>
#include <climits>
using namespace std;

int n;
int grid[500][500];
int dp[500][500] = {0};
int ddx[4] = {-1, 0, 1, 0};
int ddy[4] = {0, 1, 0, -1};

bool in_range(int i, int j){
    return !(i < 0 || j < 0 || i >= n || j >= n);
}

int dfs(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];

    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int dx = x + ddx[i];
        int dy = y + ddy[i];
        if (!in_range(dx, dy)) continue;
        if (grid[dx][dy] > grid[x][y])
            dp[x][y] = max(dp[x][y], dfs(dx, dy) + 1);
    }
    return dp[x][y];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, dfs(i, j));
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << result;
    return 0;
}
