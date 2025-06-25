#include <iostream>
#include <climits>
#include <algoritm>

using namespace std;

int n;
int arr[1000];
int dp[1000];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == INT_MIN) continue;

            if (j + arr[j] >= i)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
        // cout << dp[i] << ' ';
    }

    cout << result;


    return 0;
}
