n, m = map(int, input().split())
grid = [[0] * (n + 1 ) for _ in range(n + 1)]
storage = [0] * (n * n + 1)

for i in range(1, n + 1):
    grid[i] = [0] + list(map(int, input().split()))
    for j in range(1, n + 1):
        storage[grid[i][j]] = (i, j)

# Please write your code here.
directions = ((-1, -1), (-1 , 0), (-1, 1), (0, 1), (1, 1),
                 (1, 0),(1, -1), (0, -1))

def in_range(x ,y):
    return 1 <= x <= n and 1 <= y <= n

def change_num(x, y):
    target_x = x
    target_y = y
    target_val = 0
    for i in range(8):
        nx = x + directions[i][0]
        ny = y + directions[i][1]
        if not in_range(nx, ny):
            continue
        if target_val < grid[nx][ny]:
            target_val = grid[nx][ny]
            target_x = nx
            target_y = ny
    return target_x, target_y


while(m):
    m -= 1
    for value in range(1, n * n + 1):
        cx, cy = storage[value]
        nx, ny = change_num(cx, cy)
        storage[grid[nx][ny]] = (cx, cy)
        storage[grid[cx][cy]] = (nx, ny)
        grid[cx][cy], grid[nx][ny] = grid[nx][ny], grid[cx][cy]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        print(grid[i][j], end = " ")
    print()