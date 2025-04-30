#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int nums[12];
int result = 0;

void func(int curr, vector<int>& v) {
    if (curr > n) {
        int cnt = 0;
        for (int val : v) {
            if (val >= m) cnt++;
        }
        result = max(result, cnt);
        return;
    }

    for (int i = 1; i <= k; i++) {
        v[i] += nums[curr];
        func(curr + 1, v);
        v[i] -= nums[curr];
    }
}

int main() {
    cin >> n >> m >> k;
    vector<int> v(k + 1, 1);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    func(1, v);
    cout << result;

    return 0;
}
