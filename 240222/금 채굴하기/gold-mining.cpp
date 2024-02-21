#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int arr[50][50]={0};
int n,m;
int ans = 0;
int getArea(int k){
    return k*k+(k+1)*(k+1);
}
int getGold(int row, int col, int k){
    int gold = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(abs(row-i) + abs(col-j) <= k)
                gold += arr[i][j];
        }
    }
    return gold;
}
int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<=2*(n-1); k++){
                int num_of_gold = getGold(i,j,k);
                if(num_of_gold * m >= getArea(k)){
                    ans = max(ans, num_of_gold);
                }
            }
        }
    }
    cout << ans;

    return 0;
}
// 2 >2
// 3 >4
// 4 >6
// 5 >8