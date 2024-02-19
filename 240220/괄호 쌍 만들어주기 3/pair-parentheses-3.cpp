#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <stack>
using namespace std;
int main() {
    string str;
    stack<char>s;
    cin >> str;
    int cnt = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '('){
            for(int j=i+1; j<str.length(); j++){
                if(str[j] == ')') cnt++;
            }
        }
    }
    cout << cnt;
}