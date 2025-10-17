N, B = map(int, input().split())
P = [int(input()) for _ in range(N)]

ans = 0
for i in range(N):
    remain = B - (P[i] // 2)
    cnt = 1
    for j in range(N):
        if i == j:
            continue
        if remain - P[j] >= 0:
            remain -= P[j]
            cnt += 1
    ans = max(ans ,cnt)

print(cnt)
