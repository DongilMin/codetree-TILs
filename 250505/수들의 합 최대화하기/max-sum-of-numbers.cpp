#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
bool visited_col[11] = {0};
bool visited_row[11] = {0};
int arr[11][11];

int result = 0;
int sum() {
    int tmp = 0;
    for (int a : v) tmp += a;
    return tmp;
}

void func(int row) {
    if (row == n + 1) {
        result = max(result, sum());
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited_row[row] || visited_col[i]) continue;
        visited_row[row] = true;
        visited_col[i] = true;
        v.push_back(arr[row][i]);
        func(row + 1);
        v.pop_back();
        visited_row[row] = false;
        visited_col[i] = false;
    }

}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    func(1);
    cout << result;
    return 0;
}