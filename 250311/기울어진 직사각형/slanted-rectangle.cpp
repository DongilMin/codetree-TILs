#include <iostream>

using namespace std;

int n;
int result = 0;
int grid[20][20];
int dir[4][2] = { {-1, 1}, {-1, -1}, {1, -1}, {1, 1} };

bool in_range(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int search(int x, int y) {
    int sum = grid[x][y];
    int curr_x = x;
    int curr_y = y;
    int curr_dir = 0;

    while(curr_dir < 4){

        curr_x += dir[curr_dir][0];
        curr_y += dir[curr_dir][1];
        if (curr_x == x && curr_y == y){
            return sum;
        }
        else if (in_range(curr_x, curr_y)){
            sum += grid[curr_x][curr_y];
        }
        else {
            curr_x -= dir[curr_dir][0];
            curr_y -= dir[curr_dir][1];
            curr_dir++;
            if (!(in_range(curr_x + dir[curr_dir][0], curr_y + dir[curr_dir][1]))){
                sum = 0;
                break;
            }
        }
    }

    return sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, search(i,j));
        }
    }

    cout << result << '\n';
    return 0;
}
