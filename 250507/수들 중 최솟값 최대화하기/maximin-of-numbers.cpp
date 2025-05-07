#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[11][11];
bool visited[11];
vector<int> v;
int result = 0;

int find_min() {
    int val = 99999;
    for (int a : v) {
        if (val > a) val = a;
    }
    return val;
}
void func(int row) {
    if (row > n) {
        result = max(result, find_min());
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(grid[row][i]);
        func(row + 1);
        v.pop_back();
        visited[i] = false;
    }
}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    func(1);
    cout << result;

    return 0;
}
