n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]
edges.sort(key=lambda x: x[1])
selected = []
ans = float('inf')

def possible():
    origin = [i for i in range(n)]
    subject = [i for i in range(n)]

    for col, row in edges:
        c = col - 1
        if 0 <= c < n-1:
            origin[c], origin[c+1] = origin[c+1], origin[c]

    for col, row in selected:
        c = col - 1
        if 0 <= c < n-1:
            subject[c], subject[c+1] = subject[c+1], subject[c]
    
    return origin == subject

def backtracking(cnt):
    global ans
    if cnt == m:
        if possible():
            ans = min(ans, len((selected)))
        return
    else:
        selected.append(edges[cnt])
        backtracking(cnt + 1)
        selected.pop()

        backtracking(cnt + 1)

backtracking(0)
print(ans)
