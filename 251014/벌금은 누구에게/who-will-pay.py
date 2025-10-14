N, M, K = map(int, input().split())
student = [int(input()) for _ in range(M)]

cnt = [0] * (N + 1)
ans = -1
for s in student:
    cnt[s] += 1
    if cnt[s] >= K:
        ans = s
        break

print(ans)