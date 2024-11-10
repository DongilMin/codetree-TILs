#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // dp[j] = 최소 길이로 합이 j를 만드는 경우
    vector<int> dp(m + 1, numeric_limits<int>::max());
    dp[0] = 0; // 합이 0일 때는 공집합으로 길이 0

    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= A[i]; --j) { // 합이 j가 될 수 있도록 업데이트
            if (dp[j - A[i]] != numeric_limits<int>::max()) {
                dp[j] = min(dp[j], dp[j - A[i]] + 1);
            }
        }
    }

    // 결과 출력
    if (dp[m] == numeric_limits<int>::max()) {
        cout << -1 << endl; // 합 m을 만들 수 없을 때
    } else {
        cout << dp[m] << endl; // 합 m을 만들 수 있는 최소 길이
    }

    return 0;
}