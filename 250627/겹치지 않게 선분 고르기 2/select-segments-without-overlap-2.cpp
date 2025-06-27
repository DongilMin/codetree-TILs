#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int n;
int x1[1000];
int x2[1000];
int dp[1000];
int main() {
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[n - 1];
    return 0;
}
