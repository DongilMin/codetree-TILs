#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int>v;
void print(){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout<< "\n";
}
void solve(int curr){
    if(v.size() == m){
        print();
        return;
    }
    for(int i=curr; i<=n; i++){
        v.push_back(i);
        solve(i+1);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;
    solve(1);
    return 0;
}