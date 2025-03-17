#include <iostream>
#include <string>

using namespace std;

string A;

void right_shift() {

    int temp = A[A.length() - 1];
    for (int i = A.length() - 2; i >= 0; i--) {
        A[i + 1] = A[i];
    }
    A[0] = temp;
}
int main() {
    cin >> A;

    int result = 0;
    for (int i = 0; i < A.length(); i++) {
        right_shift();
        char prev_char = A[0];
        int cnt = 1;
        string b = "";
        bool all_same = true;
        for(int j = 1; j < A.length(); j++) {
            if (A[j] == prev_char) {
                cnt++;
            } //a5b3c1
            else {
                all_same = false;
                b += prev_char;
                b += to_string(cnt);
                prev_char = A[j];
                cnt = 0;

            }
        }
        if(all_same) {
            b += prev_char;
            b += to_string(cnt);
        }
        if( b.length() > result) {
            result = b.length();
        }
    }

    cout << result;
    return 0;
}
