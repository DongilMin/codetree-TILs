n, m = map(int, input().split())

max_t = 1000001
a_pos, b_pos = [0] * max_t, [0] * max_t

a_time = 1
for _ in range(n):
    d, t = tuple(input().split())
    for _ in range(int(t)):
        a_pos[a_time] = a_pos[a_time - 1] + (1 if d == 'R' else -1)
        a_time += 1

b_time = 1
for _ in range(m):
    d, t = tuple(input().split())
    for _ in range(int(t)):
        b_pos[b_time] = b_pos[b_time - 1] + (1 if d == 'R' else -1)
        b_time += 1

ans = -1
for i in range(1, a_time):
    if a_pos[i] == b_pos[i]:
        ans = i
        break

print(ans)