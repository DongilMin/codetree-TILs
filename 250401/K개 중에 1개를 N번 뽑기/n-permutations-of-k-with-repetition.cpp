#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> v;
void print() {
    for (auto a : v) {
        cout << a << ' ';
    }
    cout << '\n';
}
void func(int curr, int val) {
    if (curr > N) {
        print();
        return;
    }
    else {
        for (int i = 1; i <= K; i++) {
            v.push_back(i);
            func(curr + 1, i);
            v.pop_back();
        }
    }
}

int main() {
    cin >> K >> N;
    func(1, 1);
    return 0;
}
