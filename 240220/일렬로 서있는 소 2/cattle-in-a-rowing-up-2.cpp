#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <stack>
using namespace std;
int main() {
    int n;
    int arr[101];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j==i) continue;
            for(int k=0; k<n; k++){
                if(k==j) continue;
                if(i<j && j<k && arr[i] <= arr[j] && arr[j] <= arr[k]) cnt++;
            }
        }
    }
    cout << cnt;
}