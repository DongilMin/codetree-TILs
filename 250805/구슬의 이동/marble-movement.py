import sys
input = sys.stdin.readline

# 변수 선언 및 입력
n, m, t, k = map(int, input().split())
# 현재 그리드와 다음 턴용 그리드 초기화 (n x n)
grid = [[[] for _ in range(n)] for _ in range(n)]
next_grid = [[[] for _ in range(n)] for _ in range(n)]

# 범위 체크 함수
def in_range(x, y):
    return 0 <= x < n and 0 <= y < n

# 구슬의 다음 위치 계산 함수
# vnum: 이동 칸 수, move_dir: 0:U,1:R,2:L,3:D 순서
def next_pos(x, y, vnum, move_dir):
    dxs = [-1, 0, 0, 1]
    dys = [0, 1, -1, 0]
    for _ in range(vnum):
        nx = x + dxs[move_dir]
        ny = y + dys[move_dir]
        # 벽에 부딪히면 반대 방향으로 바꾸고 이동
        if not in_range(nx, ny):
            move_dir = 3 - move_dir
            nx = x + dxs[move_dir]
            ny = y + dys[move_dir]
        x, y = nx, ny
    return x, y, move_dir

# 모든 구슬을 한 번에 이동시키기
def move_all():
    for i in range(n):
        for j in range(n):
            for v, num, d in grid[i][j]:
                nx, ny, nd = next_pos(i, j, v, d)
                next_grid[nx][ny].append((v, num, nd))

# 한 칸에 모인 구슬 수를 k개로 제한
def select_marbles():
    for i in range(n):
        for j in range(n):
            if len(next_grid[i][j]) > k:
                # 속도(v), 번호(num) 내림차순
                next_grid[i][j].sort(key=lambda x: (-x[0], -x[1]))
                while len(next_grid[i][j]) > k:
                    next_grid[i][j].pop()

# 시뮬레이션 한 단계
def simulate():
    # next_grid 초기화
    for i in range(n):
        for j in range(n):
            next_grid[i][j].clear()
    # 이동
    move_all()
    # k개만 남김
    select_marbles()
    # next_grid -> grid
    for i in range(n):
        for j in range(n):
            grid[i][j] = next_grid[i][j][:]

# 방향 매핑
dir_mapper = {"U": 0, "R": 1, "L": 2, "D": 3}

# 초기 구슬 정보 입력
for idx in range(m):
    r, c, d, v = input().split()
    r, c, v = int(r) - 1, int(c) - 1, int(v)
    grid[r][c].append((v, idx + 1, dir_mapper[d]))

# t번 시뮬레이션 실행
for _ in range(t):
    simulate()

# 결과 계산 및 출력
ans = sum(len(grid[i][j]) for i in range(n) for j in range(n))
print(ans)