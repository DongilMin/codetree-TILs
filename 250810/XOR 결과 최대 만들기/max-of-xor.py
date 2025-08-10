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
    elif idx > n:
        return
    else:
        selected.append(idx)
        func(idx + 1, cnt + 1)
        selected.pop()
        func(idx + 1, cnt)

func(1, 0)
print(ans)