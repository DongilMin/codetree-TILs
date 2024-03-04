#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr[1001][4];
    int pay[1001];
    int dp[1001];
    int n,s,e,p;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s >> e >> p;
        arr[i][1] = s; 
        arr[i][2] = e;
        arr[i][3] = p;
    }
    dp[1] = arr[1][3];
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[i][1] > arr[j][2]) dp[i] = max(dp[i], dp[j] + arr[j][3]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}