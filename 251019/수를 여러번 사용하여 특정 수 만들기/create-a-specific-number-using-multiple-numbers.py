A, B, C = map(int, input().split())


ans = 0
for i in range(1001):
    for j in range(1001):
        num = A * i + B * j
        if num <= C:
            ans = max(ans, num)
print(ans)