#include <iostream>
#include <climits>
using namespace std;

int N, M;
int coin[100];
int dp[100];
int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    for (int i = 0; i <= M; i++) {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= coin[j]) {
                if (dp[i - coin[j]] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
        //cout << "i is " << i << " : " dp[i] << '\n';
    }
    if (dp[M] == INT_MAX) cout << -1;
    else cout << dp[M];
    return 0;
}
