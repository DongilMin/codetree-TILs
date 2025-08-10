import sys
from math import inf


S = (-1, -1)
E = (-1, -1)
n = int(input())
grid = []
num_pos = {}

for i in range(n):
    row = list(input())
    grid.append(row)
    for j, ch in enumerate(row):
        if '1' <= ch <= '9':
            num_pos[ch] = (i, j)
        elif ch == 'S':
            S = (i, j)
        elif ch == 'E':
            E = (i, j)

num_list = sorted(num_pos.keys(), key=int)

if len(num_list) < 3 or S == (-1, -1) or E == (-1, -1):
    print(-1)
    sys.exit()

selected = []
ans = inf

def manhattan(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def calc():
    order = [S] + [num_pos[d] for d in sorted(selected, key=int)] + [E]
    dist = 0
    for u, v in zip(order, order[1:]):
        dist += manhattan(u, v)
    return dist

def func(idx, cnt):
    global ans
    if cnt == 3:
        ans = min(ans, calc())
    elif idx == len(num_list):
        return
    else:
        selected.append(num_list[idx])
        func(idx + 1, cnt + 1)
        selected.pop()

        func(idx + 1, cnt)

func(0, 0)
print(ans if ans < inf else -1)