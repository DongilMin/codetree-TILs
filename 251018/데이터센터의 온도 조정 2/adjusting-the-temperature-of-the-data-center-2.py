N, C, G, H = map(int, input().split())
ranges = [tuple(map(int, input().split())) for _ in range(N)]
max_val = max(max(a, b) for a, b in ranges)

def get_score(a, b, t):
    if t < a:
        return C
    elif a <= t and t <= b:
        return G
    else:
        return H

ans = 0
for temp in range(1, max_val + 2):
    work = 0
    for a, b in ranges:
        work += get_score(a, b, temp)

    ans = max(ans, work)

print(ans)