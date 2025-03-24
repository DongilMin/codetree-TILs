#include <iostream>

using namespace std;

int grid[101][101] = {0};
int n, m, r, c;

bool in_range(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}
struct Dice {
    int top, bottom, left, right, front, back;

    Dice(int t, int b, int l, int ri, int f, int ba){
        this->top = t;
        this->bottom = b;
        this->left = l;
        this->right = ri;
        this->front = f;
        this->back = ba;
    }
    
    void rollNorth(int x, int y) {
        int nx = x - 1;
        int ny = y;
        if(!in_range(nx,ny)) return;
        int temp = top;
        top = front;
        front = bottom;
        bottom = back;
        back = temp;
        r = nx;
        c = ny;
        //cout << "next r && c == " << r << ' ' << c << '\n';
        //cout << "new bottom : " << bottom << '\n';
    }

    void rollSouth(int x, int y) {
        int nx = x + 1;
        int ny = y;
        if(!in_range(nx,ny)) return;
        int temp = top;
        top = back;
        back = bottom;
        bottom = front;
        front = temp;
        r = nx;
        c = ny;
        //cout << "next r && c == " << r << ' ' << c << '\n';
        //cout << "new bottom : " << bottom << '\n';
    }

    void rollWest(int x,int y) {
        int nx = x;
        int ny = y - 1;
        if(!in_range(nx,ny)) return;
        int temp = top;
        top = right;
        right = bottom;
        bottom = left;
        left = temp;
        r = nx;
        c = ny;
        //cout << "next r && c == " << r << ' ' << c << '\n';
        //cout << "new bottom : " << bottom << '\n';
    }

    void rollEast(int x,int y) {
        int nx = x;
        int ny = y + 1;
        if(!in_range(nx,ny)) return;
        int temp = top;
        top = left;
        left = bottom;
        bottom = right;
        right = temp;
        r = nx;
        c = ny;
        //cout << "next r && c == " << r << ' ' << c << '\n';
        //cout << "new bottom : " << bottom << '\n';
    }
    
    void print() {
        cout << "Top: " << top << ", Bottom: " << bottom << endl;
        cout << "Left: " << left << ", Right: " << right << endl;
        cout << "Front: " << front << ", Back: " << back << endl;
    }
};
Dice dice(1,6,4,3,2,5);

void stamp() {
    grid[r][c] = dice.bottom;
    //cout << r << " and " << c << " was stamped : " << grid[r][c] << '\n';
}


int main() {

    cin >> n >> m >> r >> c;

    char a;
    while (m--) {
        cin >> a;
        stamp();

        if (a == 'L') dice.rollWest(r,c);
        else if (a == 'R') dice.rollEast(r,c);
        else if (a == 'U') dice.rollNorth(r,c);
        else if (a == 'D') dice.rollSouth(r,c);
    }
    stamp();

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += grid[i][j];
        }
    }
    cout << sum << '\n';
}