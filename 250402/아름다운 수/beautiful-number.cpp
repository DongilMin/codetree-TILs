#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n;
int result = 0;

bool is_beautiful() {
    for (int i = 0; i < n;) {
        int cnt = 0;
        int val = v[i];
        int j = i;

        while (v[j] == val && j < n) {
            j++;
            cnt++;
        }
        if (cnt % val) return false;
        i = j;
    }
    return true;
}
void print() {
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}
void func(int curr, int val) {
    if (curr > n) {
        if (is_beautiful()) {
            //print();
            result++;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        v.push_back(i);
        func(curr + 1, i);
        v.pop_back();
    }
    

}
int main() {
    cin >> n;
    func(1,1);
    cout << result;
    return 0;
}
