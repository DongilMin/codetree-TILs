import sys

n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
x = [p[0] for p in points]
y = [p[1] for p in points]

ans = 0

for i in range(n):
    max_x = -10001
    min_x = 10001
    max_y = -10001
    min_y = 10001
    for j in range(n):
        if j == i:
            continue

        max_x, min_x = max(max_x, x[j]), min(min_x, x[j])
        max_y, min_y = max(max_y, y[j]), min(min_y, y[j])

        if max_x == min_x or max_y == min_y:
            continue
    # print(f"{max_x} and {min_x} && {max_y} and {min_y}")
    ans = max(ans, abs((max_x - min_x) * (max_y - min_y)))

print(ans)