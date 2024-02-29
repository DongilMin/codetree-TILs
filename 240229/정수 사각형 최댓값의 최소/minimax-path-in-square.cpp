#include <iostream>

#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[101][101];
    int maxdp[101][101];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    maxdp[1][1] = arr[1][1];
    for(int i=2; i<=n; i++){
        maxdp[1][i] = max(maxdp[1][i-1], arr[1][i]);
    }
    for(int i=2; i<=n; i++){
        maxdp[i][1] = max(maxdp[i-1][1], arr[i][1]);
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            maxdp[i][j] = max(min(maxdp[i-1][j], maxdp[i][j-1]), arr[i][j]);
        }
    }

    cout << maxdp[n][n] << "\n";
    return 0;
}