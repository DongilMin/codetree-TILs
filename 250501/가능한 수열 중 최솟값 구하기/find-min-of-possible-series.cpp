#include <iostream>
#include <vector>
using namespace std;

string s;
int n;

bool first = false;

bool check(int x1, int len) {
    // 두 번 길이 len만큼 읽으면 범위를 벗어나면 비교 불필요
    if (x1 + 2 * len > n) 
        return false;

    for (int i = 0; i < len; ++i) {
        if (v[x1 + i] != v[x1 + len + i]) 
            return false;
    }
    return true;
}

bool possible() {
    // i는 '반복 길이' (1부터 n/2까지)
    for (int len = 1; len <= v.size() / 2; ++len) {
        // x1은 시작 인덱스, 두 블록(len만큼)을 모두 읽을 수 있을 때까지만
        for (int x1 = 0; x1 + 2 * len <= n; ++x1) {
            if (check(x1, len)) 
                return false;    // 같은 패턴이 붙어 있으면 False
        }
    }
    return true;  // 전부 통과하면 True
}

void func(int curr) {
    if (curr > n && !first) {
        if (possible()) {
            first = true;
            for (int num : v) {
                cout << num;
            }
        }
        return;
    }
    for (int i = 4; i <= 6; i++) {
        v.push_back(i);
        func(curr + 1);
        v.pop_back();
    }
}
int main() {
    cin >> n;
    func(1);
    return 0; 
}
