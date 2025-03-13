#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

void left_shift(int row) {
    int first = a[row][0];
    for (int i = 0; i < m - 1; i++) {
        a[row][i] = a[row][i + 1];
    }
    a[row][m - 1] = first;
}

void right_shift(int row) {
    int last = a[row][m - 1];
    for (int i = m - 2; i >= 0; i--) {
        a[row][i + 1] = a[row][i];
    }
    a[row][0] = last;
}

void shift(int row, char d) {
    if (d == 'L') left_shift(row);
    if (d == 'R') right_shift(row);
}

void up(int row, char d) {
    char next_d = (d == 'L') ? 'R' : 'L';
    shift(row, next_d);

    if (row < 0) return;

    bool check = false;
    for (int i = 0; i < m; i++) {
        if (a[row][i] == a[row - 1][i]) {
            check = true;
            break;
        }
    }
    if (check) up(row - 1, next_d);
}

void down(int row, char d) {
    char next_d = (d == 'L') ? 'R' : 'L';
    shift(row, next_d);

    if (row >= n ) return;

    bool check = false;
    for (int i = 0; i < m; i++) {
        if (a[row][i] == a[row + 1][i]) {
            check = true;
            break;
        }
    }
    if (check) down(row + 1, next_d);
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        r--; // 1-based index를 0-based로 변환

        shift(r, d); // 바람이 먼저 불어야 함

        bool up_affected = false, down_affected = false;

        for (int j = 0; j < m; j++) {
            if (r > 0 && a[r][j] == a[r - 1][j]) {
                up_affected = true;
            }
            if (r < n - 1 && a[r][j] == a[r + 1][j]) {
                down_affected = true;
            }
        }

        if (up_affected) up(r - 1, d);
        if (down_affected) down(r + 1, d);
    }

    print();
    return 0;
}