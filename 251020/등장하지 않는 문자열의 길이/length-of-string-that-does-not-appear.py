N = int(input())
s = input()

ans = 10**18
for i in range(1, N + 1):
    char = s[:i]
    if char not in s[i + 1:]:
        if N == 20:
            print(char)
        ans = min(ans, i)

print(ans)