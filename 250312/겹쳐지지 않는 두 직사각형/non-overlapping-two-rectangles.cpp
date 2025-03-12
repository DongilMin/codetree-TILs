#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int width;
int height;
int square[6][6];
int paper[6][6];

int result = INT_MIN;

void input() {
    cin >> height >> width;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cin >> square[i][j];
        }
    }
}

void reset_paper() {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            paper[i][j] = 0;
        }
    }
}

int get_space1(int y1, int x1, int height1, int width1) {
    int space1 = 0;
    for(int y = y1; y < y1 + height1; y++) {
        for(int x = x1; x < x1 + width1; x++) {
            space1 += square[y][x];
            paper[y][x] = 1;
        }
    }
    return space1;
}

int get_space2(int y2, int x2, int height2, int width2) {
    int space2 = 0;
    for(int y = y2; y < y2 + height2; y++) {
        for(int x = x2; x < x2 + width2; x++) {
            if(paper[y][x] == 1)
                return -9999;
            space2 += square[y][x];
        }
    }
    return space2;
}

void solve() {
    //space 1 시작 좌표
    int space1 = 0;
    int space2 = 0;
    for(int y1 = 0; y1 < height; y1++) {
        for(int x1 = 0; x1 < width; x1++) {

            //space 1 가로 세로
            for(int height1 = 1; y1 + height1 <= height; height1++) {
                for(int width1 = 1; x1 + width1 <= width; width1++) {
                    reset_paper();
                    space1 = get_space1(y1, x1, height1, width1);

                    //space2 시작 좌표
                    for(int y2 = 0; y2 < height; y2++) {
                        for(int x2 = 0; x2 < width; x2++) {

                            //space2 가로 세로
                            for(int height2 = 1; y2 + height2 <= height; height2++) {
                                for(int width2 = 1; x2 + width2 <= width; width2++) {
                                    space2 = get_space2(y2, x2, height2, width2);
                                    if (space2 == -9999)
                                        continue;
                                    result = max(result, space1 + space2);
                                }
                            }
                        }
                    }
                }
            }

        }
    }
}

int main() {
    input();
    solve();
    cout << result;
    return 0;
}