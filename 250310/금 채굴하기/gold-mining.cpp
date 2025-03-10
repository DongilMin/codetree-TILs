#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, m;
int grid[20][20];

int calc(int x, int y, int k) {
	int cnt = 0;
	
	for (int i = -k; i <= k; i++) {
		for (int j = -k; j <= k; j++) {
			if (abs(i) + abs(j) <= k) {
				int x_new = x + i;
				int y_new = y + j;
                if( x_new < 0 || x_new >= n || y_new < 0 || y_new >= n) continue;
				if (grid[x_new][y_new]) cnt++;
			}
		}
	}
    if(k*k + (k+1)*(k+1) <= cnt*m) return cnt;
    else return 0;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int k;
    if (n>2) k = (n-1)/2;
    else k = 0;
    
    int result = 0 ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l <=n; l++){
                result = max(result, calc(i,j,l));
            }
        }
    }
    cout << result << '\n';
    return 0;
}
