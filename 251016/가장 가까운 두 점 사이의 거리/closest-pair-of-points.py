import sys

n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
x = [p[0] for p in points]
y = [p[1] for p in points]

def get_distance(x1, y1, x2 ,y2):
    return (x2 - x1)**2 + (y2 - y1)**2

ans = sys.maxsize
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        
        ans = min(ans, get_distance(x[i], y[i], x[j], y[j]))

print(ans)