n = int(input())
arr = [int(input()) for _ in range(n)]

result = 0
cnt = 0
for i in range(n):
    if i == 0 or arr[i] != arr[i - 1] or i == n - 1:
        cnt = 1
        result = max(result, cnt)
    else:
        cnt += 1

print(result)