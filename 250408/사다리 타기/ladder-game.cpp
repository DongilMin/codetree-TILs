#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> v;
vector<pair<int, int>> selected;
bool visited[16][16] = {0};

int ans = 65535;

bool possible() {

    int origin[ans];
    int subject[ans];
    for (int i = 0; i <= n; i++) {
        origin[i] = subject[i] = i;
    }

	for(int i = 0; i < (int) v.size(); i++) {
		int idx = v[i].second;
		swap(origin[idx], origin[idx + 1]);
	}

	for(int i = 0; i < (int) selected.size(); i++) {
		int idx = selected[i].second;
		swap(subject[idx], subject[idx + 1]);
	}

    for (int i = 1; i <= n; i++) {
        if (origin[i] != subject[i]) return false;
    }
    return true;
}

void sibal(int index) {
    if (index == m) {
        if(possible()) {
            int count = selected.size();
            ans = min(ans, count);
        }
        return;
    }
    selected.push_back(v[index]);
    sibal(index + 1);
    selected.pop_back();
    sibal(index + 1);
}

int main() {
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());

    sibal(0);
    
    cout << ans;

    return 0;
}
