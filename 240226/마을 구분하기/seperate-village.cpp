#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>>q;
int arr[26][26];
bool visited[26][26] = {0};
int n;
vector<int>v;
void dfs(int i,int j){
    q.push(make_pair(i,j));
    int trash = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int cx = cur.first + dx[i];
            int cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > n) continue;
            if(arr[cx][cy] == 0) continue;
            if(visited[cx][cy]) continue;
            visited[cx][cy] = true;
            trash++;
            q.push(make_pair(cx,cy));
        }
    }
    v.push_back(trash);
}
int main() {
    int cnt = 0;
    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                visited[i][j] = true;
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}