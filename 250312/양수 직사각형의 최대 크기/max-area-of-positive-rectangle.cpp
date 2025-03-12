#include <iostream>
#include <algorithm>

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
            for (int a = i; a < n; a++) {
                for (int b = j; b < m; b++) {
                    bool fail = false;

                    for (int row = i; row <= a; row++) {
                        for (int col = j; col <= b; col++) {
                            if (grid[row][col] <= 0) {
                                fail = true;
                                break;
                            }
                        }
                        if (fail) break;
                    }

                    if (!fail) {
                        int area = (a - i + 1) * (b - j + 1);
                        result = max(result, area);
                    }
                }
            }
        }
    }

    cout << result << '\n';
    return 0;
}
