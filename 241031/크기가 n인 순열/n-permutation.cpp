#include <iostream>
#include <vector>
using namespace std;
bool visit[9];
int n;
vector<int>v;
void print(){
    for(int i=v.size()-1; i>0; i--){
        cout << v[i] << ' ';
    }cout <<'\n';
    return;
}
void solve(int cnt){
    if(cnt == n){
        print();
        return;
    }
    for(int i=1; i<=n; i++){
        if(visit[i]) continue;
        visit[i] = true;
        v.push_back(i);
        solve(cnt+1);
        v.pop_back();
        visit[i] = false;
    }
}
int main() {
    cin >> n;
    solve(0);
    return 0;
}