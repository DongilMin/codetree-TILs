#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int x[2001];
    int y[2001];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        int dis = 0;
        int curX = 0;
        int curY = 0;
        for(int j=1; j<=n; j++){
            if(j==i) continue;
            dis += abs(x[j]-curX)+abs(y[j]-curY);
            curX = x[j];
            curY = y[j];
        }
        ans = min(ans, dis);
    }
    cout << ans;
}