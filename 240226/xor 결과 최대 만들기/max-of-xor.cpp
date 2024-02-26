#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n,m;
int ans = 0;
int arr[21];
int cal(){
    int sum = v[0];
    for(int i=1; i<v.size(); i++){
        sum ^= v[i];
    }
    return sum;
}
void f(int num,int cnt){
    if(cnt == m){
        ans = max(ans, cal());
        return;
    }

    for(int i=num+1; i<=n; i++){
        v.push_back(arr[i]);
        f(i,cnt+1);
        v.pop_back();
    }

}
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    f(0,0);
    cout << ans;
    return 0;
}