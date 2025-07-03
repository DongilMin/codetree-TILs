#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int dp[10001];

int main() {
    cin >> N >> M;
    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 1; i <= M; i++) dp[i] = -1;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= v[j].first) {
                if (dp[i - v[j].first] == -1) continue;

                dp[i] = max(dp[i], dp[i - v[j].first] + v[j].second);
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= M; i++) result = max(result, dp[i]);
    cout << result;
    return 0;
}
