from collections import Counter
n, m, t = map(int, input().split())


grid = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    grid[i] = [0] + list(map(int, input().split()))


marbles = [tuple(map(int, input().split())) for _ in range(m)]
r = [pos[0] for pos in marbles]
c = [pos[1] for pos in marbles]

target_list = [[x, y] for x, y in zip(r, c)]

def in_range(x, y):
    return 1 <= x <= n and 1 <= y <= n

def change(r1, c1, r2, c2):
    return r2, c2, r1, c1

def simulation(time):
    global target_list
    while(time):
        new_list = list()

        #for marble in target_list:
        #    print(f"now at {marble}")
        #print("\n")
        length = len(target_list)
        time -= 1
        for i in range(length):
            curr_x = target_list[i][0]
            curr_y = target_list[i][1]

            find_next_x = curr_x
            find_next_y = curr_y
            move_target = 0
            for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nx = curr_x + dx
                ny = curr_y + dy

                if not in_range(nx, ny):
                    continue

                if move_target < grid[nx][ny]:
                    find_next_x = nx
                    find_next_y = ny
                    move_target = grid[nx][ny]
            new_list.append((find_next_x, find_next_y))
        cnt = Counter(new_list)
        target_list = [pos for pos, c in cnt.items() if c == 1]

    return len(target_list)

print(simulation(t))