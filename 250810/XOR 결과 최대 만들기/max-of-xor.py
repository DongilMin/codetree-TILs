n, m = map(int, input().split())
A = list(map(int, input().split()))
selected = []
ans = 0
def calc():
    result = 0
    for num in selected:
        result = result ^ num
    return result

def func(idx, cnt):
    global ans
    if cnt == m:
        ans = max(ans, calc())
        return
    elif idx == n:
        return
    else:
        selected.append(A[idx])
        func(idx + 1, cnt + 1)
        selected.pop()
        func(idx + 1, cnt)

func(0, 0)
print(ans)