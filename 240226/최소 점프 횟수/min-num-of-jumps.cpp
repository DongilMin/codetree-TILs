#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int n;
int ans = INT_MAX;
vector<int>jump;
void f(int location, int count){
    if(location >= n) return;
    else if(location == n-1){
        ans = min(ans, count);
        return;
    }
    else{
        int dis = jump[location];
        for(int i=1; i<= dis; i++){
            f(location+i, count+1);
        }
        return;
    }
}
int main() {
    int k;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> k;
        jump.push_back(k);
    }
    f(0,0);
    if(ans == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << ans;
}