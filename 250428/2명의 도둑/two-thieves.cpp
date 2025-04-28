#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m, c;
int weight[11][11];
int sum = INT_MIN;

void func(int row, int col, int num, int curr, int val) {
    if (num > m) {
        sum = max(sum, val);
        return;
    }

    if (curr + weight[row][col] <= c) {
        func(row, col + 1, num + 1, curr + weight[row][col], val + weight[row][col] * weight[row][col]);
    }
    func(row, col + 1, num + 1, curr, val);
}

int main() {
    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> weight[i][j];
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - m + 1; j++) {
            sum = INT_MIN;
            func(i, j, 1, 0, 0);
            int first_thief = sum;
            // if(first_thief == 64) cout << i << " and " << j << '\n';
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n - m + 1; l++) {
                    if (i == k && !(l + m - 1 < j || l > j + m - 1)) continue;
                    sum = INT_MIN;
                    func(k, l, 1, 0, 0);
                    int second_thief = sum;
                    // cout << "sum is " << sum << '\n';
                    result = max(result, first_thief + second_thief);
                }
            }
        }
    }
    cout << result;
    return 0;
}