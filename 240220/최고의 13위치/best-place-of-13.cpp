#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;
int main() {
    int arr[21][21];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    int result = 0;
    for(int i=0; i<n; i++){
        int count;
        for(int j=0; j<n-2; j++){
            result = max(result, arr[i][j] + arr[i][j+1] + arr[i][j+2]);
        }
    }
    cout << result;
    return 0;
}