#include <iostream>

using namespace std;

int n, t;
int u[200];
int d[200];

void move(){
    int u_last = u[n-1];
    int d_last = d[n-1];
    for (int i = n-2; i >= 0; i--) {
        u[i+1] = u[i];
    }
    u[0] = d_last;
    for (int i = n-2; i >= 0; i--) {
        d[i+1] = d[i];
    }
    d[0] = u_last;
}
int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];

    for (int i = 0; i < n; i++) cin >> d[i];


    for (int i = 0; i < t; i++) {
        move();
    }

    for (int i = 0; i < n; i++) cout << u[i] << ' ';

    cout << '\n';

    for (int i = 0; i < n; i++) cout << d[i] << ' ';
    return 0;
}
