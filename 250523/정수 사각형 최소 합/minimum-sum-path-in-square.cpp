#include <iostream>
#include <algorithm>
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

    dp[0][n - 1] = grid[0][n - 1];
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == 0 && j == n - 1) continue;
            if (i == 0) dp[i][j] = dp[i][j + 1] + grid[i][j];
            else if (j == n - 1) dp[i][j] = dp[i - 1][j] + grid[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + grid[i][j];
        }
    }

    cout << dp[n - 1][0];
    return 0;
}
