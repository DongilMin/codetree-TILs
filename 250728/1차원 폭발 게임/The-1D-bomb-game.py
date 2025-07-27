n, m = tuple(map(int, input().split()))
bombs = [
    int(input())
    for _ in range(n)
    ]

def get_end_of_explosion(start_idx, curr_num):
    for end_idx in range(start_idx + 1, len(bombs)):
        if bombs[end_idx] != curr_num:
            return end_idx - 1
    return len(bombs) - 1

while True:
    did_exploed = False

    for curr_idx, bomb in enumerate(bombs):
        if bomb == 0:
            continue
        
        end_idx = get_end_of_explosion(curr_idx, bomb)
        if end_idx - curr_idx + 1 >= m :
            bombs[curr_idx : end_idx + 1] = [0] * (end_idx - curr_idx + 1)
            did_exploed = True

    bombs = list(filter(lambda x : x > 0, bombs))

    if not did_exploed:
        break

print(len(bombs))
for bomb in bombs:
    print(bomb)