#include <iostream>
#include <algorithm>

using namespace std;

int n;
int result = 0;
int grid[20][20];
int dir[4][2] = { {-1, 1}, {-1, -1}, {1, -1}, {1, 1} };

bool in_range(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int search(int x, int y) {
    int max_sum = 0;
    
    // 가능한 모든 크기의 기울어진 직사각형 탐색
    for (int d1 = 1; d1 < n; d1++) {
        for (int d2 = 1; d2 < n; d2++) {
            int sum = grid[x][y];
            int curr_x = x, curr_y = y;
            bool valid = true;
            
            // 4 방향 이동
            for (int d = 0; d < 4; d++) {
                int steps = (d % 2 == 0) ? d1 : d2; // d1, d2를 번갈아 사용
                for (int s = 0; s < steps; s++) {
                    curr_x += dir[d][0];
                    curr_y += dir[d][1];
                    if (d == 3 && curr_x == x && curr_y == y){
                        break;
                    }
                    if (!in_range(curr_x, curr_y)) {
                        valid = false;
                        break;
                    }
                    sum += grid[curr_x][curr_y];
                }
                if (!valid) break;
            }
            
            if (valid) max_sum = max(max_sum, sum);
        }
    }
    
    return max_sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, search(i, j));
        }
    }

    cout << result << '\n';
    return 0;
}
