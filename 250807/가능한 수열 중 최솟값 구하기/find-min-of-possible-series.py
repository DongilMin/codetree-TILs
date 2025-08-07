import sys

n = int(input())
ans = "4"
selected = []
ans = []
nums = [4, 5, 6]

def is_impossible():
    L = len(selected)
    for i in range(L):
        for j in range(1, (L - i)//2 + 1): # j는 길이이다.
            if selected[i:i + j] == selected[i + j:i + 2*j]:
                return True
    return False

def backtracking(index):
    global ans
    if index == n:
        if not is_impossible():
            for c in selected:
                print(c, end="")
            sys.exit()
    else:
        for num in nums:
            selected.append(num)
            backtracking(index + 1)
            selected.pop()
        return

backtracking(0)
