#include <iostream>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int main(){
    int n;
    int ans = 0;
    long long arr[501][501];
    int dp[501][501];
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            dp[i][j] = 1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int record = 0;
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx<1 || nx > n || ny<1 || ny>n) continue;
                if(arr[i][j] <= arr[nx][ny]) continue;
                record = max(record, dp[nx][ny]);
            }
            dp[i][j] += record;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}