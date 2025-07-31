n, m, r, c = map(int, input().split())

visited = set()
bombs = set()
bombs.add((r, c))
visited.add((r, c))

def in_range(x, y):
    return 1 <= x <= n and 1 <= y <= n

for t in range(0, m):
    distance = 2 ** t
    new_bombs = set()
    for x, y in bombs:
        for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nx, ny = x + dx * distance, y + dy * distance
            if in_range(nx, ny):
                new_bombs.add((nx, ny))
                visited.add((nx, ny))
    bombs.update(new_bombs)

print(len(visited))
