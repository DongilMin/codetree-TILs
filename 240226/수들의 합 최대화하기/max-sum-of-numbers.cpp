#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int arr[11][11];
int n;
bool visit[11];
int ans = INT_MIN;
vector<int>v;
int cal(){
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }
    return sum;
}

void solve(int row){
    if(row == n+1){
        ans = max(ans, cal());
        return;
    }
    for(int col = 0; col<=n; col++){
        if(visit[col]) continue;
        visit[col] = true;
        v.push_back(arr[row][col]);
        solve(row+1);
        v.pop_back();
        visit[col] = false;
    }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    solve(0);
    cout << ans;
}