#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dp[i][j] = 0;  // 각 칸에서 시작할 수 있다고 가정
        }

    int result = 0;

    // 모든 칸을 출발점으로 생각
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            for (int a = i + 1; a < n; a++) {
                for (int b = j + 1; b < m; b++) {
                    if (grid[a][b] > grid[i][j]) {
                        dp[a][b] = max(dp[a][b], dp[i][j] + 1);
                        result = max(result, dp[a][b]);
                    }
                }
            }
            // (i,j) 자체에서 시작한 점프 수 고려
            result = max(result, dp[i][j]);
        }
    }

    cout << result + 1 << endl;
    return 0;
}
