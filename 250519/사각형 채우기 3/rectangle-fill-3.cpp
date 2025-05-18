#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    int dp[1001] = {0};
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    for (int i = 3; i <= n; i++) {
        dp[i] += (dp[i - 1] * 2) % 10007;
        dp[i] += (dp[i - 2] * 4) % 10007;
    }
    cout << dp[n];
    return 0;
}
