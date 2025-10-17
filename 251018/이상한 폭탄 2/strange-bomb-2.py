N, K = map(int, input().split())
num = [int(input()) for _ in range(N)]

def get_distanct(a, b):
    return b - a

ans = -1
for i in range(N):
    for j in range(i - K, i + K + 1):
        if i == j or j < 0 or j >= N:
            continue
        
        if num[i] == num[j]:
            ans = max(ans, num[j])

print(ans)
