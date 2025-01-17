#include <iostream>

using namespace std;

int N;
int grid[20][20];
int board[3][3] = { {1,1,1}, {1,1,1}, {1,1,1}};

int check(int a, int b){
    int cnt = 0;
    for(int i = a; i < a+3; i++){
        for(int j = b; j< b+3; j++){
            if(a >= N || b >= N) continue;
            if(grid[i][j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = 0; j < N-2; j++) {
            int cnt = check(i,j);
            if(result < cnt) result = cnt;
        }
    }

    cout << result;
    return 0;
}
