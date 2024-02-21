#include <iostream>
using namespace std;
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {0,-1,1,1,-1,-1,1,0};
char arr[51][51];
int r,c;
bool range(int i, int j){
    return i<=r && j<=c;
}
int main() {

    cin >> r >> c;
    int cnt = 0;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=r; i++){
        for(int j=0; j<=c; j++){
            if(arr[i][j] =='L'){
                for(int k=0; k<8; k++){
                    int curt = 1;
                    int curX = i;
                    int curY = j;
                    while(true){
                        int nx = curX + dx[k];
                        int ny = curY + dy[k];
                        if(!range(nx,ny)) break;
                        if(arr[nx][ny] != 'E') break;
                        curt++;
                        curX = nx;
                        curY = ny;
                    }
                    if(curt >= 3) cnt++;
                }
            }

        }
    }
    cout << cnt;
    return 0;
}