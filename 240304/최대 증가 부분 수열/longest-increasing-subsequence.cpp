#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    int arr[1001];
    int dp[1001];
    arr[0] = 0;
    dp[0] = 0;
    dp[1]= 1;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for(int i=2; i<=n; i++){
        for(int j=i-1; j>0; j--){
            if(arr[i] > arr[j]){
                dp[i] = dp[j]+1;
                break;
            }
        }
    }
    cout << dp[n];
    return 0;
}