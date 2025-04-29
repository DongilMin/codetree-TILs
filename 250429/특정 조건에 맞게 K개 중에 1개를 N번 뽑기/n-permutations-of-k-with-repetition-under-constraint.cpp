#include <iostream>
#include <vector>
using namespace std;
int K, N;
vector<int> v;

bool check(int num) {
    if (v.size() < 2) return true;
    else {
        return !(num == v[v.size() - 1] && num == v[v.size() - 2]);
    }
}

void print() {
    for (int k : v) cout << k << ' ';
    cout << '\n';
}

void func() {
    if (v.size() >= N) {
        print();
        return;
    }
    
    for (int i = 1; i <= K; i++) {
        if (check(i)) {
            v.push_back(i);
            func();
            v.pop_back();
        }
    }
}
int main() {
    cin >> K >> N;
    func();

    return 0;
}
