#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[21][21];
    int ans = INT_MIN;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-2; j++){
            int num = arr[i][j]+arr[i][j+1]+arr[i][j+2];

            for(int k=1; k<=n; k++){
                for(int l=1; l<=n-2; l++){

                    if(i == k && j == l) continue;
                    if(i == k && j+1 == l) continue;
                    if(i == k && j+2 == l) continue;
                    if(i == k && l == j) continue;
                    if(i == k && l+1 == j) continue;
                    if(i == k && l+3 == j) continue;
                    int second = arr[k][l]+arr[k][l+1]+arr[k][l+2];
                    ans = max(ans, num + second);

                }
            }
        }
    }
    cout << ans;
    return 0;
}