#include <iostream>

#define MAX_N 1000
#define MAX_M 3
#define MOD 10007

using namespace std;

// 변수 선언
int n;

// dp[i] : 합 i를 만들기 위한 서로 다른 가짓수
int dp[MAX_N + 1];
int numbers[MAX_M] = {1, 2, 5};

int main() {
    // 입력:
    cin >> n;
    
    // 초기 조건은
    // 아직 아무 수도 고르지 않았을 때이므로
    // 합 0을 만들기 위한 가짓수가 1이 되어
    // dp[0] = 1입니다.
    dp[0] = 1;

    // 점화식에 따라 값을 채워줍니다.
    for(int i = 1; i <= n; i++) {
        // 마지막으로 고른 숫자가 numbers[j]인 경우에 대해
        // 가짓수를 더해줍니다.
        for(int j = 0; j < MAX_M; j++) {
            if(i >= numbers[j])
                dp[i] = (dp[i] + dp[i - numbers[j]]) % MOD;
        }
    }

    // 합이 n이 되기 위한 가짓수를 출력합니다.
    cout << dp[n];
    return 0;
}
