#include <iostream>
#include <climits>
using namespace std;

int n;
int profit[100];
int dp[10000];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
        dp[i] = profit[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                dp[i] = max(dp[i], dp[i - j] + profit[j]);
            }
        }
    }

    cout << dp[n];
    return 0;
}
