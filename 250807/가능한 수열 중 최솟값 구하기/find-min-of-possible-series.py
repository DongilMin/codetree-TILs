import sys
sys.setrecursionlimit(10**7)

# 변수 선언 및 입력
n = int(sys.stdin.readline())
nums = [4, 5, 6]

series = []  # 네 original의 selected 리스트

# ─── “좋은 수열”인지 검사 ───
# series 끝에 새로 붙인 한 글자만 검사하기 때문에 O(n)으로 충분히 빠름
def is_valid_series():
    L = len(series)
    for l in range(1, L//2 + 1):
        # 맨 뒤 l개와 그 앞 l개가 동일하면 안 됨
        if series[-l:] == series[-2*l:-l]:
            return False
    return True

# ─── 백트래킹 ───
def backtracking(cnt):
    # 길이 n에 도달하면 바로 출력 후 종료
    if cnt == n:
        # 숫자 리스트를 문자열로 바꾸어 붙여 출력
        print(''.join(map(str, series)))
        sys.exit(0)

    # 4,5,6 순서대로 시도 → 사전순 최솟값 보장
    for num in nums:
        series.append(num)
        if is_valid_series():       # 여기서 가지치기
            backtracking(cnt + 1)
        series.pop()

# 탐색 시작
backtracking(0)
