import sys
from collections import defaultdict

input = sys.stdin.readline
INF = 10**18

def main():
    n, m, d, s = map(int, input().split())

    # 치즈별 섭취 기록: person -> earliest_time
    eat_by_cheese = [defaultdict(lambda: INF) for _ in range(m + 1)]
    for _ in range(d):
        p, c, t = map(int, input().split())
        if t < eat_by_cheese[c][p]:
            eat_by_cheese[c][p] = t

    # 사람별 가장 이른 발병 시각
    sick_time = [INF] * (n + 1)
    for _ in range(s):
        p, t = map(int, input().split())
        if t < sick_time[p]:
            sick_time[p] = t

    # 실제로 아픈 사람 목록만 뽑아두면 매 치즈마다 이들만 검사하면 됨
    sick_people = [p for p in range(1, n + 1) if sick_time[p] < INF]

    ans = 0
    for c in range(1, m + 1):
        eaten = eat_by_cheese[c]  # dict: p -> earliest_eat_time

        # 아픈 사람 모두가 "발병 전에" c번 치즈를 먹었는지 검사
        possible = True
        for p in sick_people:
            if eaten.get(p, INF) >= sick_time[p]:
                possible = False
                break
        if not possible:
            continue

        # 가능하면, c번 치즈를 먹은 사람 수(=약 필요 수)를 세어 최댓값 갱신
        pills = len(eaten)  # dict key 수 == 섭취자 수(중복/후행 시각 자동 제거)
        if pills > ans:
            ans = pills

    print(ans)

if __name__ == "__main__":
    main()
