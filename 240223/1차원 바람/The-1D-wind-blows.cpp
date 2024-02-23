#include <iostream>
using namespace std;
int arr[101][101];
int n,m,q,f;
void left(int index){
    int tmp = arr[index][0];
    for(int i=0; i<m-1; i++){
        arr[index][i] =arr[index][i+1];
    }
    arr[index][m-1] = tmp;
}
void right(int index){
    int tmp = arr[index][m-1];
    for(int i=m-1; i>0; i--){
        arr[index][i] = arr[index][i-1];
    }
    arr[index][0] = tmp;
}
void up(int index, char d){
    if(index == -1) return;
    bool check = 0;
    for(int i=0; i<m; i++){
        if(arr[index][i] == arr[index+1][i]){
            check = 1;
        }
    }
    if(check){
        if(d=='L'){
            left(index);
            up(index-1, 'R');
        }else{
            right(index);
            up(index-1, 'L');
        }
    }else{
        return;
    }
}

void down(int index, char d){
    if(index == n) return;
    bool check = 0;
    for(int i=0; i<m; i++){
        if(arr[index][i] == arr[index-1][i]){
            check = 1;
        }
    }
    if(check){
        if(d=='L'){
            left(index);
            down(index+1, 'R');
        }else{
            right(index);
            down(index+1, 'L');
        }
    }else{
        return;
    }
}
int main() {
    char d;
    cin >> n >> m >> q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

     while(q--){
         cin >> f >> d;
         int floor = f-1;
         if(d=='L'){
             right(floor);
         }else{
             left(floor);
         }
         up(floor-1,d);
         down(floor+1,d);
     }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}