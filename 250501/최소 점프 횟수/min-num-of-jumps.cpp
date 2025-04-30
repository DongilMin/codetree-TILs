#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n;
int num[11];
vector<int> v;
int result = INT_MAX;

void func(int curr, int cnt) {
    if (curr >= n) {
        result = min(result, cnt);
        return;
    }

    for (int i = 1; i <= num[curr]; i++) {
        func(curr + i, cnt + 1);
    }

}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    func(1, 0);
    if (result == INT_MAX) cout << -1;
    else cout << result;
    return 0;
}
