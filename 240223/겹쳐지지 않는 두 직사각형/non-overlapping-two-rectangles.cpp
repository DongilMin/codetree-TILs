#include <iostream>
#include <climits>
using namespace std;
int n,m;
int arr[6][6];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool in_range(int i,int j){
    return i>=0 && i<n && j>=0 && j<m;
}

int solve(int x, int y, int row, int col){
    int sum = arr[x][y];
    int cx = row;
    int cy = col;

    for(int i=1; i<row; i++){
        cx += dx[0];
        cy += dy[0];
        if(in_range(cx,cy)){
            sum+=arr[cx][cy];
        }else{
            return -10000;
        }
    }

    for(int i=1; i<col; i++){
        cx += dx[1];
        cy += dy[1];
        if(in_range(cx,cy)){
            sum+=arr[cx][cy];
        }else{
            return -10000;
        }
    }

    for(int i=1; i<row; i++){
        cx += dx[2];
        cy += dy[2];
        if(in_range(cx,cy)){
            sum+=arr[cx][cy];
        }else{
            return -10000;
        }
    }

    for(int i=1; i<row; i++){
        cx += dx[3];
        cy += dy[3];
        if(in_range(cx,cy)){
            sum+=arr[cx][cy];
        }else{
            return -10000;
        }
    }
    return sum;
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            for(int k=1; k<n; k++){
                for(int l=1; l<m; l++){

                    int sum = solve(i,j,k,l);

                    for(int a=0; a<n; a++){
                        for(int b=0; b<m; b++){ // 0,0,2,3 / 1,3
                            if(abs(a-i) < k && (b-j) < l) continue;

                            for(int c=1; c<n; c++){
                                for(int d=1; d<n; d++){
                                    ans = max(ans, sum+solve(a,b,c,d));
                                }
                            }
                        }
                    }
                    
                }
            }
        }
    }
    cout << ans;
    return 0;
}