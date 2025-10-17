n = int(input())

def is_overlap(a, b):
    (a1, b1) = a
    (a2, b2) = b
    return a1 <= b2 and b1 >= a2

points = []
for _ in range(n):
    left, right = map(int, input().split())
    points.append((left, right))

points.sort()

ans = 0
for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            new_lists = [(a, b) for index, (a, b) in enumerate(points) if index not in [i, j, k] ]

            not_overlap = True
            for l in range(len(new_lists)):
                for m in range(l + 1, len(new_lists)):
                    if is_overlap(new_lists[l], new_lists[m]):
                        not_overlap = False
                        break
                if not not_overlap:
                    break
            if not_overlap:
                ans += 1

print(ans)