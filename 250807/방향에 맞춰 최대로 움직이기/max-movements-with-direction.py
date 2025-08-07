n = int(input())
num = [list(map(int, input().split())) for _ in range(n)]
move_dir = [list(map(int, input().split())) for _ in range(n)]
r, c = map(int, input().split())
r -= 1
c -= 1
ans = 0

# Please write your code here.
dirs = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), 
        (1, -1), (0, -1), (-1, -1)]

def in_range(x, y):
    return 0 <= x < n and 0 <= y < n

def backtracking(r, c, move_cnt):
    global ans
    ans = max(ans, move_cnt)

    dx, dy = dirs[move_dir[r][c] - 1]

    for dist in range (1, n):
        nx = r + dx * dist
        ny = c + dy * dist
        # print(f"next is {nx} and {ny}")
        if not in_range(nx, ny) or num[r][c] > num[nx][ny]:
            continue

        backtracking(nx, ny, move_cnt + 1)
    return

backtracking(r, c, 0)
print(ans)