#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[101][102] = {0};
    int dp[101][102] = {0};

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=n; i>0; i--){
        dp[1][i] = dp[1][i+1]+arr[1][i];
    }
    for(int i=2; i<=n; i++){
        for(int j=n; j>0; j--){
            if(j==n) dp[i][j] = dp[i-1][j] + arr[i][j];
            else dp[i][j] = min(dp[i-1][j],dp[i][j+1])+arr[i][j];
        }
    }
    cout << dp[3][1];
    return 0;
}