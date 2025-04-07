#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool visited[1001] = {0};
vector<pair<int, int>> v;
vector<pair<int, int>> u;
int result = 0;

bool is_visited(int x1, int x2) {

    return false;
}

void visit(int x1, int x2) {
    visited[x1] = visited[x2] = true;
}

void cancel_visit(int x1, int x2) {
    visited[x1] = visited[x2] = false;
}

void func(int curr, int num, int prev_end) {
    if (curr >= n){
        result = max(result, num);
        return; 
    }
    for (int i = curr; i < v.size(); i++) {
        int x1 = v[i].first;
        int x2 = v[i].second;
        if (prev_end < x1) {
            func(curr + 1, num + 1, x2);
        }
        else {
            func(curr + 1, num, prev_end);
        }
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
    func(0,0,0);
    cout << result;
    return 0;
}
