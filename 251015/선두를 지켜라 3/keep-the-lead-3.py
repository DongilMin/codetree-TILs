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

def get_leader(pos1, pos2):
    if pos1 > pos2:
        return 1  # A가 선두
    elif pos2 > pos1:
        return 2  # B가 선두
    else:
        return 3  # 공동 선두
        
prev_leader = get_leader(pos_a[0], pos_b[0])
for i in range(1, record_b):
    current_leader = get_leader(pos_a[i], pos_b[i])
    
    if current_leader != prev_leader:
        ans += 1
    
    prev_leader = current_leader

print(ans)