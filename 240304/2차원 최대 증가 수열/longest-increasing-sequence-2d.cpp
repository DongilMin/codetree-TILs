#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int arr[51][51];
    int dp[51][51];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    dp[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            for(int k=1; k<i; k++){
                for(int l=1; l<j; l++){
                    if(dp[k][l] == -1)continue;
                    if(arr[k][l] < arr[i][j]) dp[i][j] = max(dp[i][j], dp[k][l]+1);
                }
            }

            ans = max(ans, dp[i][j]);
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout << dp[i][j] << ' ';        
    //     }
    //     cout << '\n';
    // }

    cout << ans;
    return 0;
}