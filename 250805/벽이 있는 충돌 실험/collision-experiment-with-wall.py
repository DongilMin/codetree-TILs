from collections import Counter

T = int(input())
directions = [(-1, 0), (1, 0), (0, 1), (0, -1)] # U, D, R, L

def in_range(x, y, n):
    return 1 <= x <= n and 1 <= y <= n

def turn(d):
    return d + 1 if d in (0, 2) else d - 1
        
def dir_to_num(c):
    return {'U': 0, 'D': 1, 'R': 2, 'L': 3}[c]

for _ in range(T):
    N, M = map(int, input().split())
    marbles = []
    x, y, d = [], [], []
    for _ in range(M):
        xi, yi, di = input().split()
        marbles.append((int(xi), int(yi), dir_to_num(di)))

    for i in range(N * N + 1):
        new_marbles = []
        for marble in marbles:
            curr_x = marble[0]
            curr_y = marble[1]
            curr_d = marble[2]

            dx, dy = directions[curr_d]
            nx = curr_x + dx
            ny = curr_y + dy
            nd = curr_d
            if not in_range(nx, ny, N):
                nx, ny = curr_x, curr_y
                nd = turn(curr_d)
            new_marbles.append((nx, ny, nd))
        cnt_pos = Counter((x, y) for x, y, d in new_marbles)
        marbles = [(x, y, d) for x, y, d in new_marbles if cnt_pos[(x, y)] == 1]
    print(len(marbles))