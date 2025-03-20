#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in_range(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

int bomb(int row, int col, int arr[][50]) {
    
    int val = arr[row][col];

    for (int i = 0; i < val; i++) {
        for (int j = 0; j < 4; j++) {
            int nx = row + dx[j] * i;
            int ny = col + dy[j] * i;

            if (!in_range(nx,ny)) continue;
            arr[nx][ny] = 0;
        }
    }

    for (int c = 0; c < n; c++) {

        int end_of_index = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i][c] == 0) {

                end_of_index = i;
                break;
            }
        }
        if(end_of_index == -1) continue;

        for (int r = end_of_index - 1; r >= 0; r--) {
            if(arr[r][c] != 0) {
                arr[end_of_index][c] = arr[r][c];
                arr[r][c] = 0;
                end_of_index--;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int next_x = i + 1;
            int next_y = j + 1;
            if (in_range(next_x, j) && arr[next_x][j] == arr[i][j] && arr[i][j] != 0) {
                cnt++;
            }
            if (in_range(i, next_y) && arr[i][next_y] == arr[i][j] && arr[i][j] != 0) {
                cnt++;
            }
        }
    }
    
    return cnt;
}

int main() {
    cin >> n;
    int grid[50][50];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int temp[50][50];

            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) {
                    temp[a][b] = grid[a][b];
                }
            }

            result = max(result, bomb(i, j, temp));
        }
    }

    cout << result << '\n';
    return 0;
}
