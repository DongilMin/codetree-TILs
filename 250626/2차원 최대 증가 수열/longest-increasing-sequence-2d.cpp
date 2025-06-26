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
            dp[i][j] = 1;
        }
    }

    int result = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            for (int a = i + 1; a < n; a++) {
                for (int b = j + 1; b < m; b++) {
                    if (grid[i][j] < grid[a][b]) {
                        dp[a][b] = max(dp[a][b], dp[i][j] + 1);
                    }
                }
            }
            // cout << dp[i][j] << ' ';
            result = max(result, dp[i][j]);
        }
        // cout << '\n';
    }

    cout << result;

    return 0;
}
