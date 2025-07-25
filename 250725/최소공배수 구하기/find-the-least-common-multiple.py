n, m = map(int, input().split())

def func(n, m):
    ans = 0
    for i in range(n * m, 0, -1):
        if i % n == 0 and i % m == 0:
                ans = i
                
        
    print(ans)


func(n, m)