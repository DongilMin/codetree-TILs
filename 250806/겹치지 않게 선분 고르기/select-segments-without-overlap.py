n = int(input())
lines = list()
selected = list()
ans = 0

for _ in range(n):
    l, r = map(int, input().split())
    lines.append((l, r))

def calc():
    return len(selected) - 1

def debug():
    print(*selected)

def find_max_lines(cnt):
    if cnt == n:
        # debug()
        global ans
        ans = max(ans, calc())
        return
    else:
        a, b = lines[cnt]
        c, d = selected[-1]
        if d < a:
            selected.append((a, b))
            find_max_lines(cnt + 1)
            selected.pop(-1)

        find_max_lines(cnt + 1)

selected.append((0, 0))
lines.sort()

find_max_lines(0)
print(ans)