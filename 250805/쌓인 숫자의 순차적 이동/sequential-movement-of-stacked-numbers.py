n, m = map(int, input().split())
grid = [[[] for _ in range(n + 1)] for _ in range(n + 1)]

# 격자 입력 받기
for i in range(1, n + 1):
    row = list(map(int, input().split()))
    for j in range(1, n + 1):
        grid[i][j].append(row[j - 1])

# 이동할 숫자 리스트
move_nums = list(map(int, input().split()))

# 8방향 (중복 수정)
dirs = [(-1, -1), (-1, 0), (-1, 1),
        (0, 1),  (1, 1),  (1, 0),
        (1, -1), (0, -1)]

def in_range(x, y):
    return 1 <= x <= n and 1 <= y <= n

def get_pos(move_num):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if move_num in grid[i][j]:
                return (i, j)

for move_num in move_nums:
    cx, cy = get_pos(move_num)

    max_num = -1
    next_x = -1
    next_y = -1

    for dx, dy in dirs:
        nx, ny = cx + dx, cy + dy
        if not in_range(nx, ny):
            continue

        # 해당 위치에 값이 있다면 비교
        if grid[nx][ny]:
            candidate = max(grid[nx][ny])  # 가장 큰 값
            if candidate > max_num:
                max_num = candidate
                next_x = nx
                next_y = ny

    # 만약 이동할 곳이 있다면
    if next_x != -1 and next_y != -1:
        start_idx = grid[cx][cy].index(move_num)
        # start_idx부터 끝까지 이동
        moving = grid[cx][cy][start_idx:]
        grid[cx][cy] = grid[cx][cy][:start_idx]
        grid[next_x][next_y].extend(moving)

# 출력
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if not grid[i][j]:
            print("None")
        else:
            print(*reversed(grid[i][j]))
