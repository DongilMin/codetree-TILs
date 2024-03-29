#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[1001];
    int dp[1001];
    arr[0] = 0 ;
    for(int i=1; i<=n; i++){
        dp[i] = -1;
        cin >> arr[i];
    }

    dp[1] = 0;

    for(int i=2; i<=n; i++){

        for(int j=1; j<i; j++){
            if(dp[j] == -1) continue;
            if(arr[j] + j >= i) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}