n = int(input())

selected = []
result = 0

def print_output():
    print(*selected)

# 숫자를 센다.
# cnt는 num보다 클 수가 없다.
# 만약 같은 수가 안나왔는데, cnt != num 이면 False
# 같은 수가 안나왔을때 cnt == num 이면 PASS
def is_beautiful_num():
    i = 0
    n = len(selected)
    
    while i < n:
        curr = selected[i]
        count = 0

        # 항상 curr만큼 읽어야 함
        for _ in range(curr):
            if i >= n or selected[i] != curr:
                return False
            i += 1

    return True


def find_beautiful_num(cnt):
    if cnt == n:
        if is_beautiful_num():
            global result
            result += 1
            return 
    else:
        for i in range(1, n + 1):
            selected.append(i)
            find_beautiful_num(cnt + 1)
            selected.pop(-1)

find_beautiful_num(0)
print(result)