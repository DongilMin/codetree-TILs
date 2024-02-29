#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[101][101];
    int dp[101][101];
    int mindp[101][101];
    int maxdp[101][101];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    mindp[1][1] = maxdp[1][1] = arr[1][1];
    for(int i=2; i<=n; i++){
        mindp[1][i] = min(mindp[1][i-1], arr[1][i]);
        maxdp[1][i] = max(maxdp[1][i-1], arr[1][i]);
    }
    for(int i=2; i<=n; i++){
        mindp[i][1] = min(mindp[i-1][1], arr[i][1]);
        maxdp[i][1] = max(maxdp[i-1][1], arr[i][1]);
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            mindp[i][j] = min(max(mindp[i-1][j], mindp[i][j-1]), arr[i][j]);
            maxdp[i][j] = max(min(maxdp[i-1][j], maxdp[i][j-1]), arr[i][j]);
        }
    }
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = abs(maxdp[i][j] - mindp[i][j]);
        }
    }
    cout << mindp[n][n];
    return 0;
}