n, m = map(int, input().split())

max_t = 1000001
pos_a, pos_b = [0] * max_t, [0] * max_t

# 로봇 A의 움직임 기록
time_a = 1
for _ in range(n):
    t, d = input().split()
    t = int(t)
    move = 1 if d == 'R' else -1
    for _ in range(t):
        pos_a[time_a] = pos_a[time_a - 1] + move
        time_a += 1

# 로봇 B의 움직임 기록
time_b = 1
for _ in range(m):
    t, d = input().split()
    t = int(t)
    move = 1 if d == 'R' else -1
    for _ in range(t):
        pos_b[time_b] = pos_b[time_b - 1] + move
        time_b += 1

# 전체 시뮬레이션 시간 계산
total_time = max(time_a, time_b)

# 먼저 움직임이 끝난 로봇을 마지막 위치로 채워줌
if time_a < time_b:
    for i in range(time_a, time_b):
        pos_a[i] = pos_a[time_a - 1]
elif time_b < time_a:
    for i in range(time_b, time_a):
        pos_b[i] = pos_b[time_b - 1]

# 만남 횟수 계산
ans = 0
# i=1 부터 시작해서 이전 위치(i-1)와 비교
for i in range(1, total_time):
    # 현재 위치는 같고, 이전 위치는 달랐을 때 만난 것
    if pos_a[i] == pos_b[i] and pos_a[i - 1] != pos_b[i - 1]:
        ans += 1

print(ans)