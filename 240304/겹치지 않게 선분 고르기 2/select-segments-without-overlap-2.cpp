#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int>a, pair<int,int>b){
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}
int main() {
    int n,a,b;
    cin >> n;
    vector<pair<int,int>>v;
    int dp[1001];
    v.push_back(make_pair(0,0));
    for(int i=1; i<=n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end(), compare);
    dp[0] = 0;
    for(int i=1; i<=v.size(); i++){
        if(v[i].first > v[i-1].second) dp[i] = dp[i-1]+1;
    }
    cout << dp[n];
    return 0;
}