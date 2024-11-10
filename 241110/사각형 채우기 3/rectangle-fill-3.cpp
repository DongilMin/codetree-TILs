#include <iostream>

using namespace std;
int main() {
    int dp[101][101] = {0};
    int arr[101][101] = {0};
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
    }
    cout << dp[n][n];
    return 0;
}