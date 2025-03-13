#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];
void move(){
    int l_last = l[n-1];
    int r_last = r[n-1];
    int d_last = d[n-1];

    for (int i = n-2; i >= 0; i--){
        l[i+1] = l[i];
    }

    for (int i = n-2; i >= 0; i--){
        r[i+1] = r[i];
    }
    r[0] = l_last;
    for (int i = n-2; i >= 0; i--){
        d[i+1] = d[i];
    }
    d[0] = r_last;
    l[0] = d_last;
}
int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < t; i++) move();

    for (int i = 0; i < n; i++) cout << l[i] << ' ';

    cout << '\n';
    for (int i = 0; i < n; i++) cout << r[i] << ' ';

    cout << '\n';
    for (int i = 0; i < n; i++) cout << d[i] << ' ';

    return 0;
}
