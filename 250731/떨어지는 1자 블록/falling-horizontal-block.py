n, m, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# 0-based 인덱스 통일
k -= 1

def in_range(x, y):
    return 0 <= x < n and 0 <= y < n

def can_place(row, col):
    for i in range(m):
        if not in_range(row, col + i) or grid[row][col + i] == 1:
            return False
    return True

def simulation():
    row = 0
    while row + 1 < n and can_place(row + 1, k):
        row += 1

    # 최종 위치 row에 블록 m칸 놓기
    for i in range(m):
        grid[row][k + i] = 1

simulation()

for row in grid:
    print(*row)
