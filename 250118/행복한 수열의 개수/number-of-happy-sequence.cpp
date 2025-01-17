#include <iostream>
using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    // 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;

    // 행 탐색
    for (int i = 0; i < n; i++) {
        int prev = grid[i][0];
        int cnt = 0;
        bool isHappy = false; // 행복한 수열 여부 확인
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != prev) {
                prev = grid[i][j];
                cnt = 1;
            } else {
                cnt++;
            }
            if(cnt>=m){
                isHappy = true;
                break;
            }
        }
        if (isHappy) result++;
    }

    // 열 탐색
    for (int i = 0; i < n; i++) {
        int prev = grid[0][i];
        int cnt = 0;
        bool isHappy = false; // 행복한 수열 여부 확인
        for (int j = 0; j < n; j++) {
            if (grid[j][i] != prev) {
                prev = grid[j][i];
                cnt = 1;
            } else {
                cnt++;
            }
            if(cnt>=m){
                isHappy = true;
                break;
            }
        }
        if (isHappy) result++;
    }

    cout << result << endl;
    return 0;
}
