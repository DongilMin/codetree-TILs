N = int(input().strip())
s = input().strip()

for k in range(1, N + 1):
    seen = set()
    duplicate = False
    for i in range(N - k + 1):
        sub = s[i:i + k]
        if sub in seen:   # 같은 길이-k 부분문자열이 두 번 이상 등장
            duplicate = True
            break
        seen.add(sub)
    if not duplicate:
        print(k)
        break
