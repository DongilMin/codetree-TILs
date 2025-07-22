#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    int totalSum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    
    // dp[i][j] = i개의 수를 고려했을 때
    // (그룹 A의 합 - 그룹 B의 합) = j일 때
    // 가능한 그룹 A의 최대 합
    const int OFFSET = 50000;
    vector<vector<int>> dp(n + 1, vector<int>(2 * OFFSET + 1, INT_MIN));
    
    // 초기값: 아무 수도 선택하지 않았을 때
    dp[0][OFFSET] = 0;  // 차이 0, A의 합 0
    
    // DP 진행
    for (int i = 0; i < n; i++) {
        for (int j = -totalSum; j <= totalSum; j++) {
            if (dp[i][j + OFFSET] == INT_MIN) continue;
            
            int curr = dp[i][j + OFFSET];
            
            // 1. arr[i]를 그룹 A에 추가
            // 차이가 j + arr[i]가 되고, A의 합이 curr + arr[i]가 됨
            if (j + arr[i] + OFFSET >= 0 && j + arr[i] + OFFSET <= 2 * OFFSET) {
                dp[i + 1][j + arr[i] + OFFSET] = max(dp[i + 1][j + arr[i] + OFFSET], 
                                                      curr + arr[i]);
            }
            
            // 2. arr[i]를 그룹 B에 추가
            // 차이가 j - arr[i]가 되고, A의 합은 그대로
            if (j - arr[i] + OFFSET >= 0 && j - arr[i] + OFFSET <= 2 * OFFSET) {
                dp[i + 1][j - arr[i] + OFFSET] = max(dp[i + 1][j - arr[i] + OFFSET], 
                                                      curr);
            }
            
            // 3. arr[i]를 그룹 C에 추가
            // 차이와 A의 합 모두 그대로
            dp[i + 1][j + OFFSET] = max(dp[i + 1][j + OFFSET], curr);
        }
    }
    
    // A - B = 0 (A = B)일 때 A의 최대 합
    cout << dp[n][OFFSET] << endl;
    
    return 0;
}