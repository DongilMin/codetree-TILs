#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int main() {
    cin >> N;

    int table[1000000];
    for (int i = 0; i <= N + 1; i++) table[i] = INT_MAX;
    table[N] = 0;
    queue<int> q;
    q.push(N);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr < N + 4) {
            if (table[curr + 1] > table[curr] + 1) {
                table[curr + 1] = table[curr] + 1;
                if (curr + 1 > 0) q.push(curr + 1);
            }
        }
        if (curr % 2 == 0) {
            if (table[curr / 2] > table[curr] + 1) {
                table[curr / 2] = table[curr] + 1;
                if (curr / 2 > 0) q.push(curr / 2);
            }
        }
        if (curr % 3 == 0) {
            if (table[curr / 3] > table[curr] + 1) {
                table[curr / 3] = table[curr] + 1;
                if (curr / 3 > 0) q.push(curr / 3);
            }
        }
        if (table[curr - 1] > table[curr] + 1) {
            table[curr - 1] = table[curr] + 1;
            if (curr > 1) q.push(curr - 1);
        }
    }
    cout << table[1];
    return 0;
}
