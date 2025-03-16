#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];
int b[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool in_range(int row, int col) {
    return row >= 0 && row < n && col >=0 && col < m;
}

void clock_dir_shift(int src_row, int src_col, int des_row, int des_col) {
    int temp = a[src_row + 1][src_col];
    
    int src_row_des_col = a[src_row][des_col];
    for (int j = des_col; j > src_col; j--) {
        a[src_row][j] = a[src_row][j - 1];
    }
    a[src_row][src_col] = temp;
    
    int des_row_des_col = a[des_row][des_col];
    for (int i = des_row; i > src_row + 1; i--) {
        a[i][des_col] = a[i-1][des_col];
    }
    a[src_row+1][des_col] = src_row_des_col;

    int des_row_src_col = a[des_row][src_col];
    for (int j = src_col; j < des_col - 1; j++) {
        a[des_row][j] = a[des_row][j+1];
    }
    a[des_row][des_col - 1] = des_row_des_col;


    for (int i = src_row + 1; i < des_row - 1; i++) {
        a[i][src_col] = a[i + 1][src_col];
    }
    a[des_row - 1][src_col] = des_row_src_col;
}


void change(int row, int col) {

    int val = a[row][col];
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nx = row + dx[i];
        int ny = col + dy[i];

        if(in_range(nx, ny)) {
            val += a[nx][ny];
            cnt++;
        }
    }
    b[row][col] = val / cnt;
}

void func(int r1, int c1, int r2, int c2) {
    clock_dir_shift(r1,c1,r2,c2);

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            change(i,j);
        }
    }

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            a[i][j] = b[i][j];
        }
    }

}
int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        func(r1, c1, r2, c2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
