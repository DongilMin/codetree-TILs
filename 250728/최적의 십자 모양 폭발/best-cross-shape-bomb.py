n = int(input())
numbers = [list(map(int, input().split())) for _ in range(n)]

def in_range(x ,y):
    return 0 <= x < n and 0 <= y < n

def fall(bombs, col):
    n = len(bombs)
    blocks = []

    for i in range(n - 1, -1, -1):
        if bombs[i][col] != 0 :
            blocks.append(bombs[i][col])
    
    for i in range(n - 1, -1, -1):
        if blocks:
            bombs[i][col] = blocks.pop()
        else:
            bombs[i][col] = 0


def bomb_in_grid(x, y, bombs):

    dist = bombs[x][y]
    bombs[x][y] = 0

    fire = set()
    fire.add(y)

    for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        for step in range(1, dist): 
            nx, ny = x + dx * step, y + dy * step
            if in_range(nx, ny):
                bombs[nx][ny] = 0
                fire.add(ny)

    for col in fire:
        fall(bombs, col)

def find_pair(bombs):
    cnt = 0
    for i in range(n):
        for j in range(n):
            for dx, dy in ((0, 1), (1, 0)):
                ni, nj = i + dx, j + dy
                if in_range(ni, nj) and bombs[i][j] != 0 and bombs[i][j] == bombs[ni][nj]:
                    cnt += 1
    return cnt

def simulation(x, y):
    bombs = [row[:] for row in numbers]
    bomb_in_grid(x, y, bombs)
    return find_pair(bombs)

ans = 0
for i in range(n):
    for j in range(n):
        ans = max(ans, simulation(i, j))


print(ans)