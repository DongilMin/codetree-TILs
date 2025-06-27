#include <iostream>
#include <algorithm>
using namespace std;

int n;
int sequence[1000];
int dp1[1000];
int dp2[1000];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
        dp1[i] = dp2[i] = 1;
    }

    int result = 1;
    // 6 2 4 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);
            
            if (sequence[n - j - 1] < sequence[n - i - 1])
                dp2[n - i - 1] = max(dp2[n - i - 1], dp2[n - j - 1] + 1);
        }
        // if(i == 4) cout << dp1[i] << " and " << dp2[i] << '\n';
    }
    
    for (int i = 0; i < n; i++)
        result = max(result, dp1[i] + dp2[i] - 1);

    cout << result;
    return 0;
}
