#include <iostream>

using namespace std;

int grid[4][4];

void LeftCombine(){
    for(int row=0; row<4; row++){
        for(int col=0; col<3; col++){
            if(arr[row][col]==arr[row][col+1]){
                arr[row][col]*=2;
                arr[row][col+1]=0;
            }
        }
    }  
}

void RightCombine(){
    for(int row=0; row<4; row++){
        for(int col=3; col>0; col--){
            if(arr[row][col]==arr[row][col-1]){
                arr[row][col]*=2;
                arr[row][col-1]=0;
            }
        }
    }
}

void UpCombine(){
    for(int col=0; col<4; col++){
        for(int row=0; row<3; row++){
            if(arr[row][col]==arr[row+1][col]){
                arr[row][col]*=2;
                arr[row+1][col]=0;
            }
        }
    }
}

void DownCombine(){
    for(int col=0; col<4; col++){
        for(int row=3; row>0; row--){
            if(arr[row][col]==arr[row-1][col]){
                arr[row][col]*=2;
                arr[row-1][col]=0;
            }
        }
    }
}

void Combine(){
    if(dir=='L') LeftCombine();
    else if(dir=='R') RightCombine();
    else if(dir=='U') UpCombine();
    else DownCombine();
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
            move_left_right(i,d);
        }
    }
    if (d == 'U' || d == 'D') {
        for (int i = 0; i < n; i++) {
            move_up_down(i,d);
        }
    }
}

int main() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    char dir;
    cin >> dir;

    Shift(dir);
    Combine();
    Shift(dir);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout <<'\n';
    }


    return 0;
}