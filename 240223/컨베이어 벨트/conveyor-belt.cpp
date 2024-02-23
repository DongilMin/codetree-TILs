#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin >> n >> t;
    int arr[401];
    for(int i=0; i<2*n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<t%(2*n); i++){
        int tmp = arr[2*n-1];
        for(int i=2*n; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = tmp;
    }

    for(int i=0; i<n; i++) cout << arr[i] << ' ';
    cout << '\n';
    for(int i=n; i<2*n; i++) cout << arr[i] << ' ';
    return 0;
}// 6 1 2 3 4 5