
#include <iostream>

using namespace std;

int n, m;
int numbers[100];

void shift() {
    int end_of_array = 0;

    for (int i = 0; i < n; i++) {
        if(numbers[i] == 0) {
            end_of_array = i;
            break;
        }
    }

    for (int i = end_of_array; i < n; i++) {
        if (numbers[i] != 0) {
            numbers[end_of_array] = numbers[i];
            numbers[i] = 0;
            end_of_array++;
        }
    }

    n = end_of_array;
}

bool check() {
    bool fire = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if(numbers[i] == numbers[i-1]) cnt++;
        else cnt = 1;

        if(cnt >= m) {
            fire = 1;
            break;
        }
    }
    return fire;
}

void bomb() {
    while (true) {
        if (m == 1){
            n = 0;
            break;
        }

        if(!check()) break;

        int cnt = 1;
        int start_index = 0;
        for (int i = 1; i < n; i++) {
            if (numbers[i] == numbers[i - 1]) cnt++;
            else {
                cnt = 1;
                start_index = i;
            }

            if (cnt >= m) {
                int target = numbers[start_index];
                for (int j = start_index; j < n; j++) {
                    if (numbers[j] != target) break;
                    numbers[j] = 0;
                }
            }
        }

        shift();
    }
}
int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    bomb();

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << '\n';
    }

    return 0;
}