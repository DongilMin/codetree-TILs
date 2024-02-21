#include <iostream>
#include <climits>
using namespace std;
int arr[101][101];
int n,m;
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        int cnt = 1;
        for(int j=2; j<=n; j++){
            if(arr[i][j-1] == arr[i][j]) cnt++;
            if(cnt == m){
                ans++;
                break;
            }
        }
    }
    for(int i=1; i<=n; i++){
        int cnt = 1;
        for(int j=2; j<=n; j++){
            if(arr[j-1][i] == arr[j][i]) cnt++;
            if(cnt == m){
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}