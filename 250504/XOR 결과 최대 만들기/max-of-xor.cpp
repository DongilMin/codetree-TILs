#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, m;
int A[20];
vector<int> v;
int ans = -1;
void print() {
    for(int a : v) cout << a << ' ';
    cout<<'\n';
}
int calc() {
    int result = 0;
    for (int i = 0; i < v.size(); i++) {
        result = result ^ v[i];
    }
    return result;
}

void func(int idx, int cnt) {
    if(cnt == m) {
        ans = max(ans, calc());
        return;
    }
    if(idx + 1 < n) {
        v.push_back(A[idx]);
        func(idx + 1, cnt + 1);
        v.pop_back();

        func(idx + 1, cnt);
    }

}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    func(0, 0);
    cout << ans;
    return 0;
}