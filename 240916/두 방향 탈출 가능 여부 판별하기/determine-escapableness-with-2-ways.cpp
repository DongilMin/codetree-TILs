#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>>q;
int arr[102][102];
int n,m;
bool dfs(){
    while(!q.empty()){
        auto cur = q.front();
        if(cur.first == n && cur.second == m) return true;
        q.pop();
        for(int i=0; i<2; i++){
            int cx = cur.first + dx[i];
            int cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > m) continue;
            if(arr[cx][cy] == 0) continue;
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
            if(arr[1][1] == 0){
                cout << 0;
                return 0;
            }
        }
    }
    q.push(make_pair(1,1));
    cout << dfs() << '\n';
    return 0;
}