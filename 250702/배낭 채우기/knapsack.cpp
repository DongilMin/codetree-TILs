#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;

    int dp[10000];
    vector<pair<int ,int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());


    for (int i = 0; i <= M; i++) dp[i] = -1;

    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = M; j > 0; j--) {
            if (j >= v[i].first) {
                if (dp[j - v[i].first] == -1) continue;

                dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
            }
        }
    }
    int result = -1;
    for (int i = 1; i <= M; i++) result = max(result, dp[i]);
    cout << result;
    return 0;
}
