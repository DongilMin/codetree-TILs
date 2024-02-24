#include <iostream>
#include <vector>
using namespace std;
int k,n;
vector<int> v;
void print(){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
    cout <<'\n';
    return;
}

void pick(int num){
    if(v.size() == k){
        print();
        return;
    }
    for(int i=1; i<=n; i++){
        v.push_back(i);
        pick(i);
        v.pop_back();
    }
    return;
}
int main() {
    cin >> n >> k;
    pick(1);
    return 0;
}