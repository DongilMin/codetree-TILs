n = int(input())
grid = [[0] * (n + 1) for _ in range(n + 1)]
directions = [(-1, 0), (0, 1), (1, 0), (0, -1)] # 위 , 오, 아래, 왼 

for i in range(1, n + 1):
    grid[i] = [0] + list(map(int, input().split()))

def in_range(x, y):
    return 1 <= x <= n and 1 <= y <= n

def turn(bar, direct):
    if bar == 2: # \
        if direct == 0 or direct == 3:
            return direct + 1
        else:
            return direct - 1
    else: # /
        if direct == 0 or direct == 3:
            return (direct + 1) % 4
        else:
            return (direct - 1) % 4  

def simulation(start_x, start_y, direct):
    curr_x, curr_y = start_x, start_y
    curr_direct = direct
    time = 1
    while True:
        if(start_x == 5 and start_y == 5):
            print(f"here is {curr_x} and {curr_y}")
        dx, dy = directions[curr_direct]
        curr_x += dx
        curr_y += dy

        if not in_range(curr_x, curr_y):
            break
            
        time += 1
        if grid[curr_x][curr_y] != 0:
            curr_direct = turn(grid[curr_x][curr_y], curr_direct)
    return time + 1

result = 0
for i in range(1, n + 1):
    result = max(result, simulation(1, i, 2))

for i in range(1, n + 1):
    result = max(result, simulation(i, n, 3))

for i in range(n, 0, -1):
    result = max(result, simulation(n, i, 0))

for i in range(n, 0, -1):
    result = max(result, simulation(i, 1, 1))

print(result)