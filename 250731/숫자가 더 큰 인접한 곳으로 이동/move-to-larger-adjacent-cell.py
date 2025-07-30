n, r, c = map(int, input().split())
a = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    row = list(map(int, input().split()))
    for j in range(1, n + 1):
        a[i][j] = row[j - 1]

def in_range(x, y):
    return 1 <= x and x <= n and 1 <= y and y <= n

def move_in_grid():
    curr_x = r
    curr_y = c 

    ans = list()

    while True:
        can_move = False
        ans.append(a[curr_x][curr_y])
        for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nx, ny = curr_x + dx, curr_y + dy

            if in_range(nx, ny) and a[curr_x][curr_y] < a[nx][ny]:
                curr_x, curr_y = nx, ny
                can_move = True
                break
        if not can_move: break
    return ans

result = move_in_grid()
for ele in result:
    print(ele, end = " ")