#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,c;
    cin >> r >> c;

    char board[16][16];
    int cnt = 0;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> board[i][j];
        }
    }
    char cur = board[1][1];
    for(int i=2; i<r; i++){
        for(int j=2; j<c; j++){
            if(cur != board[i][j]){
                for(int k=i+1; k<r; k++){
                    for(int l=j+1; l<c; l++){
                        if(cur == board[k][l]) cnt++;
                    }
                }
            }
        }
    }
    cout << cnt;
}