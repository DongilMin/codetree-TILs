#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    int dp[20] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++)
            sum += dp[j] * dp[i - j - 1];
        dp[i] = sum;
    }

    cout << dp[n];
    return 0;
}
