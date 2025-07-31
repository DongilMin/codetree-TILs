n, m, r, c = map(int, input().split())
directions = input().split()

grid = [[0] * (n + 1) for _ in range(n + 1)]


up, front, right, down, back, left = 1, 2, 3, 6, 5, 4

def in_range(x, y):
    return 1 <= x <= n and 1 <= y <= n

def roll_left(left, up, right, down):
    return (up, right, down, left)
    
def roll_right(right, up, left, down):
    return (up, left, down, right)
    
def roll_up(back, up, front, down):
    return (up, front, down, back)

def roll_down(front, up, back, down):
    return up, back, down, front

def roll(x, y):
    global up, front, right, down, back, left
    grid[x][y] = down
    for direc in directions:
        if direc == 'L':
            if in_range(x, y - 1):
                # print(f"left! x and y = {left}")
                y -= 1
                grid[x][y] = left
                left, up, right, down = roll_left(left, up, right, down)
        if direc == 'R':
            if in_range(x, y + 1):
                # print(f"right! x and y = {right}")
                y += 1
                grid[x][y] = right
                right, up, left, down = roll_right(right, up, left, down)
        if direc == 'U':
            if in_range(x - 1, y):
                # print(f"up! x and y = {back}")
                x -= 1
                grid[x][y] = back
                back, up, front, down = roll_up(back, up, front, down)
        if direc == 'D':
            if in_range(x + 1, y):
                # print(f"down! x and y = {front}")
                x += 1
                grid[x][y] = front
                front, up, back, down = roll_down(front, up, back, down)

roll(r, c)

result = 0
for i in range(1, n + 1):
    for j in range(1, n + 1):
        result += int(grid[i][j])

print(result)