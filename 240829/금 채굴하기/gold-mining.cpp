#include <iostream>
using namespace std;

int board[21][21];
int n,m;
int ans = 0;

int getCost(int k){
    return k*k+(k+1)*(k+1);
}

void getGold(int row, int col, int k){
    int gold = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(abs(row-i)+abs(col-j) <= k && board[i][j]){
                gold += board[i][j];
            }
        }
    }

    if(gold*m >= getCost(k) && gold > ans) ans = gold;
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<=2*(n-1); k++)
                getGold(i,j,k);
        }
    }
    cout << ans;
}