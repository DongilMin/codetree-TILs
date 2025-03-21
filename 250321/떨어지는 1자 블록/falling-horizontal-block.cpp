#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = n; i >= 1; i--){입력

        bool is_empty = true;

        for (int j = k; j <= k + m; j++) {
            if (grid[i][j] == 1) {
                is_empty = false;
                break;
            }
        }

        if(is_empty) {
            for (int j = k; j <= k + m; j++) {
                grid[i][j] = 1;
            }
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
