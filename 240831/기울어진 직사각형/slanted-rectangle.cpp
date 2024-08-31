#include <iostream>
using namespace std;

int n;
int board[21][21];
int d1[2] = {-1,1};
int d2[2] = {-1,-1};
int d3[2] = {1,-1};
int d4[2] = {1,1};
int result = 0;

int func(){

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){

            for(int row_len=1; row_len < n; row_len++){
                for(int col_len=1; col_len < n; col_len++){
                    
                    int x1 = i+row_len*d1[0], y1 = j+row_len*d1[1];
                    int x2 = x1+col_len*d2[0], y2 = y1+col_len*d2[1];
                    int x3 = x2+row_len*d3[0], y3 = y2+row_len*d3[1];
                    int x4 = x3+col_len*d4[0], y4 = y3+col_len*d4[1];

                    if( x1 < 1 || x1 > n || y1 < 1 || y1 > n ||
                        x2 < 1 || x2 > n || y2 < 1 || y2 > n ||
                        x3 < 1 || x3 > n || y3 < 1 || y3 > n ||
                        x4 < 1 || x4 > n || y4 < 1 || y4 > n
                    ) continue;

                    int max_sum = 0;

                    for(int k=0; k<row_len; k++)
                        max_sum += board[i+k*d1[0]][j+k*d1[1]];
                    
                    for(int k=0; k<col_len; k++)
                        max_sum += board[x1+k*d2[0]][y1+k*d2[1]];
                    
                    for(int k=0; k<row_len; k++)
                        max_sum += board[x2+k*d3[0]][y2+k*d3[1]];
                    
                    for(int k=0; k<col_len; k++)
                        max_sum += board[x3+k*d4[0]][y3+k*d4[1]];
                    
                    if(max_sum > result) result = max_sum;
                }
            }
        }
    }
    return result;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }

    cout << func() <<'\n';
}