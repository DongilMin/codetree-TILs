#include <iostream>
#include <climits>
using namespace std;
int arr[50][50]={0};
int n,m;
int ans = INT_MIN;
int k[3][5][5] = {
    {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
    },
    {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
    },
    {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0},
    }
};
int check(int a, int b){
    int result = INT_MIN;
    for(int v=0; v<3; v++){
        int cnt = 0;
        for(int i=a-2; i<a+3; i++){
            for(int j=b-2; j<b+3; j++){
                if(arr[i][j] == 1 && k[v][i-a+2][j-b+2] == 1) cnt++;
            }
        }
        if(cnt*m - v*v+(v+1)*(v+1) < 0) continue;
        else result = max(result, cnt);
    }
    return result;
}
int main() {
    cin >> n >> m;
    for(int i=2; i<=n+1; i++){
        for(int j=2; j<=n+1; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=2; i<=n+1; i++){
        for(int j=2; j<=n+1; j++){
            ans = max(ans, check(i,j));
        }
    }
    cout << ans;

    return 0;
}