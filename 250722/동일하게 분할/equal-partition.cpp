#include <iostream>

using namespace std;

int n;
int arr[100];
int dp[1000] = {0};
int main() {
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    if (total % 2) {
        cout << "No";
        return 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = total; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) {
                dp[j]++;
            }
        }
    }
    //for (int i = 1; i <= total/2; i++) cout << dp[i] << ' ';
    //cout << '\n';
    if (dp[total / 2] > 1) cout << "Yes";
    else cout << "No";
    return 0;
}
