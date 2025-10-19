n = int(input())
arr = list(map(int, input().split()))

ans = 10**18
for i in range(n):
    new_arr = [arr[j] * 2 if i == j else arr[j] for j in range(len(arr))]

    for j in range(n):
        if i == j:
            continue
        new_new_arr = [new_arr[k] for k in range(len(new_arr)) if k != j]

        sum = 0
        for l in range(1, len(new_new_arr)):
            sum += abs(new_new_arr[l] - new_new_arr[l - 1])
        ans = min(ans, sum)

print(ans)