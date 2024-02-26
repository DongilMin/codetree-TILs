#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>>q;
vector<pair<int,int>>v;
int arr[101][101];
int visited[101][101] = {0};
int n, k,u, d;
int ans = 0;

int dfs(int size){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            visited[i][j] = 0;

    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        int a = v[i].first;
        int b = v[i].second;
        visited[a][b] = true;
        cnt++;
        q.push(make_pair(a,b));
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int cx = cur.first + dx[i];
            int cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > n) continue;
            if(u > abs(arr[cx][cy] - arr[cur.first][cur.second]) ||
                abs(arr[cx][cy] - arr[cur.first][cur.second]) > d) continue;
            if(0 < visited[cx][cy]) continue;
            visited[cx][cy] = 1;
            cnt++;
            //cout << cx << " and " << cy << "was pushed\n";
            q.push(make_pair(cx,cy));
        }
    }
    return cnt;
}

void func(int num){
     if(num==k){
         ans = max(ans, dfs(q.size()));
         return;
     }
     for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
            if(visited[i][j]) continue;
            v.push_back(make_pair(i,j));
            func(num+1);
            v.pop_back();
        }
    }
    return;
}
int main() {
    cin >> n >> k >> u >> d;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    func(0);
    cout << ans;
    return 0;
}