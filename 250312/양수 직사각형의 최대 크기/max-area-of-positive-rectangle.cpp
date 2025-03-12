#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // 가로,세로 검사 길이 할당
            for (int a = i; a < n; a++) {
                for (int b = j; b < m; b++) {
                    int cnt = 0;
                    bool fail = 0;
                    for (int row = 0; row <= a; row++) {
                        for (int col = 0; col <= b; col++) {
                            if(grid[i+row][j+col] <= 0){
                                fail = true;
                                break;
                            }
                            cnt++;
                        }
                        if(fail) break;
                    }
                    if (!fail) result = max(result, cnt);
                }
            }
        }
    }
    if (!result) cout << -1 << '\n';
    else cout << result;
    return 0;
}
