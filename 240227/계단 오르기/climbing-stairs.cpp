#include <iostream>
using namespace std;
int main() {
    int arr[10001];
    int n;
    cin >> n;
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i=4; i<=n; i++){
        arr[i] = (arr[i-2] + arr[i-3])%10007;
    }
    cout << arr[n];
    return 0;
}