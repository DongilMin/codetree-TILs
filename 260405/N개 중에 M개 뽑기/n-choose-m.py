n, m = map(int, input().split())
seleted = []

def print_ans():
    for num in seleted:
        print(num, end =' ')
    print()

def func(idx, cnt):
    if cnt == m:
        print_ans()
        return
    elif idx > n:
        return
    else:
        seleted.append(idx)
        func(idx + 1, cnt + 1)
        seleted.pop()
        func(idx + 1, cnt)

func(1, 0)