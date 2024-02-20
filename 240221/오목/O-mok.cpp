#include <iostream>
using namespace std;
int main() {
    int board[20][20];
    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++)
            cin >> board[i][j];
    }
    bool same[4];
    for(int i=1; i<=19; i++){
        for(int j=1; j<=15; j++){
            if(board[i][j] == 0) continue;
            for(int i=0; i<4; i++) same[i] = 1;
            for(int k=1; k<=4; k++){
                if(board[i][j] != board[i+k][j] || i+k>19) same[0] = 0;
                if(board[i][j] != board[i][j+k]) same[1] = 0;
                if(board[i][j] != board[i+k][j+k] || i+k>19) same[2] = 0;
                if(board[i][j] != board[i+k][j-k] || i+k>19) same[3] = 0;
            }
            if(same[0]){
                cout << board[i][j] << '\n'<< i+2 << " " << j;
                return 0;
            }
            if(same[1]){
                cout << board[i][j] << '\n'<< i << " " << j+2;
                return 0;
            }
            if(same[2]){
                cout << board[i][j] << '\n'<< i+2 << " " << j+2;
                return 0;
            }
            if(same[3]){
                cout << board[i][j] << '\n'<< i+2 << " " << j-2;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}