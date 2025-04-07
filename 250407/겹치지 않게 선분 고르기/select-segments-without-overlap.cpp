#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[15];
vector<pair<int, int>> v;
vector<pair<int, int>> u;
int result = 0;

bool is_visited(int x1, int x2) {
    for (int j = x1; j <= x2; j++) 
        if (visited[j])
            return true;

    return false;
}

void visit(int x1, int x2) {
    for (int j = x1; j <= x2; j++) 
        visited[j] = true;
}

void cancel_visit(int x1, int x2) {
    for (int j = x1; j <= x2; j++) 
        visited[j] = false;
}

void func(int curr, int num) {
    if (curr >= v.size()){
        result = max(result, num);
        return; 
    }
    for (int i = curr; i < v.size(); i++) {
        int x1 = v[i].first;
        int x2 = v[i].second;
        if (is_visited(x1, x2)) {
            func(curr + 1, num); 
        }
        else {
            visit(x1, x2);
            func(curr + 1, num + 1);
            cancel_visit(x1, x2);
        }
    }
}

int main() {
    cin >> n;
    int x1, x2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        v.push_back({x1, x2});
    }
    func(0,0);
    cout << result;
    return 0;
}
