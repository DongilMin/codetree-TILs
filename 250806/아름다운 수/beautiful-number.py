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
    # 연달아 같은 숫자가 나오는 시작 위치를 잡습니다.
    i = 0
    while i < n:
        # 만약 연속하여 해당 숫자만큼 나올 수 없다면
        # 아름다운 수가 아닙니다.
        if i + selected[i] - 1 >= n:
            return False
        # 연속하여 해당 숫자만큼 같은 숫자가 있는지 확인합니다.
        # 하나라도 다른 숫자가 있다면
        # 아름다운 수가 아닙니다.
        for j in range(i, i + selected[i]):
            if selected[j] != selected[i]:
                return False
            
        i += selected[i]
        
    return True


def find_beautiful_num(cnt):
    if cnt == n:
        if is_beautiful_num():
            global result
            result += 1
            return 
    else:
        for i in range(1, 5):
            selected.append(i)
            find_beautiful_num(cnt + 1)
            selected.pop(-1)

find_beautiful_num(0)
print(result)