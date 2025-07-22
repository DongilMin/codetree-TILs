#include <iostream>

using namespace std;

int n;
int arr[100];
int dp[100] = {0};
int main() {
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += 0;
        // dp[arr[i]] = 1;
    }
    if (total % 2) {
        cout << "N";
        return 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = total; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) {
                dp[j] += dp[j - arr[i]];
            }
        }
    }

    if (dp[total / 2] > 1) cout << "YES";
    else cout << "No";
    return 0;
}
