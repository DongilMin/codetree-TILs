#include <iostream>
#include <climits>
using namespace std;
int dx[4] = {-1,-1,1,1};
int dy[4] = {1,-1,-1,1};
int se[2] = {1,2};
int main() {
    int arr[201][201] = {0};
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> arr[i][j];

    int ans = INT_MIN;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=0; k<4; k++){
                int curX = i+dx[k];
                int curY = j+dy[k];
                if(curX > n || curX < 1 || curY > m || curY < 1) continue;
                ans = max(ans, arr[i][j] + arr[i][curY] + arr[curX][j]);
            }
            if(j+2 > n) continue;
            ans = max(ans, arr[i][j]+arr[i][j+1]+arr[i][j+2]);
            if(i+2 > n) continue;
            ans = max(ans, arr[i][j]+arr[i+1][j]+arr[i+2][j]);        

        }
    }
    cout << ans;
    return 0;
}