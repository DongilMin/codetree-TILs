#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[22][21];
int dx[4] = {-1,-1,1,1};
int dy[4] = {1,-1,-1,1};

bool range(int x, int y){
    return 0 <= x && 0 <= y && x < n && y < n;
}

int cal(int x, int y, int row, int col){
    int curX = x;
    int curY = y;
    int sum = arr[curX][curY];
    for(int i=1; i<=row; i++){
        curX += dx[0];
        curY += dy[0];
        if(range(curX, curY)) sum += arr[curX][curY];
        else return -1;
    }
    for(int i=1; i<=col; i++){
        curX += dx[1];
        curY += dy[1];
        if(range(curX, curY)) sum += arr[curX][curY];
        else return -1;
    }
    for(int i=1; i<=row; i++){
        curX += dx[2];
        curY += dy[2];
        if(range(curX, curY)) sum += arr[curX][curY];
        else return -1;
    }
    for(int i=1; i<=col; i++){
        curX += dx[3];
        curY += dy[3];
        if(curX == x && curY == y) return sum;
        if(range(curX, curY)) sum += arr[curX][curY];
        else return -1;
    }
    return sum;

}
int solve(int row, int col){
    int val = -1;
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            val = max(val, cal(row,col,i,j));
        }
    }
    return val;
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, solve(i,j));
        }
    }
    cout << ans;
    return 0;
}