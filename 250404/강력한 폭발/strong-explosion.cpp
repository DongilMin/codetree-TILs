#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[20][20];
vector<pair<int,int>> v;
int result = 0;

bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int bomb(int num, int x, int y, int mark) {
    int cnt = 0;
    if (num == 1) {
        for (int i = 1; i <= 2; i++) {
            int nx1 = x - i;
            int nx2 = x + i;
            if (in_range(nx1, y) && grid[nx1][y] == 0) {
                grid[nx1][y] = mark;
                cnt++;
            }
            if (in_range(nx2, y) && grid[nx2][y] == 0) {
                grid[nx2][y] = mark;
                cnt++;
            }
        }
    }
    else if (num == 2) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (in_range(nx, ny) && grid[nx][ny] == 0) {
                grid[nx][ny] = mark;
                cnt++;
            }
        }
    }
    else if (num == 3) {
        int dx[4] = {-1, -1, 1, 1};
        int dy[4] = {-1, 1, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (in_range(nx, ny) && grid[nx][ny] == 0) {
                grid[nx][ny] = mark;
                cnt++;
            }
        }        
    }
    return cnt;
}

void reset(int num, int x, int y, int mark) {
    if (num == 1) {
        for (int i = 1; i <= 2; i++) {
            int nx1 = x - i;
            int nx2 = x + i;
            if (in_range(nx1, y) && grid[nx1][y] == mark) {
                grid[nx1][y] = 0;
            }
            if (in_range(nx2, y) && grid[nx2][y] == mark) {
                grid[nx2][y] = 0;
            }

        }
    }
    else if (num == 2) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (in_range(nx, ny) && grid[nx][ny] == mark) {
                grid[nx][ny] = 0;
            }
        }
    }
    else {
        int dx[4] = {-1, -1, 1, 1};
        int dy[4] = {-1, 1, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (in_range(nx, ny) && grid[nx][ny] == mark) {
                grid[nx][ny] = 0;
            }
        }        
    }

}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void func(int index, int curr, int mark) {
    if (index == v.size()) {
        result = max(result, curr);
        // print();
        return;
    }
    auto now = v[index];
    for (int i = 1; i <= 3; i++) {
        int gained = bomb(i, now.first, now.second, mark);
        func(index + 1, curr + gained, mark + 1);
        reset(i, now.first, now.second, mark);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) v.push_back({i,j});
        }
    }
    func(0, v.size(), 2);
    cout << result;
    return 0;
}
