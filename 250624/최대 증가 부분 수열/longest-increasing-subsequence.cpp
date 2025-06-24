#include <iostream>
#include <climits>
using namespace std;

int N;
int M[1000];
int dp[1000];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
        dp[i] = 1;
    }
    int result = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (M[i] > M[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
    }
    cout << result;
    return 0;
}
