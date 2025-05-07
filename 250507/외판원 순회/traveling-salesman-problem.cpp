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
    if (curr > 4) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += A[ v[i - 1] ][ v[i] ];
        }
        sum += A[v[n - 1]][1];
        result = min(result, sum);
        return;
        }
    
    for (int i = 2; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        func(curr + 1);
        v.pop_back();
        visited[i]= false;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
    v.push_back(1);
    visited[1] = true;
    func(2);
    cout << result;

    return 0;
}
