X, Y = map(int, input().split())

cnt = 0
for num in range(X, Y + 1):
    s = str(num)
    if s == s[::-1]:
        cnt += 1

print(cnt)