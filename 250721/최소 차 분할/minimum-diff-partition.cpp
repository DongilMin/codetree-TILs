#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
    
    // DP 배열: dp[i] = i라는 합을 만들 수 있는지 여부
    vector<bool> dp(totalSum + 1, false);
    dp[0] = true;
    
    // 각 숫자에 대해
    for (int i = 0; i < N; i++) {
        // 뒤에서부터 순회 (중복 사용 방지)
        for (int j = totalSum; j >= nums[i]; j--) {
            if (dp[j - nums[i]]) {
                dp[j] = true;
            }
        }
    }
    
    // 전체 합의 절반에 가장 가까운 부분집합 합 찾기
    int minDiff = totalSum;
    int target = totalSum / 2;
    
    // target에서 가까운 곳부터 찾기
    for (int i = target; i >= 0; i--) {
        if (dp[i]) {
            // 한 그룹의 합이 i이면, 다른 그룹의 합은 totalSum - i
            // 두 그룹의 차이는 |i - (totalSum - i)| = |2*i - totalSum|
            minDiff = abs(2 * i - totalSum);
            break;
        }
    }
    
    cout << minDiff << endl;
    
    return 0;
}