n, m = map(int, input().split())
max_t = 1000001
pos_a, pos_b = [0] * max_t, [0] * max_t

# Process A's movements
v = []
t = []
for _ in range(n):
    vi, ti = map(int, input().split())
    v.append(vi)
    t.append(ti)

# Process B's movements
v2 = []
t2 = []
for _ in range(m):
    vi, ti = map(int, input().split())
    v2.append(vi)
    t2.append(ti)

record_a = 1
for i in range(n):
    for _ in range(t[i]):
        pos_a[record_a] = pos_a[record_a - 1] + v[i]
        record_a += 1

record_b = 1
for i in range(m):
    for _ in range(t2[i]):
        pos_b[record_b] = pos_a[record_b - 1] + v2[i]
        record_b += 1

leader, ans = 0, 0
for i in range(1, record_a):
    if pos_a[i] > pos_b[i]:
        if leader == 2:
            ans += 1

        leader = 1
    elif pos_a[i] < pos_b[i]:
        if leader == 1:
            ans += 1

        leader = 2

print(ans)