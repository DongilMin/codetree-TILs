#include <iostream>

using namespace std;

int n, m;
int grid[200][200];
int dx[4] = {-1, 1, 1, -1};
int dy[4] = { 1,1, -1, -1};
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int result = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx < 0 || ny < 0 || nx >=n || ny >= m) continue;
                int curr = grid[i][j] + grid[nx][j] + grid[i][ny];
                if (curr > result) result = curr;
            }
            if( i != 0 && i < n-1){
                int curr = grid[i][j] + grid[i-1][j] + grid[i+1][j];    
                if (curr > result) result = curr;            
            }

            if( j != 0 && j < m-1){
                int curr = grid[i][j] + grid[i][j-1] + grid[i][j+1];
                if (curr > result) result = curr;                
            }
        }
    }
    cout << result;
    return 0;
}
