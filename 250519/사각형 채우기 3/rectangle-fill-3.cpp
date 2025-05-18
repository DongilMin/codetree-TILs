#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    long long dp[1001] = {0};
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;
    for (int i = 4; i <= n; i++) {
        dp[i] += (dp[i - 1] * 2) % 1000000007;
        dp[i] += (dp[i - 2] * 3) % 1000000007;
        dp[i] += (dp[i - 3] * 2) % 1000000007;
    }
    cout << dp[n];
    return 0;
}
