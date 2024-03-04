#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[1001];
    int dp[1001];
    int dp1[1001];
    int dp2[1001];

    for(int i=1; i<=n; i++){
        cin >> arr[i];
        dp1[i] = 1;
        dp2[i] = 1;
    }
    // dp1[1] = 1;
    // dp2[n] = 0;
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[j] < arr[i]) dp1[i] = max(dp1[i], dp1[j]+1);
        }
    }
    for(int i=n; i>0; i--){
        for(int j=n; j>i; j--){
            if(arr[j] < arr[i]) dp2[i] = max(dp2[i], dp2[j]+1);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        dp[i] = dp1[i] + dp2[i] -1;
        ans = max(ans, dp[i]);
       // cout << dp[i] << ' ';
    }
    cout << ans;
    return 0;
}