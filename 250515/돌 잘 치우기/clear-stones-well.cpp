#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<vector<int>> grid;

// 방향 벡터
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

//— 1) 컴포넌트 라벨링 준비 —//
int compId[100][100];
int nComp = 0;
vector<int> compSize;

//— 2) 벽 셀 ID 매기기 —//
int wallId[100][100];
int nWall = 0;
vector<pair<int,int>> wallCells;          // wallId -> (x,y)
vector<vector<int>> compWalls;            // compWalls[c] = list of wallId 인접
vector<vector<int>> wallComps;            // wallComps[w] = list of compId 인접

//— 3) 그리드에서 0-셀 컴포넌트와 벽/컴포넌트 인접 리스트를 구축 —//
void buildComponents() {
    // 초기화
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        compId[i][j] = -1;
    }
    // 2-1) wallId 붙이기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1){
                wallId[i][j] = nWall++;
                wallCells.emplace_back(i,j);
            } else {
                wallId[i][j] = -1;
            }
        }
    }
    // 2-2) 0-셀 컴포넌트 BFS
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0 && compId[i][j]==-1){
                queue<pair<int,int>> q;
                q.emplace(i,j);
                compId[i][j] = nComp;
                compSize.push_back(0);

                while(!q.empty()){
                    auto [x,y] = q.front(); q.pop();
                    compSize[nComp]++;
                    for(int d=0;d<4;d++){
                        int nx=x+dx[d], ny=y+dy[d];
                        if(nx>=0 && nx<n && ny>=0 && ny<n
                           && grid[nx][ny]==0
                           && compId[nx][ny]==-1) {
                            compId[nx][ny] = nComp;
                            q.emplace(nx,ny);
                        }
                    }
                }
                nComp++;
            }
        }
    }
    // 2-3) compWalls & wallComps 채우기
    compWalls.assign(nComp, {});
    wallComps.assign(nWall, {});
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                int c = compId[i][j];
                for(int d=0;d<4;d++){
                    int ni=i+dx[d], nj=j+dy[d];
                    if(ni>=0 && ni<n && nj>=0 && nj<n
                       && grid[ni][nj]==1) {
                        int w = wallId[ni][nj];
                        compWalls[c].push_back(w);
                    }
                }
            }
        }
    }
    // 중복 제거 + wallComps 역구축
    for(int c=0;c<nComp;c++){
        auto &v = compWalls[c];
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(int w: v){
            wallComps[w].push_back(c);
        }
    }
}

//— 4) 재귀 탐색으로 최대 영역 찾기 —//
long long bestRegion;

void dfs(int rem, int lastWall,
         vector<char> &compVis,
         long long curSize,
         vector<int> &boundary)
{
    // 현재까지 영역 크기 갱신
    bestRegion = max(bestRegion, curSize);

    if(rem == 0) return;

    // 경계 벽 하나씩 골라서 부수기
    for(int w: boundary){
        if(w <= lastWall) continue;  // 중복 조합 방지

        // 이 벽을 부수면 붙는 컴포넌트
        vector<int> newly;
        for(int c: wallComps[w]){
            if(!compVis[c]){
                newly.push_back(c);
                compVis[c] = 1;
            }
        }
        // 부순 벽 셀 자체도 영역에 추가되므로 +1
        long long nextSize = curSize + 1;
        for(int c: newly) nextSize += compSize[c];

        // 다음 경계 갱신: 
        //   1) 기존 경계 + 2) 새로 연결된 컴포넌트의 compWalls + 
        //   3) 방금 부순 셀 주변(벽) 
        vector<int> nextBoundary = boundary;
        for(int c: newly){
            for(int w2: compWalls[c])
                nextBoundary.push_back(w2);
        }
        auto [bx,by] = wallCells[w];
        for(int d=0;d<4;d++){
            int nx=bx+dx[d], ny=by+dy[d];
            if(nx>=0 && nx<n && ny>=0 && ny<n
               && grid[nx][ny]==1)
                nextBoundary.push_back(wallId[nx][ny]);
        }
        // 중복 제거
        sort(nextBoundary.begin(), nextBoundary.end());
        nextBoundary.erase(unique(nextBoundary.begin(), nextBoundary.end()),
                           nextBoundary.end());

        dfs(rem-1, w, compVis, nextSize, nextBoundary);

        // 복귀 시 마킹 해제
        for(int c: newly)
            compVis[c] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> m;
    grid.assign(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> grid[i][j];

    vector<pair<int,int>> starts(k);
    for(int i=0;i<k;i++){
        int r,c;
        cin >> r >> c;
        starts[i] = {r-1, c-1};
    }

    // 컴포넌트 + 인접 정보 구축
    buildComponents();

    long long answer = 0;
    // 각 시작점마다
    for(auto &st: starts){
        auto [sx,sy] = st;
        if(sx<0||sx>=n||sy<0||sy>=n) continue;
        if(grid[sx][sy] == 1){
            // 시작점이 벽인 경우는 문제 조건에 따라 별도 처리...
            continue;
        }
        int startComp = compId[sx][sy];

        // 방문 마크 초기화
        vector<char> compVis(nComp, 0);
        compVis[startComp] = 1;

        // 초기 영역 크기 = 해당 컴포넌트 크기
        long long initSize = compSize[startComp];

        // 초기 경계 벽
        vector<int> boundary = compWalls[startComp];

        bestRegion = initSize;
        dfs(m, -1, compVis, initSize, boundary);

        answer = max(answer, bestRegion);
    }

    cout << answer << "\n";
    return 0;
}
