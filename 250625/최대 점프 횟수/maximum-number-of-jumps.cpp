#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int arr[1000];
int dp[1000];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = -1;
    }

    dp[0] = 0;
    int result = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == -1) continue;

            if (j + arr[j] >= i)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
        // cout << dp[i] << ' ';
    }

    cout << result;


    return 0;
}
