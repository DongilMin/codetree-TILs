#include <iostream>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;
    int dp[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!i && !j) continue;
            if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
            else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}
