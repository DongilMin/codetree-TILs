#include <iostream>
#include <vector>
using namespace std;

int n, m;
int move_nums[100];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<vector<vector<int>>> v;

bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void simulate(int num) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < v[i][j].size(); k++) {
                if (v[i][j][k] == num) {
                    int find_max = -1;
                    int dir_x = -1;
                    int dir_y = -1;
                    
                    // 이동 방향 탐색
                    for (int l = 0; l < 8; l++) {
                        int nx = i + dx[l];
                        int ny = j + dy[l];
                        if (!in_range(nx, ny)) continue;
                        if (v[nx][ny].empty()) continue;
                        for (int s = 0; s < v[nx][ny].size(); s++) {
                            if (find_max < v[nx][ny][s]) {
                                find_max = v[nx][ny][s];
                                dir_x = nx;
                                dir_y = ny;
                            }
                        }
                    }
                    if (dir_x != -1 && dir_y != -1) {
                        for (int p = k; p < v[i][j].size(); p++) {
                            v[dir_x][dir_y].push_back(v[i][j][p]);
                        }
                        v[i][j].erase(v[i][j].begin() + k, v[i][j].end());
                        return;
                    }
                }
            }
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j].empty()) {
                cout << "None\n";
            } else {
                for (int k = v[i][j].size() - 1; k >= 0; k--) {
                    cout << v[i][j][k] << ' ';
                }
                cout << '\n';
            }
        }
    }
}

int main() {
    cin >> n >> m;
    v = vector<vector<vector<int>>>(n, vector<vector<int>>(n));

    int val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            v[i][j].push_back(val);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> move_nums[i];
    }

    for (int i = 0; i < m; i++) {
        simulate(move_nums[i]);

    }

    print();
    return 0;
}
