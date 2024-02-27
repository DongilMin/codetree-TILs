#include <iostream>
using namespace std;
int main() {
    int n;
    int arr[1001];
    cin >> n;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 7;
    for(int i=3; i<=n; i++){
        arr[i] = (arr[i-1]*3 +arr[i-2] -arr[i-3])%1000000007;
    }
    cout << arr[n];
    return 0;
}