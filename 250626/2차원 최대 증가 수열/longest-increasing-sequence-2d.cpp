#include <iostream>

using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    int result = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            for (int a = 0; a < i; a++) {
                for (int b = 0; b < j; b++) {
                    if(dp[a][b] == -1) continue;
                    if (grid[i][j] > grid[a][b]) {
                        dp[i][j] = max(dp[i][j], dp[a][b] + 1);
                    }
                }
            }
            // cout << dp[i][j] << ' ';
            result = max(result, dp[i][j]);
        }
        // cout << '\n';
    }

    cout << result + 1;

    return 0;
}
