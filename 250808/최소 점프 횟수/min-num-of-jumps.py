n = int(input())
num = list(map(int, input().split()))
ans = 999999

def backtracking(idx, cnt):
    global ans
    if idx >= n - 1:
        ans = min(ans, cnt)
        return
    else:
        for i in range(1, num[idx] + 1):
            backtracking(idx + i, cnt + 1)

backtracking(0, 0)
print(ans if ans != 999999 else -1)