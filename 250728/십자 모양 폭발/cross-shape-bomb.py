def in_range(x, y):
    return 0 <= x < n and 0 <= y < n

def fall(col):
    # 0이 아닌 블록만 모아서 아래에서부터 채움
    non_zero = [grid[i][col] for i in range(n) if grid[i][col] != 0]
    for i in range(n - 1, -1, -1):
        grid[i][col] = non_zero.pop() if non_zero else 0

def bomb(r, c):
    val = grid[r][c]
    for dist in range(val):
        for dx, dy in ((0,1), (1,0), (0,-1), (-1,0)):
            nx, ny = r + dx * dist, c + dy * dist
            if in_range(nx, ny):
                grid[nx][ny] = 0

    for j in range(n):
        if grid[r][j] == 0:
            fall(j)

# --- 실행부 ---
n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

r, c = map(lambda x: int(x)-1, input().split())  # 0-based
bomb(r, c)

# 출력
print('\n'.join(' '.join(map(str, row)) for row in grid))
