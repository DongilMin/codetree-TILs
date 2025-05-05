#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
bool visited[9] = {0};

void print() {
    for (int a : v) cout << a << " ";
    cout << '\n';
}

void func(int curr) {
    if (curr == n) {
        print();
        return;
    }

    for (int i = n; i > 0; i--) {
        if (visited[i]) continue;
        v.push_back(i);
        visited[i] = true;
        func(curr + 1);
        visited[i] = false;
        v.pop_back();
    }
}

int main() {
    cin >> n;
    func(0);
    return 0;
}