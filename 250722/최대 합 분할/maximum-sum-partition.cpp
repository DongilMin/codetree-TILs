#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> nums(N);
    int totalSum = 0;
    
    // 입력받고 전체 합 계산
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        totalSum += nums[i];
    }
    
    // dp[i][j][k] = 첫 i개의 수를 고려했을 때, 
    // 그룹 A의 합이 j, 그룹 B의 합이 k인 경우가 가능한지
    // 그룹 C의 합은 totalSum - j - k (하지만 C는 고려하지 않음)
    vector<vector<vector<bool>>> dp(N + 1, 
        vector<vector<bool>>(totalSum + 1, 
            vector<bool>(totalSum + 1, false)));
    
    // 초기 상태: 아무 수도 선택하지 않았을 때
    dp[0][0][0] = true;
    
    // 각 수에 대해
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= totalSum; j++) {
            for (int k = 0; k <= totalSum; k++) {
                if (dp[i][j][k]) {
                    // nums[i]를 그룹 A에 넣는 경우
                    if (j + nums[i] <= totalSum) {
                        dp[i + 1][j + nums[i]][k] = true;
                    }
                    
                    // nums[i]를 그룹 B에 넣는 경우
                    if (k + nums[i] <= totalSum) {
                        dp[i + 1][j][k + nums[i]] = true;
                    }
                    
                    // nums[i]를 그룹 C에 넣는 경우
                    dp[i + 1][j][k] = true;
                }
            }
        }
    }
    
    int result = 0;
    
    // 모든 N개의 수를 사용한 경우에서 A와 B의 합이 같고 최대인 경우 찾기
    for (int j = 0; j <= totalSum; j++) {
        // A와 B의 합이 같은 경우만 확인
        if (dp[N][j][j]) {
            result = max(result, j);
        }
    }
    
    cout << result << endl;
    
    return 0;
}