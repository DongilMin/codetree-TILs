#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

string expression;
int result = INT_MIN;

void func(int idx, int len, vector<int>& v){
    if (idx == len) {
        int num = v[0];
        for (int i = 2; i < expression.length(); i += 2) {
            int val = v[i/2];
            char op = expression[i - 1];
            if (op == '-') num -= val;
            else if (op == '+') num += val;
            else num *= val;
        }
        result = max(result, num);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        v[idx] = i;
        func(idx + 1, len, v);
    }
}
int main() {
    cin >> expression;
    int leng = expression.length();
    int len = leng % 2 ? leng / 2 + 1 : leng / 2;
    vector<int> v(len, 1);
    v[0] = 4;
    func(1, len, v);
    cout << result;
    return 0;
}
