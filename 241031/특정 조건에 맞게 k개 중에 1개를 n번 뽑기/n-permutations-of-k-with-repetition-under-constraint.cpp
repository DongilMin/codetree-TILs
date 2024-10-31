#include <iostream>
#include <vector>
using namespace std;
int k,n;
vector<int>v;

void print(){
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<" ";
    }
    cout << '\n';
    return;
}

bool impossible(int num){
    if(v.size()<2) return false;
    return (v[v.size()-1] == num && v[v.size()-2] == num) || num > k;
}

void fun(int cnt){
    if(cnt == n){
        print();
        return;
    }
    for(int i=1; i<=k; i++){
        if(!impossible(i)){
            v.push_back(i);
            fun(cnt+1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> k >> n;
    fun(0);
    return 0;
}