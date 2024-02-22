#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[21][21];

int solve(int x,int y, int w, int h){
    int cnt = 0;
    for(int i=0; i<=x+h; i++){
        for(int j=0; j<=y+w; j++){
            if(arr[i][j] < 0) return -1;
            cnt ++;
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    int ans = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            for(int k=0; k<m; k++){
                for(int l=0; l<n; l++){
                    if( i+l >= n || j+k >= m) continue;
                    ans = max(ans, solve(i,j,k,l));
                }
            }
        }
    }
    cout << ans;
    return 0;
}