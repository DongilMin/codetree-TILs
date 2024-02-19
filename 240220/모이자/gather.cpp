#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    int n;
    int home[101];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> home[i];
    }
    int result = INT_MAX;
    for(int i=1; i<=n; i++){
        int dis = 0;
        for(int j=1; j<=n; j++){
            if(j==i) continue;
            dis += abs(i-j)*home[j];
        }
        result = min(result, dis);
    }
    cout << result;
}