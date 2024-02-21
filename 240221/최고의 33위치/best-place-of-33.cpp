#include <iostream>
#include <climits>
using namespace std;
int board[21][21];
int n;
int count(int a, int b){
    int result = 0;
    for(int i=a; i<a+3; i++){
        if(i > n) continue;
        for(int j=b; j<b+3; j++){
            if(j > n) continue;
            result += board[i][j];
        }
    }
    return result;
}
int main() {
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> board[i][j];

    int ans = INT_MIN;
    for(int i=1; i<=n-2; i++){
        for(int j=1; j<=n-2; j++){
            ans = max(ans, count(i,j));
        }
    }
    cout << ans;
    return 0;
}