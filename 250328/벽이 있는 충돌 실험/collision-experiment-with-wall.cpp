#include <iostream>
#include <queue>
using namespace std;

int T;
int n, M;
int board[51][51];
// 상 우 하 좌
//  0 1 2 3
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<pair<pair<int, int>, int>> q1, q2, new_q;
bool in_range (int x,int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
int make_dir(char a) {
    if (a == 'L') return 3;
    else if (a == 'D') return 2;
    else if (a == 'R') return 1;
    else return 0;
}
void find_crash() {
    while (!q2.empty()){
        auto curr = q2.front();
        q2.pop();
        int cx = curr.first.first;
        int cy = curr.first.second;
        int dir = curr.second;
        if (board[cx][cy] >= 2) {
            board[cx][cy] = 0;
        }
        else if (board[cx][cy] == 1){
            new_q.push({{cx,cy}, dir});
        }
    }
}
void simulate() {
    while (!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        int dir = curr.second;
        int cx = curr.first.first;
        int cy = curr.first.second;
        int nx = curr.first.first + dx[dir];
        int ny = curr.first.second + dy[dir];
        if (in_range(nx,ny)) {
            board[nx][ny]++;
            board[cx][cy]--;
            q2.push({{nx,ny},dir});
        }
        else {
            int inverse_dir = (dir + 2) % 4;
            q2.push({{cx, cy}, inverse_dir});
        }
    }
    find_crash();
    q1 = new_q;
    while (!new_q.empty()) new_q.pop();
}
int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 50; i++)
            for (int j = 0; j < 50; j++)
                board[i][j] = 0;
        cin >> n >> M;
        int x, y;
        char a;
        for (int i = 0; i < M; i++) {
            cin >> x >> y >> a;
            x--;
            y--;
            board[x][y]++;
            int d = make_dir(a);
            q1.push({{x,y},d});
        }

        for (int j = 0; j < 2*n; j++) {
            simulate();
        }

        cout << q1.size() << '\n';
        while (!q1.empty()) q1.pop();
        while (!q2.empty()) q2.pop();
        while (!new_q.empty()) new_q.pop();
    }
    return 0;
}