n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]
visited = [False] * (n + 1)
answer = []
ans = 0

def choose(curr_row):
    if curr_row == n:
        global ans
        ans = max(sum(answer), ans)
        return
    else:
        for i in range(n):
            if visited[i] == True:
                continue
            
            answer.append(grid[curr_row][i])
            visited[i] = True
            choose(curr_row + 1)
            visited[i] = False
            answer.pop()

choose(0)
print(ans)