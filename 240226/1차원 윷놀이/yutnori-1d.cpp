#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
vector<int>v;
vector<int>player;
int score = 0;

void fun(int turn){
    if(turn >= m){
        int tmp = 0;
        for(int i=1; i<player.size(); i++){
            if(player[i] >= m){
                tmp++;
            }
        }
        score = max(score,tmp);
        return;
    }
    for(int j=1; j<player.size(); j++){
            if(player[j] >= m) continue;
            player[j] += v[turn];
            fun(turn+1);
            player[j] -= v[turn];
    }

}
int main() {
    cin >> n >> m >> k;
    v.push_back(0);
    player.push_back(0);
    for(int i=1; i<=k; i++) player.push_back(1);

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    fun(0);
    cout << score;
    return 0;
}