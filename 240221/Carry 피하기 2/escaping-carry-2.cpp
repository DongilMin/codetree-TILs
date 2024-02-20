#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    int arr[23];
    cin >> n;
    int b1[23] ={0};
    int b2[23] ={0};
    int b3[23] ={0};
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        b1[i] = arr[i]%10;
        b2[i] = (arr[i]/10)%10;
        b3[i] = (arr[i]/100)%10;
    }
    int ans = INT_MIN;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                if(arr[i] + arr[j] + arr[k] > 9999) continue;
                if(b1[i] + b1[j] + b1[k] >= 10) continue;
                if(b2[i] + b2[j] + b2[k] >= 10) continue;
                if(b3[i] + b3[j] + b3[k] >= 10) continue;
                ans = max(ans, arr[i] + arr[j] + arr[k]);
            }
        }
    }
    cout << ans;
    return 0;
}