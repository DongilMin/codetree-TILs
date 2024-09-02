#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int n,m;
int arr[21][21];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


bool in_range(int i,int j){
    return i<n && j<m;
}

int getSum(int x, int y, int w, int h){
    int curr = 0;
    for(int i=x; i<=x+h; i++){
        for(int j=y; j<=y+w; j++){
            if(arr[i][j] < 0) return -1;
            curr++;
        }
    }
    return curr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int result = -1001;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            for(int h=0; h<n; h++){
                for(int w=0; w<m; w++){
                    if(!in_range(i+h, j+w)) continue;
                    result = max(result, getSum(i,j,w,h));
                }
            }
        }
    }

    cout << result;
    return 0;
}