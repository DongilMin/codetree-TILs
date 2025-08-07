n, m, c = map(int, input().split())
weight = [list(map(int, input().split())) for _ in range(n)]
visited = [False] * n
selected = []
ans = 0
# 행을 선택한다. visited(col) 표시
# 행에서의 가능한 n - 1경우의 수를 수행한다.
# 각각의 수행마다 또 다른 도둑의 경우의 수를 백트래킹 수행

def print_output():
    print(*selected)

def get_weight(row, col, length):
    return sum(x**2 for x in weight[row][col:col + length])

def backtracking(curr):
    if curr > c:
        # print_output()
        global ans
        ans = max(ans, curr)
        return
    else:
        for i in range(n):
            for j in range(n - m):
                if not visited[j]:
                    for in range(j,j + m):
                        total weight = 0

                    selected.extend(weight[i][j:j+m])
                    visited[j:j+m] = [True] * m
                    backtracking(curr + get_weight(i, j, m))
                    visited[j:j+m] = [False] * m
                    selected.extend(weight[i][j:j+m])
                    del selected[-m:]

backtracking(0)
print(ans)