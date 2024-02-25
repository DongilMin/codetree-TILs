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
    return (v[i].second < v[j].first)&&(v[i].first < v[j].first) ||
            (v[j].second < v[i].first)&&(v[j].first < v[i].first);
}

bool possible(){
    for(int i=0; i<ans.size(); i++){
        for(int j=i+1; j<ans.size(); j++){
            if(!check(i,j)) return false;
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