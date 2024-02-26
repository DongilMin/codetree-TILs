#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt = 0;
int arr[5][5];
int info[5][5];
int dx[9] = {0,-1,-1,0,1,1,1,0,-1};
int dy[9] = {0,0,1,1,1,0,-1,-1,-1};
vector<pair<int,int>>v;
bool find(int i, int j){
    int a = i;
    int b = j;
    while(true){
        if(a<0 || b<0 || a>n || b>n) return false;
        a += dx[info[i][j]];
        b += dy[info[i][j]];
        if(arr[i][j] < arr[a][b]){
            return true;
        }
    }
}

void solve(int r, int c, int count){
    if(!find(r,c)){
        cnt = max(cnt, count);
        return;
    }
    else{
        int a = r;
        int b = c;
        while(!(a<=0 || b<=0 || a>n || b>n)){
            a += dx[info[r][c]];
            b += dy[info[r][c]];
            if(arr[r][c] < arr[a][b]){
                v.push_back(make_pair(a,b));
                solve(a,b,count+1);
                v.pop_back();
            }
        }
    }
}

int main() {
    int r,c;
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> info[i][j];

    cin >> r >> c;
    solve(r,c,0);
    cout << cnt;
}