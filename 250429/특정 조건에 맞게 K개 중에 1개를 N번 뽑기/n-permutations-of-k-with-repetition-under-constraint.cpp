#include <iostream>
#include <vector>
using namespace std;
int K, N;
vector<int> v;

bool check(int num) {
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == num) cnt++;
    }

    return cnt < 2;
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
