#include <iostream>
#include <climits>
using namespace std;

int n, m;
int A[100];
int dp[100000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= m; i++) {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int j = 0; j < n; j++) {
        for (int i = m; i >= A[j]; i--) {
            if (dp[i - A[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - A[j]] + 1);
            }
        }
    }
    if (dp[m] == INT_MAX) cout << -1;
    else cout << dp[m];
    return 0;
}
