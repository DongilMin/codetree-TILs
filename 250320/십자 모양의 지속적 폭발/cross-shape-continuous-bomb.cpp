#include <iostream>

using namespace std;

int n, m, c;
int grid[200][200];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool in_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void fall(int col) {
    int temp[200]; 
    int end_of_array = 0;

    for (int i = 0; i < n; i++) {
        if (grid[i][col] != 0) {
            temp[end_of_array] = grid[i][col];
            end_of_array++;
        }
    }

    int index = n - 1;
    for (int i = end_of_array - 1; i >= 0; i--) {
        grid[index][col] = temp[i]; 
        index--;
    }

    while (index >= 0) {
        grid[index][col] = 0;
        index--;
    }
}

void bomb(int c) {

    int first_of_row = -1;

    for (int i = 0; i < n; i++) {
        if (grid[i][c] != 0) {
            first_of_row = i;
            break;
        }
    }

    if (first_of_row == -1) return;

    int val = grid[first_of_row][c];
    for (int i = 0; i < val; i++) {
        for (int j = 0; j < 4; j++) {
            int nx = first_of_row + (dx[j] * i);
            int ny = c + (dy[j] * i);

            if(!in_range(nx,ny)) continue;
            grid[nx][ny] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        fall(i);
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> c;
        c--;
        bomb(c);
    }
    print();
    return 0;
}
