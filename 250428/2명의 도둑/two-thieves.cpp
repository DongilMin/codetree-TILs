#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m, c;
int weight[11][11];
int sum = INT_MIN;

void func(int row, int col, int num, int curr, int val) {
    if(col > n || curr > c) return;

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
        for (int j = 1; j <= n; j++) {
            func(i, j, 1, 0, 0);
            int first_thief = sum;
            sum = INT_MIN;
            // if(first_thief == 64) cout << i << " and " << j << '\n';
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
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