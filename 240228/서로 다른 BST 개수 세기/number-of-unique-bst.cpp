#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dp[20] = {0};
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    cout << dp[n];
    return 0;
    // 3 = 0*2 + 1*1 + 2*0
}