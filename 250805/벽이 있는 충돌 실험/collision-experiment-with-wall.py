import sys
input = sys.stdin.readline

# 방향 매핑(U,D,R,L → 0,1,2,3) 및 델타
dir_map = {'U': 0, 'D': 1, 'R': 2, 'L': 3}
dirs    = [(-1, 0), (1, 0), (0, 1), (0, -1)]

MAX_N = 50
# 위치별 구슬 개수 카운팅용 (전역 재사용)
pos_cnt = [[0] * (MAX_N + 1) for _ in range(MAX_N + 1)]

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    marbles = []
    for _ in range(M):
        x, y, c = input().split()
        marbles.append((int(x), int(y), dir_map[c]))

    # 충분히 긴 틱 수: 2*N
    for _ in range(2 * N):
        # 1) 이동
        for i, (x, y, d) in enumerate(marbles):
            dx, dy = dirs[d]
            nx, ny = x + dx, y + dy
            if not (1 <= nx <= N and 1 <= ny <= N):
                # 벽에 부딪히면 제자리에 머무르고 방향 반전
                nx, ny = x, y
                d ^= 1  # 0⇔1, 2⇔3
            marbles[i] = (nx, ny, d)

        # 2) 위치별 개수 집계
        for x, y, d in marbles:
            pos_cnt[x][y] += 1

        # 3) 충돌 없는 구슬만 선별
        new_list = []
        for x, y, d in marbles:
            if pos_cnt[x][y] == 1:
                new_list.append((x, y, d))

        # 4) 카운터 리셋
        for x, y, d in marbles:
            pos_cnt[x][y] = 0

        marbles = new_list
        if not marbles:
            break

    # 최종 살아남은 구슬 수 출력
    print(len(marbles))
