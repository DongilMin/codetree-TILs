#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int arr[11][11];
int n;
bool row[11];
bool col[11];
int ans = INT_MIN;
vector<int>v;

int cal(){
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }
    return sum;
}

void solve(int cnt){
    if(cnt == n){
        ans = max(ans, cal());
    }
    for(int a=1; a<=n; a++){
        if(row[a]) continue;
        row[a] = true;
        for(int b=1; b<=n; b++){
            if(col[b]) continue;
            col[b] = true;
            v.push_back(arr[a][b]);
            solve(cnt+1);
            v.pop_back();
            col[b] = false;
        }
        row[a] = false;
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