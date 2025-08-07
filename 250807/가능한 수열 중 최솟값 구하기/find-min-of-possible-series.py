import sys
sys.setrecursionlimit(10**7)

# 변수 선언 및 입력
n = int(sys.stdin.readline())
nums = [4, 5, 6]

series = []  # 네 original의 selected 리스트

# ─── “좋은 수열”인지 검사 ───
# series 끝에 새로 붙인 한 글자만 검사하기 때문에 O(n)으로 충분히 빠름
def is_impossible():
    L = len(series)
    for i in range(L):
        for j in range(1, (L - i)//2 + 1): # j는 길이이다.
            if series[i:i + j] == series[i + j:i + 2*j]:
                return True
    return False

# ─── 백트래킹 ───
def backtracking(cnt):
    # 길이 n에 도달하면 바로 출력 후 종료
    if cnt == n:
        # 숫자 리스트를 문자열로 바꾸어 붙여 출력
        print(*series, sep="")
        sys.exit(0)

    # 4,5,6 순서대로 시도 → 사전순 최솟값 보장
    for num in nums:
        series.append(num)
        if not is_impossible():       # 여기서 가지치기
            backtracking(cnt + 1)
        series.pop()

# 탐색 시작
backtracking(0)
