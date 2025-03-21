#include <iostream>

using namespace std;

int n, m, k;
int grid[101][101];

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    
    int row = 0;
    for (int i = 1; i <= n; i++){

        bool is_empty = true;

        for (int j = k; j < k + m; j++) {
            if (grid[i][j] == 1) {
                is_empty = false;
                break;
            }
        }

        if(is_empty) row = i;
    } 
    if(row) {
        for (int j = k; j < k + m; j++) {
            grid[row][j] = 1;
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
