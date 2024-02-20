#include <iostream>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'C'){
            for(int j=i+1; j<s.size(); j++){
                if(s[j] == 'O'){
                    for(int k=j+1; k<s.size(); k++){
                        if(s[k] == 'W'){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
}