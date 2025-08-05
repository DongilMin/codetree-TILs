import sys
input = sys.stdin.readline

# 방향 맵핑 및 이동 델타
dir_map = {'U': 0, 'D': 1, 'R': 2, 'L': 3}
dirs    = [(-1, 0), (1, 0), (0, 1), (0, -1)]  # U, D, R, L

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    marbles = []
    for _ in range(M):
        x, y, c = input().split()
        marbles.append((int(x), int(y), dir_map[c]))

    # 각 구슬은 수평/수직 이동 주기가 2*(N-1) 이므로
    ticks = 2 * (N - 1)
    for _ in range(ticks):
        # 위치 충돌 카운터 초기화
        pos_cnt = [[0] * (N + 1) for _ in range(N + 1)]
        moved = []

        # 1) 이동
        for x, y, d in marbles:
            dx, dy = dirs[d]
            nx, ny = x + dx, y + dy
            # 벽 충돌 시 제자리 + 방향 반전
            if not (1 <= nx <= N and 1 <= ny <= N):
                nx, ny = x, y
                d ^= 1  # 0↔1, 2↔3
            moved.append((nx, ny, d))
            pos_cnt[nx][ny] += 1

        # 2) 충돌 제거: 위치당 1개인 구슬만 남김
        marbles = [
            (x, y, d)
            for x, y, d in moved
            if pos_cnt[x][y] == 1
        ]
        if not marbles:
            break

    # 결과 출력
    print(len(marbles))
