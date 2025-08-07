import sys

INT_MIN = -sys.maxsize

expression = input()
length = 6
num = [0 for _ in range(length)]
ans = INT_MIN

def conv(idx):
    return num[ord(expression[idx]) - ord('a')]

def calc():
    l = len(expression)
    value = conv(0)
    for i in range(2, l, 2):
        if expression[i - 1] == '-':
            value -= conv(i)
        elif expression[i - 1] == '+':
            value += conv(i)
        else :
            value *= conv(i)
    return value

def find_max(cnt):
    global ans

    if cnt == length:
        ans = max(ans, calc())
        return
    else:
        for i in range(1, 5):
            num[cnt] = i
            find_max(cnt + 1)

find_max(0)
print(ans)