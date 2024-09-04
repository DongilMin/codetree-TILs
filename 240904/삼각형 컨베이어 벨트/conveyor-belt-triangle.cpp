#include <iostream>
using namespace std;

int main() {
    int n,t;
    int arr[604];
    cin >> n >> t;
    for(int i=1; i<=3*n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<t; i++){
        int temp = arr[3*n];
        for(int j=3*n; j>0; j--){
            arr[j] = arr[j-1];
        }
        arr[1] = temp;
    }
    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << "\n";
    for(int i=n+1; i<=2*n; i++) cout << arr[i] << " ";
    cout << "\n";
    for(int i=2*n+1; i<=3*n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}