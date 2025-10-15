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
        pos_b[record_b] = pos_b[record_b - 1] + v2[i]
        record_b += 1

ans = 0
lead_a = False
lead_b = False
for i in range(1, record_a):
    if pos_a[i] > pos_b[i]:
        if lead_b == True:
            lead_a = True
            lead_b = False
            ans += 1
    elif pos_a[i] < pos_b[i]:
        if lead_a == True:
            lead_b = True
            lead_a = False
            ans += 1
    else:
        lead_b = True
        lead_a = True
        ans += 1

print(ans)