#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int n;
bool visited[1001] = {0};
vector<pair<int, int>> v;
int result = 0;

bool is_visited(int x1, int x2) {
    for (int i = x1; i <= x2; i++) {
        if (visited[i]) return true;
    }
    return false;
}

void visit(int x1, int x2) {
    for (int i = x1; i <= x2; i++) visited[i] = true;
}

void cancel_visit(int x1, int x2) {
    for (int i = x1; i <= x2; i++) visited[i] = false;
}

void func(int curr, int num) {
    if (curr == n){
        result = max(result, num);
        return; 
    }
    int x1 = v[curr].first;
    int x2 = v[curr].second;

    func(curr + 1, num);

    if(!is_visited(x1, x2)) {
        visit(x1, x2);
        func(curr + 1, num + 1);
        cancel_visit(x1, x2);
    }
}

int main() {
    cin >> n;
    int x1, x2;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        v.push_back({x1, x2});
    }
    sort(v.begin(), v.end());
    func(0, 0);
    cout << result;
    return 0;
}
