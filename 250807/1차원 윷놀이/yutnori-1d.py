n, m, k = map(int, input().split())
nums = list(map(int, input().split()))
horses = [1] * k
ans = 0

# k개의 말에 대하여 각각이 n개의 경우에 할당된다. O(k*n)
# 목표지점을 넘어가는 말은 이동 중단
def calc():
    scores = 0
    for i in range(k):
        if horses[i] >= m:
            scores += 1
    return scores

def backtracking(curr):
    global ans
    if curr == n:
        ans = max(ans, calc())
        return
    else:
        for i in range(k):
            if horses[i] >= m:
                continue
            horses[i] += nums[curr]
            backtracking(curr + 1)
            horses[i] -= nums[curr]

backtracking(0)
print(ans)