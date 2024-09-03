#include <iostream>
using namespace std;
int board[3][201];
int n,t;
int main() {
    cin >> n >> t;

    for(int i=1; i<=2; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<t; i++){

        int first_row_start = board[1][1];
        int second_row_start = board[2][n];
        int first_row_end = board[1][n];
        int second_row_end = board[2][n];

        for(int j=n; j>1; j--){
            board[1][j] = board[1][j-1];
        }
        board[1][1] = second_row_end;
        for(int j=n; j>1; j--){
            board[2][j] = board[2][j-1];
        }
        board[2][1] = first_row_end;
    }
    
    for(int i=1; i<=2; i++){
        for(int j=1; j<=n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}