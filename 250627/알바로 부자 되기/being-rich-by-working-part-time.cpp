#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    cin >> n;
    int dp[1000];
    vector<pair<int, int>> v(n);
    int pay[1000];
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second >> pay[i];
        dp[i] = pay[i];
    }

    sort(v.begin(), v.end(), compare);

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].first)
                dp[i] = max(dp[i], dp[j] + pay[i]);
        }
        result = max(result, dp[i]);
    }

    cout << result;
    return 0;
}
