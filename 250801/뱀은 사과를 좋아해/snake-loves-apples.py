n, k, l = map(int, input().split())

grid = [[0] * (n + 1) for _ in range(n + 1)] # 보드
for _ in range(k):
    a, b = map(int,input().split()) # 사과의 위치(a, b)
    grid[a][b] = 3                 # 위치에 3넣어줌

info = []
for _ in range(l):
    d, p = input().split()   # 방향변환 정보
    info.append((d, int(p))) # 정보를 list에 저장

def in_range(x, y):
    return 1 <= x <= n and 1 <= y <= n

def get_dir(direction):
    if direction == 'R':
        return 0
    elif direction == 'D':
        return 1
    elif direction == 'L':
        return 2
    elif direction == 'U':
        return 3

x, y = 1, 1
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)] # R, D, L, U
time = 0
q = []
q.append((x, y))
curr_x = x
curr_y = y
grid[curr_x][curr_y] = 2
for mission in info:
    direction = get_dir(mission[0])
    dist = mission[1]
    for i in range (dist):
        time += 1
        nx = curr_x + directions[direction][0]
        ny = curr_y + directions[direction][1]
        if not in_range(nx, ny) or grid[nx][ny] == 1:
            print(time)
            exit()

        elif grid[nx][ny] == 3:
            grid[curr_x][curr_y] = 1
            grid[nx][ny] = 2
            q.insert(0, (nx, ny))

        else:
            tail = q.pop()
            grid[tail[0]][tail[1]] = 0
            grid[curr_x][curr_y] = 1
            grid[nx][ny] = 2
            q.insert(0, (nx, ny))  
        curr_x = nx
        curr_y = ny
print(time)