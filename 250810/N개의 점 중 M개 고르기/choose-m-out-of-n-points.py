from math import inf

n, m = map(int, input().split())
points = [list(map(int, input().split())) for _ in range(n)]

selected = []
ans = inf  # 최소화할 값(선택된 점들 사이 최대 제곱거리)

def dist2(a, b):
    dx = a[0] - b[0]
    dy = a[1] - b[1]
    return dx*dx + dy*dy  # 제곱거리

def calc():
    # 선택된 점들 사이의 최대 제곱거리
    if len(selected) < 2:
        return 0
    result = 0
    L = len(selected)
    for i in range(L):
        for j in range(i + 1, L):
            result = max(result, dist2(selected[i], selected[j]))
    return result

def func(idx, cnt):
    global ans
    # m개를 뽑으면 평가하고 종료
    if cnt == m:
        ans = min(ans, calc())
        return
    # 더 이상 고를 점이 없으면 종료
    if idx == n:
        return
    # 가지치기: 남은 점으로 m개 못 채우는 경우
    if cnt + (n - idx) < m:
        return

    # 선택
    selected.append(points[idx])
    func(idx + 1, cnt + 1)
    selected.pop()

    # 미선택
    func(idx + 1, cnt)

func(0, 0)
print(ans if ans < inf else -1)  # 제곱거리 출력
