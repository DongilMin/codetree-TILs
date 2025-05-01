#include <iostream>
#include <string>
using namespace std;

int n;
bool found = false;
string s;

// s에 길이 L = s.length()인 상태에서
// 어떤 길이 len짜리 블록이 연속으로 두 번 나오는지 검사
bool possible() {
    int L = s.length();
    for (int len = 1; len * 2 <= L; ++len) {
        for (int i = 0; i + 2 * len <= L; ++i) {
            bool equal = true;
            for (int j = 0; j < len; ++j) {
                if (s[i + j] != s[i + len + j]) {
                    equal = false;
                    break;
                }
            }
            if (equal) return false;
        }
    }
    return true;
}

void dfs(int cur) {
    if (found) return;            // 이미 답을 찾았으면 바로 종료
    if (cur == n) {
        // 길이 n의 좋은 수열 완성!
        cout << s << "\n";
        found = true;
        return;
    }
    // 4,5,6 을 하나씩 붙여보며
    for (char c = '4'; c <= '6'; ++c) {
        s.push_back(c);
        // 지금 붙인 상태가 아직 “좋은 수열”이라면
        if (possible()) {
            dfs(cur + 1);
        }
        if (found) return;        // 하위에서 답을 찾았으면 바로 돌아가기
        s.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dfs(0);
    return 0;
}
