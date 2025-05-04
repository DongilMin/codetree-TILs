#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n, m;
int x[20], y[20];
int result = INT_MAX;
vector<pair<int ,int>> v;

int calc(int x1, int y1, int x2, int y2) {
    return ( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
}

int check() {
    int min_val = INT_MIN;

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++)
            min_val = max(min_val, calc(v[i].first, v[i].second, v[j].first, v[j].second));
    }
    return min_val;
}

void func(int idx, int cnt) {
    if (cnt == m) {
        result = min(result, check());
        return;
    }
    if(idx == n) return;

    func(idx + 1, cnt);

    v.push_back({x[idx], y[idx]});
    func(idx + 1, cnt + 1);
    v.pop_back();
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    func(0, 0);
    cout << result;
    return 0;   
}
