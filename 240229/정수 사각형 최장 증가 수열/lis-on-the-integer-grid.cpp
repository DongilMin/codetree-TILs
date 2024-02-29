#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
long long arr[501][501];

bool sorting(pair<int,int>a, pair<int,int>b){
    return arr[a.first][a.second] < arr[b.first][b.second];
}

int main(){
    int n;
    vector<pair<int,int>>v;
    int ans = 0;
    int dp[501][501];
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            v.push_back(make_pair(i,j));
            dp[i][j] = 1;
        }
    }
    sort(v.begin(), v.end(), sorting);

    for(int i=0; i<v.size(); i++){
       int x = v[i].first;
       int y = v[i].second;
       for(int j=0; j<4; j++){
           int nx = x + dx[j];
           int ny = y + dy[j];
           if(nx < 1 || nx > n || ny<1 || ny>n) continue;
           if(arr[x][y] <= arr[nx][ny]) continue;
           dp[x][y] = max(dp[x][y], dp[nx][ny]+1);
           ans = max(ans, dp[x][y]);
       }
    }
    cout << ans;
}