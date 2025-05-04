#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, last, cnt, dist;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> grid(N);
    for(int i=0; i<N; i++) 
        cin >> grid[i];

    int sx=-1, sy=-1;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        if(grid[i][j]=='S'){ sx=i; sy=j; }
    }

    // visited[x][y][last_num 0..9][collected count 0..3]
    static bool visited[20][20][10][4] = {};
    queue<State> q;
    q.push({sx, sy, 0, 0, 0});
    visited[sx][sy][0][0] = true;

    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        // 만약 E이고 cnt>=3 이면
        if(cur.cnt >= 3 && grid[cur.x][cur.y]=='E'){
            cout << cur.dist << "\n";
            return 0;
        }
        for(int d=0;d<4;d++){
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if(nx<0||ny<0||nx>=N||ny>=N) continue;

            char c = grid[nx][ny];
            int nlast = cur.last;
            int ncnt  = cur.cnt;

            if(isdigit(c)){
                int v = c - '0';
                if(v > cur.last){
                    // 새 동전 수집
                    nlast = v;
                    ncnt  = min(cur.cnt+1, 3); 
                }
                // else: 숫자지만 last 이상이면 그냥 지나침
            }
            // '.', 'S', 'E' 는 어떤 제약 없이 그냥 지나감

            if(!visited[nx][ny][nlast][ncnt]){
                visited[nx][ny][nlast][ncnt] = true;
                q.push({nx, ny, nlast, ncnt, cur.dist+1});
            }
        }
    }

    // 탈출 못 하면
    cout << -1 << "\n";
    return 0;
}
