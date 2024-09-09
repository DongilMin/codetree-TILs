#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int result = 0;
vector<pair<int,int>>ans;
vector<pair<int,int>>v;

bool check(int x1, int x2){
    return ans[x1].first > ans[x2].second || ans[x1].second < ans[x2].first;
}

bool is_possible(){
    for(int i=0; i<ans.size(); i++){
        for(int j=i+1; j<ans.size(); j++){
            if(!check(i,j)) return false;
        }
    }
    return true;
}

void solve(int index){
    if(index == n){
        if(is_possible()) result = max(result, (int)ans.size());
        return;
    }
    ans.push_back(v[index]);
    solve(index+1);
    ans.pop_back();
    solve(index+1);
    
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int x1,x2;
        cin >> x1 >> x2;
        v.push_back(make_pair(x1, x2));
    }
    solve(0);
    cout<<result;
    return 0;
}