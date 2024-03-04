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
        dp[i]= -1;
    }
    sort(v.begin(), v.end(), compare);
    dp[1] = 1;
    int ans = 0;
    for(int i=1; i<=v.size(); i++){
        for(int j=1; j<i; j++){
            if(dp[j] == -1 )continue;
            if(v[i].first > v[j].second) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}