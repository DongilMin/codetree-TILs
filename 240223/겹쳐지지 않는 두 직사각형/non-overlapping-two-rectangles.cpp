#include <iostream>
#include <climits>
using namespace std;
int n,m;
int arr[6][6];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool in_range(int i,int j){
    return i<n && j<m;
}

int getSum(int x, int y, int w, int h){
    int curr = 0;
    for(int i=x; i<=x+h; i++){
        for(int j=y; j<=y+w; j++)
            curr += arr[i][j];
    }
    return curr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            for(int k=0; k<m; k++){
                for(int l=0; l<n; l++){
                    if(!in_range(i+l, j+k)) continue;

                    for(int a=0; a<n; a++){
                        for(int b=0; b<m; b++){ // 0,0,2,3 / 1,3

                            for(int c=0; c<m; c++){
                                for(int d=0; d<n; d++){
                                    if(!in_range(a+d, b+c)) continue;
                                    if(i+l < a  || j+k < b){
                                        ans = max(ans, getSum(i,j,k,l) + getSum(a,b,c,d));
                                    }
                                }
                            }
                        }
                    }
                    
                }
            }
        }
    }// 6 5 3 -4 6 1 + 20
    cout << ans;
    return 0;
}