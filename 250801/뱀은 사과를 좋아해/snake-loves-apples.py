n, m, k = map(int, input().split())

grid = [[0] * n for _ in range(n)]  # 0-indexed 그리드
for _ in range(m):
    a, b = map(int, input().split())  # 사과의 위치(a, b) - 1-indexed로 입력
    grid[a-1][b-1] = 3  # 0-indexed로 변환하여 저장

info = []
for _ in range(k):
    d, p = input().split()  # 방향변환 정보
    info.append((d, int(p)))  # 정보를 list에 저장

def in_range(x, y):
    return 0 <= x < n and 0 <= y < n  # 0-indexed 범위 체크

def get_dir(direction):
    if direction == 'L':  # 왼쪽
        return 0
    elif direction == 'U':  # 위
        return 1
    elif direction == 'R':  # 오른쪽
        return 2
    elif direction == 'D':  # 아래
        return 3

# 시작 위치 (0, 0) - 0-indexed
x, y = 0, 0
# 좌(0,-1) 상(-1,0) 우(0,1) 하(1,0) - C++ 코드와 동일
directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]  # L, U, R, D
time = 0
body_pos = []  # 몸통 위치들
grid[x][y] = 2  # HEAD

for mission in info:
    direction = get_dir(mission[0])
    dist = mission[1]
    
    for i in range(dist):
        time += 1
        nx = x + directions[direction][0]
        ny = y + directions[direction][1]
        
        # 격자를 벗어난 경우
        if not in_range(nx, ny):
            print(time)
            exit()
        
        # 사과를 먹은 경우
        if grid[nx][ny] == 3:
            body_pos.append((x, y))
            grid[x][y] = 1  # BODY
            x = nx
            y = ny
            grid[x][y] = 2  # HEAD
        
        # 머리만 있는 경우
        elif len(body_pos) == 0:
            grid[x][y] = 0
            x = nx
            y = ny
            grid[x][y] = 2  # HEAD
        
        # 일반 이동 (몸통+머리)
        else:
            # 가장 뒤 몸통 제거
            tail_x, tail_y = body_pos[0]
            grid[tail_x][tail_y] = 0
            
            # 몸통 이동
            for j in range(len(body_pos) - 1):
                body_pos[j] = body_pos[j + 1]
            body_pos[-1] = (x, y)
            grid[x][y] = 1  # BODY
            
            # 몸통이 꼬이는지 확인 (nx, ny가 body_pos에 있으면 안 됨)
            is_collision = False
            for bx, by in body_pos:
                if bx == nx and by == ny:
                    is_collision = True
                    break
            
            if is_collision:
                print(time)
                exit()
            
            x = nx
            y = ny
            grid[x][y] = 2  # HEAD

print(time)