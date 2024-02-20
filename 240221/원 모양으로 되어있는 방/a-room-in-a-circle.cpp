#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    cin >> n;
    int room[1004];

    for(int i=1; i<=n; i++) {
        cin >> room[i];
    }

    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        int dis = 0;
        for(int j=1; j<=n; j++){
            int dist = (j+n-i)%n;
            dis += dist*room[j];
        }
        ans = min(ans, dis);
    }
    cout << ans;
    return 0;
}