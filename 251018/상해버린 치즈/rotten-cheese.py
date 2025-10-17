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
    
"""
from collections import defaultdict

INF = 10**18
input = __import__('sys').stdin.readline

def main():
    n, m, d, s = map(int, input().split())

    eat = [[] for _ in range(n + 1)]  # 사람별 (치즈, 시간)
    for _ in range(d):
        p, c, t = map(int, input().split())
        eat[p].append((c, t))

    sick_time = [INF] * (n + 1)
    for _ in range(s):
        p, t = map(int, input().split())
        sick_time[p] = min(sick_time[p], t)

    # step 1️⃣ 각 아픈 사람별로 "발병 전에 먹은 치즈들" 구하기
    candidate_cheeses = []  # 각 아픈 사람의 후보 치즈 집합
    sick_people = [p for p in range(1, n + 1) if sick_time[p] < INF]

    for p in sick_people:
        eaten_before_sick = set()
        for c, t in eat[p]:
            if t < sick_time[p]:  # 발병 전에 먹었으면 후보
                eaten_before_sick.add(c)
        candidate_cheeses.append(eaten_before_sick)

    # step 2️⃣ 공통으로 먹은 치즈(모두가 발병 전에 먹은 치즈)
    if not candidate_cheeses:  # 아픈 사람 없음
        print(0)
        return

    common_cheeses = set.intersection(*candidate_cheeses)

    # step 3️⃣ 그 치즈들을 먹은 모든 사람 찾기
    eaters = set()
    for p in range(1, n + 1):
        for c, t in eat[p]:
            if c in common_cheeses:
                eaters.add(p)

    print(len(eaters))

if __name__ == "__main__":
    main()
"""