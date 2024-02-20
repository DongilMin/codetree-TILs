#include <iostream>
using namespace std;
int main() {
    string s;
    int cnt = 0;
    cin >> s;
    for(int i=1; i<s.size(); i++){
        if(s[i] == '(' && s[i-1] == '('){
            for(int j=i+2; j<s.size(); j++){
                if(s[j-1] == ')' && s[j] == ')') cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}