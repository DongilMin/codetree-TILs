k, n = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(k)]

ans = 0
for i in range(1, n + 1):
    for j in range(1, n + 1):

        if i == j:
            continue
        
        correct = True

        for lists in arr:
            index_i = lists.index(i)
            index_j = lists.index(j)

            if index_i > index_j:
                correct = False
        
        if correct:
            ans += 1

print(ans)