#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n;
int A[11][11];
bool visited[11];
int result = INT_MAX;
vector<int> v;

void func(int curr) {
    if (v.size() == n - 1) { // n = 4
        int sum = 0;
        int prev = 1; // 출발점(1번 행)
        bool invalid = false;

        // 경로 비용 합계
        for (int city : v) {
            if (A[prev][city] == 0) {
                invalid = true; // 길 없음
                break;
            }
            sum += A[prev][city];
            prev = city;
        }

        // 마지막 도시에서 출발지(1번)로 돌아오는 비용
        if (!invalid && A[prev][1] != 0) {
            sum += A[prev][1];
            result = min(result, sum);
        }

        return;
    }

    for (int i = 2; i <= n; i++) { // 도시 2~n 선택
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        func(curr + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
    func(1);
    cout << result;

    return 0;
}
