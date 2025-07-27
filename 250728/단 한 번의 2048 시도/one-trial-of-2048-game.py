# Read 4x4 grid
grid = [list(map(int, input().split())) for _ in range(4)]

# Read direction ('L', 'R', 'U', 'D')
dir = input().strip()

def left_combine():
    global grid
    for i in range(4):
        new_row = [num for num in grid[i] if num != 0]
        j = 0
        while j < len(new_row) - 1:
            if new_row[j] == new_row[j + 1]:
                new_row[j] *= 2
                new_row.pop(j + 1)
                new_row.append(0)
            j += 1
        new_row = [num for num in new_row if num != 0]
        new_row += [0] * (4 - len(new_row))
        grid[i] = new_row

def reverse_rows():
    global grid
    for i in range(4):
        grid[i].reverse()

def transpose():
    global grid
    grid = [list(row) for row in zip(*grid)]

def move(dir):
    if dir == 'L':
        left_combine()
    elif dir == 'R':
        reverse_rows()
        left_combine()
        reverse_rows()
    elif dir == 'U':
        transpose()
        left_combine()
        transpose()
    elif dir == 'D':
        transpose()
        reverse_rows()
        left_combine()
        reverse_rows()
        transpose()

# Run the move
move(dir)

# Output
for row in grid:
    print(*row)
