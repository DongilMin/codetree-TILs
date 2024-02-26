#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>>q;
int arr[101][101];
int visited[101][101] = {0};
int n, u, d;
int ans = 0;

int dfs(){
    int cnt = q.size();
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int cx = cur.first + dx[i];
            int cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > n) continue;
            if(u > abs(arr[cx][cy] - arr[cur.first][cur.second]) ||
                abs(arr[cx][cy] - arr[cur.first][cur.second]) > d) continue;
            if(visited[cx][cy]) continue;
            visited[cx][cy] = 1;
            cnt++;
            q.push(make_pair(cx,cy));
        }
    }
    return cnt;
}

void reset(){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(visited[i][j] == 1) visited[i][j] = 0;
}
void func(int a,int b, int k){
    if(k==0){
        ans = max(ans, dfs());
        reset();
        return;
    }
    for(int i=a; i<=n; i++){
        for(int j=b; j<=n; j++){
            if(0 < visited[i][j]) continue;
            visited[i][j] = 2;
            q.push(make_pair(i,j));
            //cout <<  i << " and " << j << " was pushed\n";
            for(int l=0; l<k; l++){
                func(i,j,k-1);
            }
            visited[i][j] = 0;
        }
    }
}
int main() {
    int k;
    cin >> n >> k >> u >> d;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    func(1,1,k);
    cout << ans;
    return 0;
}