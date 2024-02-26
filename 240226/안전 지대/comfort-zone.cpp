#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>>q;
int arr[51][51];
bool visited[51][51] = {0};
int n,m;

void dfs(int i,int j,int k){
    q.push(make_pair(i,j));
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int cx = cur.first + dx[i];
            int cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > m) continue;
            if(arr[cx][cy] <= k) continue;
            if(visited[cx][cy]) continue;
            visited[cx][cy] = true;
            q.push(make_pair(cx,cy));
        }
    }
}

void reset(){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            visited[i][j] = 0;
}

int f(int k){
    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j] > k && !visited[i][j]){
                visited[i][j] = true;
                dfs(i,j,k);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int ans = 0;
    int k = 1;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> arr[i][j];

    for(int i=1; i<=100; i++){
        int tmp = f(i);
        if(ans < tmp){
            ans = tmp;
            k = i;
        }
        reset();
    }
    cout << k << ' ' << ans;
    return 0;
}