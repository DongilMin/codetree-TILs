#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int prev = grid[i][0];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(cnt >= m) {
                result++;
                break;
            }
            if(prev != grid[i][j]){
                prev = grid[i][j];
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int prev = grid[0][i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(cnt >= m) {
                result++;
                break;
            }
            if(prev != grid[j][i]){
                prev = grid[j][i];
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
    }

    cout << result;
}