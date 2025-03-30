#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_GRID (4002) //(가중치 * 2 + 1 + 가중치 * 2)
// 좌표 변환에 대한 일반화 필요
#define ASCII_NUM 128
#define OFF_SET 1000
#define DIR_NUM 4
using namespace std;

int last_t;
int dir_mapper[ASCII_NUM];

vector<tuple<int, int, int>> grid[MAX_GRID][MAX_GRID];
vector<tuple<int, int, int>> next_grid[MAX_GRID][MAX_GRID];

bool InGrid(int x, int y)
{
    return x >= 0 && x < MAX_GRID && y >= 0 && y < MAX_GRID;
}
tuple<int, int, int> GetPosInfo(int x, int y)
{
    int weight = get<0>(grid[x][y][0]);
    int num = get<1>(grid[x][y][0]);
    int dir = get<2>(grid[x][y][0]);
    return make_tuple(weight, num, dir);
}

void MoveAll()
{
    int dx[DIR_NUM] = { -1, 0, 0, 1 };
    int dy[DIR_NUM] = { 0, 1, -1, 0 };
    for (int i = 0; i < MAX_GRID; i++)
    {
        for (int j = 0; j < MAX_GRID; j++)
        {
            if (!grid[i][j].empty())
            {
                int next_w, next_num, next_dir;
                tie(next_w, next_num, next_dir) = GetPosInfo(i, j);
                int nx = i + dx[next_dir];
                int ny = j + dy[next_dir];
                if(InGrid(nx, ny))
                    next_grid[nx][ny].push_back(make_tuple(next_w, next_num, next_dir));
            }
        }
    }
}

void SelectMarbles(int time)
{
    for (int i = 0; i < MAX_GRID; i++) {
        for (int j = 0; j < MAX_GRID; j++)
        {
            if (next_grid[i][j].size() > 1) {
                sort(next_grid[i][j].begin(), next_grid[i][j].end());
                last_t = time;
                while (next_grid[i][j].size() > 1) // 실수 주의!
                {
                    next_grid[i][j].pop_back();
                }
            }
        }
    }
}

void Simulate(int time)
{
    // Step1. next_grid를 초기화
    for (int i = 0; i < MAX_GRID; i++)
        for (int j = 0; j < MAX_GRID; j++)
            next_grid[i][j].clear();

    // Step2. Move All
    MoveAll();
    // Step3. SelectMarbles - 충돌 여부 판별 및 구슬 내림차순으로 정렬 후 가장 적합한 구슬만 남음.
    SelectMarbles(time);
    // next_grid 값을 grid 값으로 옮긴다.
    for (int i = 0; i < MAX_GRID; i++)
        for (int j = 0; j < MAX_GRID; j++)
            grid[i][j] = next_grid[i][j];

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    dir_mapper['U'] = 0;
    dir_mapper['R'] = 1;
    dir_mapper['L'] = 2;
    dir_mapper['D'] = 3;
    int t; // test case 개수
    cin >> t;
    while (t--) {
        // 새로운 테스트 케이스가 시작될 때마다 기존에 사용하던 값들을 초기화해줍니다.
        last_t = -1;

        for (int i = 0; i < MAX_GRID; i++)
            for (int j = 0; j < MAX_GRID; j++)
                grid[i][j].clear();

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y, w;
            char d;
            cin >> x >> y >> w >> d;
            // 2초에 1칸 움직이는 것을 편의상 2초에 2칸으로 뻥튀기 되게끔 좌표 변환
            // 좌표 변환 더블 체크 바람
            grid[2 * (x + OFF_SET)][2 * (y + OFF_SET)].push_back(make_tuple(-w, -(i + 1), dir_mapper[d]));
            /* 무게가 가장 크거나, 무게가 같은 구슬이 여러 개일 경우 구슬의 번호가 크게끔 */
            /* -4,-3,-2,-1 => 즉, 4,3,2,1 내림차순의 인버스가 되도록
             * - 부호를 붙인다! */
        }

        // 시뮬레이션 총 2초*n번 진행
        // 1초 단위로 처리하게끔 위에서 좌표 변환!
        for (int time = 1; time <= 2 * n; time++) {
            Simulate(time);
        }
        // 출력 :
        cout << last_t << "\n";

    }
    return 0;
}