n = int(input())
a = list(map(int, input().split()))

a.sort()
ans = 0
for k in range(1, n + 1):
    new_arr = [num for num in a]
    new_arr.append(k)
    new_arr.sort()
    cnt = 0
    for i in range(len(new_arr)):
        for j in range(i + 1, len(new_arr)):
            for l in range(j + 1, len(new_arr)):
                if new_arr[j] - new_arr[i] == new_arr[l] - new_arr[j]:
                    cnt += 1
    ans = max(ans, cnt)

print(ans)