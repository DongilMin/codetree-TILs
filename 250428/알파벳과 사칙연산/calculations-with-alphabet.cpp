#include <bits/stdc++.h>
using namespace std;

string expr;
int best = INT_MIN;

// letterIdx = 0('a') .. 5('f')
void dfs(int letterIdx, array<int,6>& val){
    if(letterIdx == 6){
        int acc = val[expr[0]-'a'];
        for(int i = 1; i < expr.size(); i += 2){
            char op = expr[i];
            int  x  = val[expr[i+1]-'a'];
            if      (op=='+') acc += x;
            else if (op=='-') acc -= x;
            else /*'*'*/      acc *= x;
        }
        best = max(best, acc);
        return;
    }
    for(int x = 1; x <= 4; ++x){
        val[letterIdx] = x;
        dfs(letterIdx+1, val);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> expr;
    array<int,6> val;
    val.fill(1);
    dfs(0, val);
    cout << best << "\n";
    return 0;
}
