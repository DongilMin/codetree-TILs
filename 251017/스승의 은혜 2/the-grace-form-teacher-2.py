N, B = map(int, input().split())
P = [int(input()) for _ in range(N)]

ans = 0
for i in range(N):
    remain = [
        P[j] for j in range(N)
    ]
    P[i] /= 2

    remain.sort()
    money = 0
    student = 0

    for j in range(N):
        if money + remain[j] > B:
            break
        money += P[j]
        student += 1
    
    ans = max(ans, student)

print(ans)
