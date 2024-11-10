#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // 카데인 알고리즘을 적용
    int max_sum = A[0]; // 최대 합 초기화
    int current_sum = A[0]; // 현재 합 초기화

    for (int i = 1; i < n; ++i) {
        current_sum = max(A[i], current_sum + A[i]); // 현재 합 업데이트
        max_sum = max(max_sum, current_sum); // 최대 합 업데이트
    }

    cout << max_sum << endl; // 결과 출력
    return 0;
}