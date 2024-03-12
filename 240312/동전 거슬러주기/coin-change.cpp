#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n,m;
    int dp[10001];
    int coin[101];
    cin >> n >> m;
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> coin[i];
    }
    for(int i=1; i<=m; i++){
        dp[i] = INT_MAX;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(i < coin[j]) continue;
            if(dp[i-coin[j]] == INT_MAX) continue;
            dp[i] = min(dp[i], dp[i-coin[j]] + 1);
        }
    }
    if(dp[m] == INT_MAX) dp[m] = -1;
    cout << dp[m];
    return 0;
}