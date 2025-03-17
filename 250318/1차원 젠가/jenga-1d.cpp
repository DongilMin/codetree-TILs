#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int>blocks;
int s1, e1;
int s2, e2;

void rm_block(int s, int e) {
    
}

int main() {
    cin >> n;
    int block;

    for (int i = 0; i < n; i++) {
        cin >> block;
        blocks.push_back(block);
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;
    s1--;
    // 1 2 3 1 1 5 (2, 4) => ( 2,3,1)
    // 1 1 5, (2, 2) = > (1) 제거해야함
    blocks.erase(blocks.begin() + s1, blocks.begin() + e1);
    s2--;
    blocks.erase(blocks.begin() + s2, blocks.begin() + e2);

    cout << blocks.size() << '\n';
    for(int t : blocks) cout << t << '\n';
    return 0;
}
