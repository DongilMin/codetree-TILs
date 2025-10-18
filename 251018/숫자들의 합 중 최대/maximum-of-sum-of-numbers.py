X, Y = map(int, input().split())

ans = 0
for i in range(X, Y + 1):
    arr = tuple(map(int, list(str(i))))
    ans = max(ans, sum(arr))
print(ans)