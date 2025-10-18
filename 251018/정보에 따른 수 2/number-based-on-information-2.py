T, a, b = map(int, input().split())

# 빈칸은 점(.)으로 표시 (임의의 placeholder)
arr = ['.'] * 1001

for _ in range(T):
    c, pos = input().split()
    arr[int(pos)] = c

def find_nearest_index(arr, pos, target, prefer='left'):
    n = len(arr)
    if arr[pos] == target:      # 자기 자신이 target이면 거리 0
        return pos

    max_dist = max(pos, n - pos - 1)
    for d in range(1, max_dist + 1):
        li = pos - d
        ri = pos + d
        if prefer == 'left':
            if li >= 0 and arr[li] == target: return li
            if ri < n  and arr[ri] == target: return ri
        else:
            if ri < n  and arr[ri] == target: return ri
            if li >= 0 and arr[li] == target: return li
    return None 

def dist(i, target):
    j = find_nearest_index(arr, i, target)
    return abs(i - j) if j is not None else float('inf')

ans = 0
for x in range(a, b + 1):       # a..b만 카운트
    d1 = dist(x, 'S')
    d2 = dist(x, 'N')
    if d1 <= d2:
        ans += 1

print(ans)
