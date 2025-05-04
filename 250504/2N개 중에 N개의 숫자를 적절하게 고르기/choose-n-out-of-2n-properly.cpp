#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int num[20];
vector<int> A;
vector<int> B;
int result = INT_MAX;

int calc(){
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
        a += A[i];
        b += B[i];
    }
    return abs(a - b);
}

void func(int idx) {
    if (A.size() == n && B.size() == n) {
        int ans = calc();
        //cout << "heY ~ " << ans << '\n';
        result = min(result, ans);
        return;
    }
    if (idx == 2 * n) return;

    if (A.size() < n) {
        A.push_back(num[idx]);
        func(idx + 1);
        A.pop_back();
    }

    if (B.size() < n) {
        B.push_back(num[idx]);
        func(idx + 1);
        B.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
    }
    func(0);

    cout << result;
    return 0;
}
