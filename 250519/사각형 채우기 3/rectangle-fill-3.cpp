#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    long long dp[1001] = {0};
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3) % 1000000007;
        for(int j = i - 3; j >= 0; j--) {
            dp[i] = (dp[i] + (dp[j] * 2) % 1000000007) % 1000000007;
        }
    }
    cout << dp[n];
    return 0;
}
// 별 1 -> 2
// 별 2 -> 2