import sys
from math import inf

n = int(input())

S = (-1, -1)
E = (-1, -1)
num_pos = {}   # 키: '1'~'9' (문자), 값: (i, j)
grid = []

for i in range(n):
    row = list(input())      # input()은 개행 제거됨
    grid.append(row)
    for j, ch in enumerate(row):
        if '1' <= ch <= '9':
            num_pos[ch] = (i, j)      # 같은 숫자가 여러 칸이면 마지막만 남음(필요시 확장)
        elif ch == 'S':
            S = (i, j)
        elif ch == 'E':
            E = (i, j)

# 숫자 목록(중복 제거) — 문자로 유지
num_list = sorted(num_pos.keys(), key=int)

# 숫자 총 개수가 3 미만이면 불가능 처리
if len(num_list) < 3 or S == (-1, -1) or E == (-1, -1):
    print(-1)
    sys.exit(0)

selected = []
ans = inf

def manhattan(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def calc():
    # 선택된 숫자를 숫자값 오름차순으로 방문
    order = [S] + [num_pos[d] for d in sorted(selected, key=int)] + [E]
    dist = 0
    for u, v in zip(order, order[1:]):
        dist += manhattan(u, v)
    return dist

# 백트래킹: num_list에서 정확히 3개 선택 (최소 3개면 최적은 3개 선택일 뿐이라 이게 충분)
def func(idx, cnt):
    global ans

    # 3개 선택 완료 → 거리 계산
    if cnt == 3:
        ans = min(ans, calc())
        return

    # 더 고를 숫자가 없음
    if idx == len(num_list):
        return

    # 가지치기: 남은 숫자를 전부 골라도 3개 못 채우면 중단
    if cnt + (len(num_list) - idx) < 3:
        return

    # 1) 현재 숫자 선택
    selected.append(num_list[idx])
    func(idx + 1, cnt + 1)
    selected.pop()

    # 2) 현재 숫자 미선택
    func(idx + 1, cnt)

func(0, 0)
print(ans if ans < inf else -1)
