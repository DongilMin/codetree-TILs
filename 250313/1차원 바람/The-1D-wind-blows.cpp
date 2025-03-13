#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];
bool visited[100];
void left_shift(int col) {
    int row_first = a[col][0];
    for (int i = 0; i < m-1; i++) {
        a[col][i] = a[col][i+1];
    }
    a[col][m-1] = row_first;
}

void right_shift(int col) {
    int row_last = a[col][m-1];
    for (int i = m-2; i >= 0; i--) {
        a[col][i+1] = a[col][i];
    }
    a[col][0] = row_last;
}

void shift(int col, char d){
    if(d == 'L') left_shift(col);
    if(d == 'R') right_shift(col);
}
void up(int col, char d) {
    shift(col, d);
    if (col == 0) {
        return;
    }
    for (int i = 0; i < m; i++) {
        if(a[col][i] == a[col-1][i]) up(col-1, d);
    }
}
void down(int col, char d) {
    shift(col, d);
    if (col == n-1) {
        return;
    }
    for (int i = 0; i < m; i++) {
        if(a[col][i] == a[col-1][i]) down(col+1, d);
    }
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
        up(r,d);
        down(r,d);
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
