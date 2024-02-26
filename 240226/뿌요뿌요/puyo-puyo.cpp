#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>>q;
int arr[101][101];
bool visited[101][101] = {0};
int n;
int sibal = 0;
int dfs(int i,int j){
    int cnt = 1;
    q.push(make_pair(i,j));
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int cx = cur.first + dx[i];
            int cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > n) continue;
            if(arr[cx][cy] != arr[cur.first][cur.second]) continue;
            if(visited[cx][cy]) continue;
            cnt++;
            visited[cx][cy] = true;
            q.push(make_pair(cx,cy));
        }
    }
    if(cnt >= 4) sibal++;
    return cnt;
}

int main() {
    int ans = 0;
    int cnt = 0;
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                int bomb = dfs(i,j);
                ans = max(ans,bomb);
            }
        }
    }
    cout << sibal << ' ' << ans;

    return 0;
}