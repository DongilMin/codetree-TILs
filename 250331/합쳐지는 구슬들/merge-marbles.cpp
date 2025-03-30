#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t;
struct ball {
    int num;
    int r;
    int c;
    int d;
    int w;
    ball(int val, int row, int col, int dir, int weight) {
        num = val;
        r = row;
        c = col;
        d = dir;
        w = weight;
    }
};
vector<ball> v;

int board[50][50] = {0};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
void remove_func(int i, int j) {
    int w_sum = 0;
    int max_num = 0;
    int dir = 0;
    int cnt = 0;
    vector<int>index;

    for (int k = 0; k < v.size(); k++) {
        ball b = v[k];
        if (b.r == i && b.c == j) {
            index.push_back(k);
            cnt++;
            w_sum += b.w;
            if (max_num < b.num) {
                max_num = b.num;
                dir = b.d;
            }
        }
    }
    while (!index.empty()) {
        int k = index.back();
        index.pop_back();
        v.erase(v.begin() + k);
    }

    v.emplace_back(max_num, i, j, dir, w_sum);
}

void remove_crash() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 1) {
                remove_func(i,j);
                board[i][j] = 1;
            }
        }
    }
}

void simulate() {
    for (auto& b : v) {
        int nx = b.r + dx[b.d];
        int ny = b.c + dy[b.d];
        if (!in_range(nx, ny)) {
            b.d = (b.d + 2) % 4;
        }
        else {
            board[b.r][b.c]--;
            board[nx][ny]++;
            b.r = nx;
            b.c = ny;
        }
    }

    remove_crash();
}

int make_dir(char d) {
    if (d == 'U') return 0;
    else if (d == 'R') return 1;
    else if (d == 'D') return 2;
    else return 3;
}

void print() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m >> t;

    int r, c, w;
    char d;
    for (int i = 0; i < m; i++) {
        cin >> r >> c >> d >> w;
        r--;
        c--;
        board[r][c]++;
        int dir = make_dir(d);
        v.emplace_back(i,r,c,dir,w);
    }

    for (int i = 0; i < t; i++) {
        simulate();
    }
    int max_num = 0;
    for (auto b : v) {
        if (max_num < b.w) max_num = b.w;
    }
    cout << v.size() << ' ' << max_num;
}
