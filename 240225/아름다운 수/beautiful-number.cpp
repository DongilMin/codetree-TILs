#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt = 0;
vector<int> v;
void print(){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
    cout <<'\n';
    return;
}

void pick(int cur){
    if(cur >= n+1){
        cnt++;
        return;
    }
    for(int i=1; i<=4; i++){
        for(int j=0; j<i; j++){
            v.push_back(i);
        }
        if(cur + i <= n+1) pick(cur+i);
        for(int j=0; j<i; j++){
            v.pop_back();
        }
    }
    return;
}
int main(){
    cin >> n;
    pick(1);
    cout << cnt;
}