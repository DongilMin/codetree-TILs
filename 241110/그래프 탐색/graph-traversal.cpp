#include <iostream>
#include <vector>
using namespace std;
int n,m;
int cnt = 0;
vector<int> graph[1001];
bool visited[1001];

DFS(int curr){
    for (int i : graph[curr]){
        if (!visited[i]){
            visited[i] = true; 
            cnt++;
            DFS(i);
        }
    }
}
int main() {

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited[1] = true;
    DFS(1);

    cout << cnt;
    return 0;
}