n = int(input())
x = [tuple(map(int, input().split())) for _ in range(n)]

ans = 0

for i in range(n):
    overlap = False

    for j in range(n):
        if j == i:
            continue
        
        if (x[i][0] <= x[j][0] and x[i][1] >= x[j][1]) or (x[i][0] >= x[j][0] and x[i][0] <= x[j][1]):
            overlap = True
            break
    
    if not overlap:
        ans +=1

print(ans)