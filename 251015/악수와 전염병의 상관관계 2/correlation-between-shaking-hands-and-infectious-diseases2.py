N, K, P, T = map(int, input().split())

handshakes = [tuple(map(int, input().split())) for _ in range(T)]

handshakes.sort(key=lambda x: x[0])

infected = [False] * (N + 1)
infection_count = [0] * (N + 1)

infected[P] = True
infection_count[P] = K

for t, p1, p2 in handshakes:

    p1_infected = infected[p1]
    p2_infected = infected[p2]

    if p1_infected and not p2_infected and infection_count[p1] > 0:
        infected[p2] = True
        infection_count[p1] -= 1
        infection_count[p2] = K

    if p2_infected and not p1_infected and infection_count[p2] > 0:
        infected[p1] = True
        infection_count[p2] -= 1
        infection_count[p1] = K

    # 둘 다 감염된 상태라면, 남은 전염 횟수만 차감
    if p1_infected and p2_infected:
        if infection_count[p1] > 0:
            infection_count[p1] -= 1
        if infection_count[p2] > 0:
            infection_count[p2] -= 1

for i in range(1, N + 1):
    if infected[i]:
        print(1, end='')
    else:
        print(0, end='')