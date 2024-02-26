#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>>q;
int arr[101][101];
bool visited[101][101];
int n, k;
int cnt = 0;
void dfs(){
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int cx = cur.first + dx[i];
            int cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > n) continue;
            if(arr[cx][cy] == 1) continue;
            if(visited[cx][cy]) continue;
            cnt++;
            visited[cx][cy] = 1;
            q.push(make_pair(cx,cy));
        }
    }
}
int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    int a,b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        q.push(make_pair(a,b));
        visited[a][b] = true;
        cnt++;
    }
    dfs();
    cout << cnt;
    
    return 0;
}