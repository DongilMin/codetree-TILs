#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int result = 0;
vector<pair<int,int>>v;
vector<pair<int,int>>ans;
bool visit[20];
bool check(int i, int j){
    int ax1=v[i].first;
    int ax2=v[i].second;
    int bx1=v[j].first;
    int bx2=v[j].second;
    return (ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) ||
           (bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2);
}

bool possible(){
    for(int i=0; i<ans.size(); i++){
        for(int j=i+1; j<ans.size(); j++){
            if(check(i,j)) return false;
        }
    }
    return true;
}
void solve(int index){
    if(index == n){
        if(possible()) result = max(result, (int)ans.size());
        return;
    }

    ans.push_back(v[index]);
    solve(index+1);
    ans.pop_back();
    solve(index+1);
}

int main() {
    int a,b;
    cin >> n;
    int tmp = n;
    while(tmp--){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    solve(0);
    cout << result;
    return 0;
}