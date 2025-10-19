n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]

def get_field(x, y, a, b):
    if a < x and b < y:
        return 1
    elif a > x and b < y:
        return 2
    elif a > x and b > y:
        return 3
    else:
        return 4


ans = 10**18
for x in range(2, 101, 2):
    for y in range(2, 101, 2):

        field = [[] for _ in range(5)]
        max_val = 0
        for point in points:
            a = point[0]
            b = point[1]
            field[get_field(x, y, a, b)].append((a, b))
        
        max_index = 0
        for i in range(1, 5):
            max_index = max(max_index, len(field[i]))
        ans = min(ans, max_index)

print(ans)