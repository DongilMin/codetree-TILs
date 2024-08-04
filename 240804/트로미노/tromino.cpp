#include <iostream>
using namespace std;
int n,m;
int board[201][201];
int dx[4] = {-1,1,1,-1};
int dy[4] = {1,1,-1,-1};

int block(int i,int j){
    int sum = board[i][j];
    int add = 0;
    for(int k=0; k<4; k++){
        if(i+dx[k]>n || j+dy[k]>m || i+dx[k]<=0 || j+dy[k]<=0) continue;
        int val = board[i+dx[k]][j] + board[i][j+dy[k]];
        if(add < val) add = val;
    }
    if(i!=1 && i!= n){
        int row_sum = board[i-1][j] + board[i+1][j];
        if(row_sum > add) add = row_sum;
    }
    if(j!=1 && j!= n){
        int col_sum = board[i][j-1] + board[i][j+1];
        if(col_sum > add) add = col_sum;
    }
    return sum+add;
}

int main() {
    int result = 0;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(result < block(i,j)) result = block(i,j);
        }
    }
    cout << result;
}