#include <iostream>
using namespace std;
int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int arr[501][501];
int dp[501][501];
int visited[501][501];
int ans = 0;
bool validate(int x, int y){

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<1 || nx > n || ny<1 || ny>n) continue;
        if(arr[x][y] < arr[nx][ny]) return true;
    }
    return false;
}
void nfind(int x,int y, int cnt){
    if(!validate(x,y)){
        ans = max(ans,cnt);
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<1 || nx >n || ny<1 || ny>n) continue;
        if(arr[x][y] >= arr[nx][ny]) continue;
        if(visited[nx][ny]) continue;
        visited[nx][ny] = true;
        nfind(nx,ny,cnt+1);
        visited[nx][ny] = false;
    }
    return;
}
int main() {
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            nfind(i,j,1);
        }
    }
    cout << ans;
    return 0;
}