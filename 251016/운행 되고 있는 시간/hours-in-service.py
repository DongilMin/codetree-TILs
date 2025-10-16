n = int(input())
times = [tuple(map(int, input().split())) for _ in range(n)]
a = [t[0] for t in times]
b = [t[1] for t in times]

operating = [0] * 10001

ans = 0
for i in range(n):
    operating = [0] * 10001
    for j in range(n):
        if i == j:
            continue
        for k in range(a[j], b[j]):
            operating[k] += 1
    
    ans = max(ans, sum(1 for x in operating if x > 0))
        
print(ans)