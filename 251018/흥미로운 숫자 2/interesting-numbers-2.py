from collections import Counter

X, Y = map(int, input().split())

def is_interesting(s):
    c = Counter(s)
    return len(c) == 2 and 1 in c.values()

ans = 0
for i in range(X, Y + 1):
    if is_interesting(str(i)):
        ans += 1

print(ans)