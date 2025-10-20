N = int(input())
s = input()

ans = 10**18
for i in range(2, N + 1):
    char = s[:i]
    if char not in s[i:]:
        ans = min(ans, i)

print(ans)