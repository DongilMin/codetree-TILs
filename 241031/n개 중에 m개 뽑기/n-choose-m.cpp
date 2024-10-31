#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
void print(){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }cout << '\n';
}
int n,m;
void f(int num,int cnt){
    if(cnt == m){
        print();
        return;
    }
    for(int i=num+1; i<=n; i++){
        v.push_back(i);
        f(i,cnt+1);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;
    f(0,0);
    return 0;