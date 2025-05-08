#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[1001];
vector<vector<int>> v;
int cnt = 0;

void DFS(int curr) {
    visited[curr] = true;
    for (int next : v[curr]) {
        if (visited[next]) continue;
        cnt++;
        DFS(next);
    }
}
int main() {
    cin >> n >> m;
    v.resize(n + 1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1);
    cout << cnt;

    return 0;
}
