#include <iostream>
using namespace std;
int main() {
    int n;
    int arr[1001];
    cin >> n;
    arr[1] = 2;
    arr[2] = 7;
    arr[3] = 22;
    for(int i=4; i<=n; i++){
        arr[i] = ((arr[i-2]*3)%1000000007 + (arr[i-1]*2)%1000000007)%1000000007;
    }
    // arr[3] = 14+ 8
    // 2 7 22
    cout << arr[n];
    return 0;
}