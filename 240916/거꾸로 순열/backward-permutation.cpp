#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int>v;
bool visited[10] = {0};

void print(){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void solve(){
    if(v.size() == n){
        print();
        return;
    }
    for(int i=n; i>0; i--){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            solve();
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    solve();
    return 0;
}