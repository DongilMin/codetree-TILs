#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void print() {
    for (int a : v) cout << a << ' ';
    cout << '\n';
}

void func(int curr, int cnt) {
    if (cnt == m) {
        print();
        return;
    }

    for (int i = curr + 1; i <= n; i++) {
        v.push_back(i);
        func(i, cnt + 1);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;
    func(0, 0);

    return 0;
}
