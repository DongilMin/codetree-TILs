#include <iostream>
using namespace std;
int n,m;
int result = 0;
int grid[101][101];

bool col(int i){
    if(m==1) return true;
    int count = 1;
    int rev = grid[1][i];
    for(int j=2; j<=n; j++){
        if(grid[j][i] == rev){
            count++;
            if(count == m) return true;
        }
        else count = 1;
        rev = grid[j][i];
    }
    return false;
}
bool row(int i){
    if(m==1) return true;
    int count = 1;
    int rev = grid[i][1];
    for(int j=2; j<=n; j++){
        if(grid[i][j] == rev){
            count++;
            if(count == m) return true;
        }
        else count = 1;
        rev = grid[i][j];
    }
    return false;
}
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        if(col(i)) result++;
        if(row(i)) result++;
    }

    cout << result;
    return 0;
}