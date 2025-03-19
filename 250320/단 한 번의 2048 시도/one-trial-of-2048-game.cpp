#include <iostream>
using namespace std;

const int n = 4;  
int grid[n][n];

void LeftCombine(){
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n - 1; col++){
            if(grid[row][col] == grid[row][col + 1]){
                grid[row][col] *= 2;
                grid[row][col + 1] = 0;
            }
        }
    }  
}

void RightCombine(){
    for(int row = 0; row < n; row++){
        for(int col = n - 1; col > 0; col--){
            if(grid[row][col] == grid[row][col - 1]){
                grid[row][col] *= 2;
                grid[row][col - 1] = 0;
            }
        }
    }
}

void UpCombine(){
    for(int col = 0; col < n; col++){
        for(int row = 0; row < n - 1; row++){
            if(grid[row][col] == grid[row + 1][col]){
                grid[row][col] *= 2;
                grid[row + 1][col] = 0;
            }
        }
    }
}

void DownCombine(){
    for(int col = 0; col < n; col++){
        for(int row = n - 1; row > 0; row--){
            if(grid[row][col] == grid[row - 1][col]){
                grid[row][col] *= 2;
                grid[row - 1][col] = 0;
            }
        }
    }
}

void Combine(char d){
    if(d == 'L') 
        LeftCombine();
    else if(d == 'R') 
        RightCombine();
    else if(d == 'U') 
        UpCombine();
    else if(d == 'D') 
        DownCombine();
}

void move_up_down(int col, char dir) {
    if (dir == 'D') {
        int end_of_array = 0;
        int temp[n] = {0};

        for (int i = 0; i < n; i++) {
            if (grid[i][col] != 0) {
                temp[end_of_array] = grid[i][col];
                end_of_array++;
            }
        } 

        int index = n - 1;
        for (int i = end_of_array - 1; i >= 0; i--) {
            grid[index][col] = temp[i];
            index--;
        }

        while (index >= 0) {
            grid[index][col] = 0;
            index--;
        }
    }
    else {  
        int end_of_array = 0;
        int temp[n] = {0};

        for (int i = 0; i < n; i++) {
            if (grid[i][col] != 0) {
                temp[end_of_array] = grid[i][col];
                end_of_array++;
            }
        } 

        int index = 0;
        for (int i = 0; i < end_of_array; i++) {
            grid[index][col] = temp[i];
            index++;
        }

        while (index < n) {
            grid[index][col] = 0;
            index++;
        }
    }
}

void move_left_right(int row, char dir) {
    if (dir == 'R') {
        int end_of_array = 0;
        int temp[n] = {0};  

        for (int i = 0; i < n; i++) {
            if (grid[row][i] != 0) {
                temp[end_of_array] = grid[row][i];
                end_of_array++;
            }
        } 

        int index = n - 1;
        for (int i = end_of_array - 1; i >= 0; i--) {
            grid[row][index] = temp[i];
            index--;
        }

        while (index >= 0) {
            grid[row][index] = 0;
            index--;
        }
    }
    else {
        int end_of_array = 0;
        int temp[n] = {0};

        for (int i = 0; i < n; i++) {
            if (grid[row][i] != 0) {
                temp[end_of_array] = grid[row][i];
                end_of_array++;
            }
        } 

        int index = 0;
        for (int i = 0; i < end_of_array; i++) {
            grid[row][index] = temp[i];
            index++;
        }

        while (index < n) {
            grid[row][index] = 0;
            index++;
        }
    }
}

void shift(char d){
    if (d == 'L' || d == 'R'){
        for (int i = 0; i < n; i++) {
            move_left_right(i, d);
        }
    }
    else if (d == 'U' || d == 'D') {
        for (int i = 0; i < n; i++) {
            move_up_down(i, d);
        }
    }
}

int main() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    char dir;
    cin >> dir;

    shift(dir);
    Combine(dir);
    shift(dir);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
