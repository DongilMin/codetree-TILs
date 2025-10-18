n = int(input())
h = [int(input()) for _ in range(n)]

ans = 0
for i in range(1, 1000):

    new_h = [j for j, v in enumerate(h) if v > i]

    cnt = 0
    check = []
    for k in new_h:
        if k in check:
            continue
        check.append(k)
        cnt += 1
        n_k = k + 1
        while n_k in new_h:
            check.append(n_k)
            n_k += 1
    
    ans = max(ans, cnt)

print(ans)