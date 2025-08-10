from math import inf
from collections import Counter

n = int(input())
num = list(map(int, input().split()))
ans = inf

selected = []

def calc():
    # selected에 있는 원소들을 num에서 '개수만큼' 제거한 나머지가 remain
    cnt = Counter(selected)
    remain = []
    for x in num:
        if cnt[x] > 0:
            cnt[x] -= 1
        else:
            remain.append(x)

    # 예시 목적함수: 선택합과 남은합의 차이의 절댓값
    return abs(sum(remain) - sum(selected))

def func(idx, picked):
    global ans
    # 가지치기: 남은 원소로 n개 못 채우면 중단
    if picked + (2 * n - idx) < n:
        return

    if picked == n:
        ans = min(ans, calc())
        # 디버깅 출력 원하면:
        # if ans in (7, 19):
        #     print(*selected)
        return

    if idx == 2 * n:
        return

    # 선택
    selected.append(num[idx])
    func(idx + 1, picked + 1)
    selected.pop()

    # 미선택
    func(idx + 1, picked)
    
func(0, 0)
print(ans)