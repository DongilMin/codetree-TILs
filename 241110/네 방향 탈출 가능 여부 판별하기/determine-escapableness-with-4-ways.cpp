#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool visited[101][101] = {0};
queue<pair<int,int>>q;
int arr[101][101];
int n,m;
bool dfs(int i,int j){
    if(arr[i][j] == 0) return false;
    visited[i][j] = true;
    q.push(make_pair(i,j));
    while(!q.empty()){
        auto cur = q.front();
        if(cur.first == n && cur.second == m) return true;
        q.pop();
        for(int i=0; i<4; i++){
            int cx = cur.first + dx[i];
            int cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > m) continue;
            if(visited[cx][cy]) continue;
            if(arr[cx][cy] == 0) continue;
            visited[cx][cy] = true;
            q.push(make_pair(cx,cy));
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    cout << dfs(1,1) << '\n';
    return 0;
}