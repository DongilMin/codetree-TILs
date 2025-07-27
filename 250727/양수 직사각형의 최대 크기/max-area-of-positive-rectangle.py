n, m = tuple(map(int, input().split()))
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.

def get_size(x1, y1, x2, y2):
    return all([
        grid[i][j] > 0
        for i in range(x1, x2 + 1)
        for j in range(y1, y2 + 1)
    ])

ans = -1
for i in range(n):
    for j in range(n):
        for k in range(i, n):
            for l in range(j, m):
                if get_size(i, j, k, l):
                    ans = max(ans,
                                (k - i + 1) * (l - j + 1))
                        
print(ans)