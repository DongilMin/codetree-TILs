#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    
    vector<pair<int,int>> v(n);
    int t = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;  // first: 경험치, second: 시간
        t += v[i].second;  // 시간을 더해야 함
    }
    
    // dp[i][j]: i번째 퀘스트까지 고려했을 때 (0-indexed),
    // 시간 j를 사용했을 때 얻을 수 있는 최대 경험치
    vector<vector<int>> dp(n, vector<int>(t + 1, INT_MIN));
    
    // 초기값: 첫 번째 퀘스트
    dp[0][0] = 0;  // 첫 번째 퀘스트를 하지 않음
    if (v[0].second <= t) {
        dp[0][v[0].second] = v[0].first;  // 첫 번째 퀘스트를 함
    }
    
    // DP 진행
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= t; j++) {
            // i번째 퀘스트를 하지 않는 경우
            dp[i][j] = dp[i-1][j];
            
            // i번째 퀘스트를 하는 경우
            if (j - v[i].second >= 0 && dp[i-1][j - v[i].second] != INT_MIN) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - v[i].second] + v[i].first);
            }
        }
    }
    
    // 답 찾기: m 이상의 경험치를 얻는 최소 시간
    int ans = INT_MAX;
    for (int j = 0; j <= t; j++) {
        if (dp[n-1][j] >= m) {
            ans = min(ans, j);
        }
    }
    
    if (ans == INT_MAX) {
        ans = -1;
    }
    
    cout << ans;
    return 0;
}