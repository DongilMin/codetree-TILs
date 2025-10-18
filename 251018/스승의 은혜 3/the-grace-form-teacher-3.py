N, B = map(int, input().split())
gifts = [tuple(map(int, input().split())) for _ in range(N)]

ans = 0
for i in range(N):
    new_gifts = [(a / 2 + b) if j == i else (a + b) for j, (a, b) in enumerate(gifts)]
    new_gifts.sort()
    money = 0
    students = 0

    for j in range(N):
        if money + new_gifts[j] > B:
            break
        money += new_gifts[j]
        students += 1
    
    ans = max(ans, students)

print(ans)