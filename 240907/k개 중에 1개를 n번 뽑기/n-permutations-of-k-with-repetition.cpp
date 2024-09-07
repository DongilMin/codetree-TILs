#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n,k;
void print(){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void cal(){
    if(v.size() == n){
        print();
        return;
    }

    for(int i=1; i<=k; i++){
        v.push_back(i);
        cal();
        v.pop_back();
    }

}

int main() {
    cin >> n >> k;
    cal();
    
}