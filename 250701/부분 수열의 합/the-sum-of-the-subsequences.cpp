#include <iostream>

using namespace std;

int n, m;
int A[100];
bool dp[10000];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) dp[i] = false;

    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = m; j > 0; j--) {
            if (j >= A[i]) {
                if (dp[j - A[i]])
                    dp[j] = true;
            }
        }
    }
    if (dp[m]) cout << "Yes";
    else cout << "No";
    return 0;
}
